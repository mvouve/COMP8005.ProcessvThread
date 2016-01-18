#include "controller.h"
#include <unistd.h>
#include <QFile>

//!
//! \author Marc Vouve
//! \designer Marc Vouve
//! \date Janurary 9, 2015
//!
//! \brief Controller::run this is the main function in the controller class
//! creates childern and waits for them to finish. on completion prints the total elapsed time.
//!
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
