#include "utility.h"


QList<QString> getDirectoryListing(QString dir) {
    QDir(dir).entryList();
}
