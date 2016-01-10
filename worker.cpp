#include "worker.h"
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QCryptographicHash>

void Worker::run()
{
    QString work;

    qDebug() << fileQueue->isEmpty();
    while(!fileQueue->isEmpty()) {
        work = fileQueue->dequeue();
        if(QFileInfo(work).isDir()) {
            QStringList dirListing = QDir(work).entryList(QDir::NoDotAndDotDot | QDir::AllEntries, QDir::DirsFirst);
            for(auto file = dirListing.begin(); file != dirListing.end(); ++file) {
                fileQueue->enqueue(work + "/" + *file);
            }
        } else {
            QByteArray hash = QCryptographicHash::hash(QFile(work).readAll(), QCryptographicHash::Sha3_512);
            QTextStream(stdout) << work << " " << hash << '\n';
        }
    }


}
