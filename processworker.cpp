#include "processworker.h"
#include <unistd.h>
#include <sys/wait.h>

//!
//! \date January 10, 2016
//! \author Marc Vouve
//! \brief ProcessWorker::start
//! \return
//!
int ProcessWorker::start()
{
    switch(int pid = fork()) {
    case 0:
        run();
        break;
    case -1:
        break;
    default:
        childId_ = pid;
        return pid;
    }

    exit(0);
}

//!
//! \brief ProcessWorker::wait waits for child process to exit
//! \date Janurary 10, 2016
//! \author Marc Vouve
//! \designer Marc Vouve
//! \revision January 16, 2016: on some machines childId_ was not working, changed to -1
//!
void ProcessWorker::wait() {
    waitpid(-1, NULL, 0);
}
