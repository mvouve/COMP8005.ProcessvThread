#include "worker.h"

//!
//! \author Marc Vouve
//! \designer Marc Vouve
//! \date January 8, 2015
//! \revision January 15, balenced work out better.
//! \brief Worker::run the main algorithm used by worker classes.
//!                     both worker classes use the exact same code in execution.
//!                     this version of run calculates prime numbers based off it's
//!                     members threadNo_, the maxPrime_ and totalThreads_.
//!
void Worker::run()
{
    bool notPrime;
    QTextStream out(out_);
    QTime t;

    t.start();
    // assign i as 1 above 0
    for(quint64 i = threadNo_ + 1; i < maxPrime_; i += totalThreads_)
    {

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

        // if i == totalThreads_ in its the first itteration, i will never be prime again
        // as it will always be divisible by the number of iterations. this will result in
        // repitition of some numbers but that's okay for this usecase.
        if(i == totalThreads_)
            i++;
    }
    qDebug() <<"Worker :" << threadNo_ << " completed after: " << t.elapsed() << "ms\n";
}


