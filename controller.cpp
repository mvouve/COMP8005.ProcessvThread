#include "controller.h"
#include <unistd.h>

Controller::Controller(QString dir, qint32 numOfChildern, QObject * parent = 0) : RootDir(dir), requiredChildern(numOfChildern), QObject(parent)
{

}

//!#
//! This is the main function for the controlling thread. It takes care of all the set up for the child threads. and monitors when they return.
void Controller::run() {
    stopWatch.start();
    QVector<Worker *> workers;

    QStringList f = QDir(RootDir).entryList(QDir::NoDotAndDotDot | QDir::AllEntries);

    for(auto itr = f.begin(); itr != f.end(); ++itr) {
        fileQueue.enqueue(RootDir + *itr);
    }

    for(int i = 1; i <= requiredChildern; ++i) {
        workers.append(new Worker(i, requiredChildern, 100000000));
        if(!fork()){
            workers.last()->run();
            break;
        }
        //workers.last()->start();
    }


    // TODO: handle thread creation
    for(;;){}

    //TODO: check if all threads are returned and exit
    for(auto itr = workers.begin(); itr != workers.end(); itr++)
    {
        //delete itr;
    }
}
