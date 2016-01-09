#include "controller.h"

Controller::Controller(QString dir, qint32 numOfChildern, QObject * parent = nullptr) : RootDir(dir), requiredChildern(numOfChildern), QObject(parent)
{
    stopWatch.start();
}

void run() {
    getDirectoryListing(rootDir);

    for(int i = 0; i < requiredChidlern; ++i) {
        QProcess()
    }

}
