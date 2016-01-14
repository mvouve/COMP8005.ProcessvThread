#include "controller.h"
#include <unistd.h>
#include <QFile>

//!#
//! This is the main function for the controlling thread. It takes care of all the set up for the child threads. and monitors when they return.
void Controller::run() {
    stopWatch_.start();
    QVector<Worker *> workers;

    QFile fd("text.txt");
    fd.open(QFile::WriteOnly | QFile::Truncate);

    for(int i = 1; i <= requiredChildern_; ++i) {
        if(mode_ == Concurrency::thread)
            workers.append(new PThreadWorker(&fd, i, requiredChildern_, maxPrime_));
        else
            workers.append(new ProcessWorker(&fd, i, requiredChildern_, maxPrime_));

        workers.last()->start();
    }

    for(auto w = workers.begin(); w != workers.end(); ++w) {
        (*w)->wait();
        delete *w;
    }

    qDebug() << "Time Elapsed: " << stopWatch_.elapsed() << "ms\n";
    fd.close();



}
