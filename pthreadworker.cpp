#include "pthreadworker.h"

//!
//! \brief PThreadWorker::~PThreadWorker
//!
PThreadWorker::~PThreadWorker()
{
    pthread_exit(&thread);
}

//!
//! \brief PThreadWorker::start
//! \return a pthread_create error value
//!
int PThreadWorker::start()
{
    if(int rc = pthread_create(&thread, NULL, PThreadWorker::begin, (void *) this)) {
        qDebug() << "Thread Failed to be created!" << '\n';

        return rc;
    }

    return 0x0;
}

//!
//! \brief PThreadWorker::begin This function acts as a helper for starting a thread internal to the object.
//!             the Pthread api expects a function pointer so using begin as the function and this (keyword)
//!             as a parameter is a simple way of creating a thread
//! \author Marc Vouve
//! \designer Marc Vouve
//! \param worker should be passed this from internal to the object
//! \return void
//!
void *PThreadWorker::begin(void * worker) {
    ((PThreadWorker *)worker)->run();
}

//!
//! \brief PThreadWorker::wait
//!
void PThreadWorker::wait() {
    pthread_join(thread, NULL);
}
