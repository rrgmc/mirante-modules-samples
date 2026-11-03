// The card's body, from whichever implementation the build compiled in: the
// default, or the app's extension. Both keep the interface of CardBody.h.
#include "../CardBody.h"

#include <QTest>
#include <QWidget>

#include <memory>

using namespace mirante::modules::rrgmcextension;

class TestBody : public QObject
{
    Q_OBJECT

private slots:
    void makesTheBody()
    {
        QWidget parent;
        QWidget *body = makeCardBody(CardText{QStringLiteral("Title"), QStringLiteral("Some text")}, &parent);
        QVERIFY(body);
        QCOMPARE(body->parent(), &parent);
        QCOMPARE(body->objectName(), QStringLiteral("cardBody"));
    }
};

QTEST_MAIN(TestBody)
#include "tst_body.moc"
