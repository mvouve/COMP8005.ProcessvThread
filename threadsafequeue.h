#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <QMutex>
#include <QQueue>

template<class T>
class ThreadSafeQueue : public QQueue<T>
{
public:
    ThreadSafeQueue() {}
    T dequeue();
    bool isEmpty();
    void enqueue(const T &t);

private:
    QMutex access;
};

template<class T>
T ThreadSafeQueue<T>::dequeue()
{
    access.lock();
    const T &t = QQueue<T>::dequeue();
    access.unlock();

    return t;
}

template<class T>
void ThreadSafeQueue<T>::enqueue(const T &t)
{
    access.lock();
    QQueue<T>::enqueue(t);
    access.unlock();
}

template<class T>
bool ThreadSafeQueue<T>::isEmpty()
{
    access.lock();
    bool empty = QQueue<T>::isEmpty();
    access.unlock();

    return empty;
}

#endif // THREADSAFEQUEUE_H
