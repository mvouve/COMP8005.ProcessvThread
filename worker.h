#ifndef WORKER_H
#define WORKER_H

#include <QFile>
#include <QTextStream>
#include <cmath>
#include <QTime>

class Worker
{
public:
    explicit Worker(QFile * out, quint32 threadNo, quint32 totalThreads, quint64 maxPrime) : out_(out), totalThreads_(totalThreads), threadNo_(threadNo),
        maxPrime_(maxPrime) {}
    void run();
    virtual int start() = 0;
    virtual void wait() = 0;
private:
    QFile  * out_;
    const qint32 totalThreads_;
    const qint32 threadNo_;
    const quint64 maxPrime_;
};

#endif // WORKER_H
