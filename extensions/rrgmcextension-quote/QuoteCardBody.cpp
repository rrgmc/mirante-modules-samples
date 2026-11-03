// An extension of rrgmcextension's extension point "body": the card's text as
// a quote, beside an icon. It includes the module's interface by name, and its
// icon comes from its own resources.txt, served as
// :/modules/rrgmcextension/quote.svg. See ../README.md.
#include "CardBody.h"

#include <QFont>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>

namespace mirante::modules::rrgmcextension {

QWidget *makeCardBody(const CardText &card, QWidget *parent)
{
    auto *body = new QWidget(parent);
    body->setObjectName(QStringLiteral("cardBody"));
    auto *layout = new QHBoxLayout(body);
    layout->setContentsMargins(0, 0, 0, 0);

    auto *icon = new QLabel(body);
    icon->setPixmap(QIcon(QStringLiteral(":/modules/rrgmcextension/quote.svg")).pixmap(24, 24));
    icon->setAlignment(Qt::AlignTop);
    layout->addWidget(icon);

    auto *text = new QLabel(card.text, body);
    QFont font = text->font();
    font.setItalic(true);
    text->setFont(font);
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    layout->addWidget(text, 1);
    return body;
}

} // namespace mirante::modules::rrgmcextension
