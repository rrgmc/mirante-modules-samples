// The rrgmcextension sample: a card whose body comes from an extension point,
// so an app can replace it at build time. See README.md.
#include "CardBody.h"

#include <mirante/Fields.h>
#include <mirante/ItemContext.h>
#include <mirante/ItemType.h>
#include <mirante/Module.h>

#include <QCoreApplication>
#include <QFont>
#include <QIcon>
#include <QJsonObject>
#include <QLabel>
#include <QUrl>
#include <QUuid>
#include <QVBoxLayout>

#include <memory>
#include <vector>

namespace mirante::modules::rrgmcextension {

namespace {

class CardItemType : public ItemType
{
public:
    QString id() const override { return QStringLiteral("rrgmcextension.card"); }
    QString name() const override { return QCoreApplication::translate("rrgmcextension", "Sample card"); }
    QIcon icon() const override { return QIcon(QStringLiteral(":/modules/rrgmcextension/icons/card.svg")); }
    QString description() const override
    {
        return QCoreApplication::translate("rrgmcextension",
                                           "A card whose body an app can replace when it builds Mirante.");
    }

    std::vector<Field> fields() const override
    {
        Field title;
        title.key = QStringLiteral("title");
        title.label = QCoreApplication::translate("rrgmcextension", "Title");
        title.defaultValue = QCoreApplication::translate("rrgmcextension", "A sample card");
        Field text;
        text.key = QStringLiteral("text");
        text.label = QCoreApplication::translate("rrgmcextension", "Text");
        text.type = Field::Type::MultiLineText;
        text.defaultValue =
            QCoreApplication::translate("rrgmcextension", "The body below comes from an extension point.");
        return {title, text};
    }

    // The title is the module's own. The body comes from makeCardBody(),
    // which the default or the app's extension defines.
    QWidget *createView(ItemContext &context, QWidget *parent) const override
    {
        const QJsonObject config = context.config();
        const CardText card{config.value(QStringLiteral("title")).toString(),
                            config.value(QStringLiteral("text")).toString()};

        auto *view = new QWidget(parent);
        auto *layout = new QVBoxLayout(view);
        auto *title = new QLabel(card.title, view);
        QFont font = title->font();
        font.setBold(true);
        title->setFont(font);
        layout->addWidget(title);
        layout->addWidget(makeCardBody(card, view), 1);
        return view;
    }
};

} // namespace

void registerModule(ModuleRegistrar &registrar)
{
    registrar.setModuleName(QCoreApplication::translate("rrgmcextension", "Sample extension point"));
    registrar.setModuleDescription(QCoreApplication::translate(
        "rrgmcextension", "A sample of a module whose code an app can replace in part."));
    registrar.setModuleUuid(QUuid(QStringLiteral("4e1c7a92-6d3b-4f08-b5a1-8c2e9d7f3b64")));
    registrar.setModuleVersion(QStringLiteral("0.1.0"));
    registrar.setModuleAuthor(QStringLiteral("Rangel Reale"));
    registrar.setModuleHomepage(
        QUrl(QStringLiteral("https://github.com/rrgmc/mirante-modules-samples/tree/master/rrgmcextension")));
    registrar.addItemType(std::make_unique<CardItemType>());
}

} // namespace mirante::modules::rrgmcextension
