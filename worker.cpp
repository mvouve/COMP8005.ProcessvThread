#include "worker.h"
#include <cmath>
#include <unistd.h>
#include <QDebug>

void Worker::run()
{
    bool notPrime;
    QTextStream out(out_);

    //qDebug() << threadNo_;

    for(quint64 i = (quint64) threadNo_; i < maxPrime_; i += totalThreads_)
    {
        quint64 square = ceil(sqrt(i));
        notPrime = false;
        if(i < 2) {
            continue;
        }
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
            //qDebug() << i;
            out << i << "\n";
        }
    }



}


