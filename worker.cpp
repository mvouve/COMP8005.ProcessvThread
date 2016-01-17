#include "worker.h"
#include <cmath>
#include <unistd.h>
#include <QDebug>
#include <QTime>

void Worker::run()
{
    bool notPrime;
    QTextStream out(out_);
    QTime t;

    t.start();

    //qDebug() << threadNo_;
    quint64 i;
    for(i = threadNo_ + 1; i < maxPrime_; i += totalThreads_)
    {
        // if i == totalThreads_, its the first itteration, will never be prime
        if(i == totalThreads_)
        {
            i = 1;
        }
        quint64 square = ceil(sqrt(i));
        notPrime = false;

        for(quint64 n = 2; n <= square; n++)
        {
            if((i % n) == 0)
            {
                notPrime = true;
                break;
            }
        }
        if(!notPrime)
        {
            out << i << "\n";
        }
    }

    qDebug() <<"Worker :" << threadNo_ << " completed after: " << t.elapsed() << "ms\n";


}


