#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include "blockingqueue.h"
#include "threadsafequeue.h"

class Worker : public QThread
{
Q_OBJECT
public:
    explicit Worker(BlockingQueue<QString> * checksums, ThreadSafeQueue<QString> * files, QObject * parent = 0) : QThread(parent), fileQueue(files), checksumQueue(checksums) {}
    void run();
private:
    QStringList work;
    ThreadSafeQueue<QString> * fileQueue;
    BlockingQueue<QString> * checksumQueue;
signals:
    void resultReady(const QString);
};

#endif // WORKER_H
