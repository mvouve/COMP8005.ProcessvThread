#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QObject>
#include <QTime>
#include <QLocalServer>
#include <QDir>
#include <QTextStream>
#include <QVector>
#include "blockingqueue.h"
#include "threadsafequeue.h"
#include "worker.h"

class Controller : public QObject
{
public:
    explicit Controller(QString dir, qint32 numOfChildern, QObject * parent);
    void run();

private:
    const QString RootDir;
    const qint32 requiredChildern;
    QTime stopWatch;
    const QLocalServer comm;
    BlockingQueue<QString> checksumQueue;
    ThreadSafeQueue<QString> fileQueue;
};

#endif // CONTROLLER_H
