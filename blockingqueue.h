#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <QQueue>
#include <QSemaphore>

template<class T>
class BlockingQueue : public QQueue<T>
{
public:
    BlockingQueue() : sem(0) {}
    T dequeue();
    void enqueue(const T &t);
private:
    QSemaphore sem;
};

template<class T>
T BlockingQueue<T>::dequeue()
{
    sem.acquire();

    return QQueue<T>::dequeue();
}

template<class T>
void BlockingQueue<T>::enqueue(const T &t)
{
    QQueue<T>::enqueue(t);
    sem.release();
}

#endif // BLOCKINGQUEUE_H
