#pragma once

#include <QString>

class QWidget;

// The interface of the extension point "body": what a card shows below its
// title. DefaultCardBody.cpp implements it, and so does any extension that an
// app names for "body" in its manifest. See README.md.
namespace mirante::modules::rrgmcextension {

// What the card shows, from the item's configuration.
struct CardText
{
    QString title;
    QString text;
};

// Makes the card's body, a child of parent. The widget's object name must be
// "cardBody", which the module's tests look for.
QWidget *makeCardBody(const CardText &card, QWidget *parent);

} // namespace mirante::modules::rrgmcextension
