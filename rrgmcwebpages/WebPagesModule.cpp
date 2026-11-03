// The rrgmcwebpages sample: an item that shows a web page shipped inside the
// module, with no HTTP server. See README.md.
#include "WebPages.h"

#include <mirante/Fields.h>
#include <mirante/ItemContext.h>
#include <mirante/ItemType.h>
#include <mirante/Module.h>

#include <QCoreApplication>
#include <QIcon>
#include <QUrl>
#include <QUrlQuery>
#include <QUuid>

#include <memory>
#include <vector>

namespace mirante::modules::rrgmcwebpages {

// The address of the page, with the item's title in its query, which the
// page's script reads. The core serves module://rrgmcwebpages/<path> from
// the resource :/modules/rrgmcwebpages/web/<path>.
QUrl pageUrl(const QString &title)
{
    QUrl url(QStringLiteral("module://rrgmcwebpages/index.html"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("title"), title);
    url.setQuery(query);
    return url;
}

namespace {

class PageItemType : public ItemType
{
public:
    QString id() const override { return QStringLiteral("rrgmcwebpages.page"); }
    QString name() const override { return QCoreApplication::translate("rrgmcwebpages", "Sample page"); }
    QIcon icon() const override { return QIcon(QStringLiteral(":/modules/rrgmcwebpages/icons/webpages.svg")); }
    QString description() const override
    {
        return QCoreApplication::translate("rrgmcwebpages",
                                           "A web page that comes with the module, served without a server.");
    }

    std::vector<Field> fields() const override
    {
        Field title;
        title.key = QStringLiteral("title");
        title.label = QCoreApplication::translate("rrgmcwebpages", "Title");
        title.defaultValue = QCoreApplication::translate("rrgmcwebpages", "Hello from a module page");
        title.help = QCoreApplication::translate("rrgmcwebpages", "Shown at the top of the page.");
        return {title};
    }

    // A web view, so the cell header shows the page's toolbar.
    Rendering rendering() const override { return Rendering::Web; }

    QWidget *createView(ItemContext &context, QWidget *parent) const override
    {
        return context.createWebView(pageUrl(context.config().value(QStringLiteral("title")).toString()), parent);
    }
};

} // namespace

void registerModule(ModuleRegistrar &registrar)
{
    registrar.setModuleName(QCoreApplication::translate("rrgmcwebpages", "Sample web pages"));
    registrar.setModuleDescription(QCoreApplication::translate(
        "rrgmcwebpages", "A sample of a module that ships its own web pages."));
    registrar.setModuleUuid(QUuid(QStringLiteral("9d3f6a2e-5b1c-4e8a-a7d4-2c6f0b9e1a53")));
    registrar.setModuleVersion(QStringLiteral("0.1.0"));
    registrar.setModuleAuthor(QStringLiteral("Rangel Reale"));
    registrar.setModuleHomepage(
        QUrl(QStringLiteral("https://github.com/rrgmc/mirante-modules-samples/tree/master/rrgmcwebpages")));
    registrar.addItemType(std::make_unique<PageItemType>());
}

} // namespace mirante::modules::rrgmcwebpages
