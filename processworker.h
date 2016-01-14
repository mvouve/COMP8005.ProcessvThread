#ifndef PROCESSWORKER_H
#define PROCESSWORKER_H

#include <sys/wait.h>
#include "worker.h"

class ProcessWorker : public Worker
{
public:
    using Worker::Worker;
    int start();
    void wait();
private:
    pid_t childId_;
};

#endif // PROCESSWORKER_H
