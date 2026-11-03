// Registers the module with the testing library, as the core would.
#include <mirante/ItemType.h>
#include <mirante/testing/TestRegistrar.h>

#include <QTest>

namespace mirante::modules::rrgmcwebpages {
void registerModule(mirante::ModuleRegistrar &registrar);
}

class TestRegister : public QObject
{
    Q_OBJECT

private slots:
    void registersThePage()
    {
        mirante::testing::TestRegistrar registry;
        registry.registerModule(QStringLiteral("rrgmcwebpages"), &mirante::modules::rrgmcwebpages::registerModule);
        QVERIFY(registry.contains(QStringLiteral("rrgmcwebpages.page")));
        const mirante::ItemType &type = registry.type(QStringLiteral("rrgmcwebpages.page"));
        QCOMPARE(type.rendering(), mirante::Rendering::Web);
        QCOMPARE(type.fields().size(), size_t(1));
        QVERIFY(!type.icon().isNull());
    }
};

QTEST_MAIN(TestRegister)
#include "tst_register.moc"
