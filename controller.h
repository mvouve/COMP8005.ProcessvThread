#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QTime>
#include <QVector>
#include "worker.h"
#include "pthreadworker.h"
#include "processworker.h"

enum class Concurrency {
    process,
    thread
};

class Controller
{
public:
    explicit Controller(Concurrency mode, quint64 maxPrime, qint32 numOfChildern) : mode_(mode), requiredChildern_(numOfChildern), maxPrime_(maxPrime) {}
    void run();

private:
    const Concurrency mode_;
    const qint32 requiredChildern_;
    const quint64 maxPrime_;
    QTime stopWatch_;
};

#endif // CONTROLLER_H
