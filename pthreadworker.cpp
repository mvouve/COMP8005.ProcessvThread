#include "pthreadworker.h"

PThreadWorker::~PThreadWorker()
{
    pthread_exit(&thread);
}

int PThreadWorker::start()
{
    if(int rc = pthread_create(&thread, NULL, PThreadWorker::begin, (void *) this)) {
        qDebug() << "Thread Failed to be created!" << '\n';

        return rc;
    }

    return 0x0;
}

void *PThreadWorker::begin(void * worker) {
    ((PThreadWorker *)worker)->run();
    //pthread_exit(((PThreadWorker *)worker)->thread);
}

void PThreadWorker::wait() {
    pthread_join(thread, NULL);
}
