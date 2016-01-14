#include "processworker.h"
#include <unistd.h>
#include <sys/wait.h>

int ProcessWorker::start()
{
    switch(int pid = fork()) {
    case 0:
        run();
        break;
    case -1:
        break;
    default:
        childId = pid;
        return pid;
    }

    exit(0);
}

void ProcessWorker::wait() {
    waitpid(childId, NULL, 0);
}
