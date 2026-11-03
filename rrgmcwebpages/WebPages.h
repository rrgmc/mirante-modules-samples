#pragma once

#include <QString>
#include <QUrl>

namespace mirante::modules::rrgmcwebpages {

// The address of the sample page for an item with this title.
QUrl pageUrl(const QString &title);

} // namespace mirante::modules::rrgmcwebpages
