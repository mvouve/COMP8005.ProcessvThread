#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QCryptographicHash>
#include "blockingqueue.h"
#include "threadsafequeue.h"

class Worker : public QThread
{
Q_OBJECT
public:
    explicit Worker(quint32 threadNo, quint32 totalThreads, quint64 maxPrime, QObject * parent = nullptr) : QThread(parent), threadNo_(threadNo), totalThreads_(totalThreads),
        maxPrime_(maxPrime) {}
    void run();
private:
    const qint32 totalThreads_;
    const qint32 threadNo_;
    const quint64 maxPrime_;

signals:
    void resultReady(const QString);
};

#endif // WORKER_H
