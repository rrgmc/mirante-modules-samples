// Registers the module with the testing library, as the core would.
#include <mirante/ItemType.h>
#include <mirante/testing/TestRegistrar.h>

#include <QTest>

namespace mirante::modules::rrgmcextension {
void registerModule(mirante::ModuleRegistrar &registrar);
}

class TestRegister : public QObject
{
    Q_OBJECT

private slots:
    void registersTheCard()
    {
        mirante::testing::TestRegistrar registry;
        registry.registerModule(QStringLiteral("rrgmcextension"), &mirante::modules::rrgmcextension::registerModule);
        QVERIFY(registry.contains(QStringLiteral("rrgmcextension.card")));
        const mirante::ItemType &type = registry.type(QStringLiteral("rrgmcextension.card"));
        QCOMPARE(type.rendering(), mirante::Rendering::Native);
        QCOMPARE(type.fields().size(), size_t(2));
        QVERIFY(!type.icon().isNull());
    }
};

QTEST_MAIN(TestRegister)
#include "tst_register.moc"
