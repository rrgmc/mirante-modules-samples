// The page's address, and the files that the core serves for it. Loading the
// page needs Qt WebEngine and the core, so it is not tested here.
#include "../WebPages.h"

#include <QFile>
#include <QTest>
#include <QUrlQuery>

using mirante::modules::rrgmcwebpages::pageUrl;

class TestPages : public QObject
{
    Q_OBJECT

private slots:
    void addressHasTheTitle()
    {
        const QUrl url = pageUrl(QStringLiteral("Café & more?"));
        QCOMPARE(url.scheme(), QStringLiteral("module"));
        QCOMPARE(url.host(), QStringLiteral("rrgmcwebpages"));
        QCOMPARE(url.path(), QStringLiteral("/index.html"));
        QCOMPARE(QUrlQuery(url).queryItemValue(QStringLiteral("title"), QUrl::FullyDecoded),
                 QStringLiteral("Café & more?"));
    }

    // module://rrgmcwebpages/<path> is the resource below, so each file the
    // page uses must be compiled in.
    void filesAreCompiledIn_data()
    {
        QTest::addColumn<QString>("path");
        QTest::newRow("page") << "index.html";
        QTest::newRow("script") << "page.js";
        QTest::newRow("style") << "page.css";
        QTest::newRow("data") << "greetings.json";
    }

    void filesAreCompiledIn()
    {
        QFETCH(QString, path);
        QVERIFY(QFile::exists(QStringLiteral(":/modules/rrgmcwebpages/web/") + path));
    }
};

QTEST_APPLESS_MAIN(TestPages)
#include "tst_pages.moc"
