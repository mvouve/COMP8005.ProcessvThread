#ifndef PTHREADWORKER_H
#define PTHREADWORKER_H

#include "worker.h"
#include <pthread.h>
#include <QDebug>

class PThreadWorker : public Worker
{
public:
    using Worker::Worker;
    ~PThreadWorker();
    int start();
    void wait();
private:
    pthread_t thread;
    static void *begin(void *);
};

#endif // PTHREADWORKER_H
