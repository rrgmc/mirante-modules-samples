// The default of the extension point "body": the card's text, as a label. It
// is compiled only when the app names no extension for "body".
#include "CardBody.h"

#include <QLabel>

namespace mirante::modules::rrgmcextension {

QWidget *makeCardBody(const CardText &card, QWidget *parent)
{
    auto *label = new QLabel(card.text, parent);
    label->setObjectName(QStringLiteral("cardBody"));
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    return label;
}

} // namespace mirante::modules::rrgmcextension
