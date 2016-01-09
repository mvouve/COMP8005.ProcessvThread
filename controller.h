#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QObject>
#include <QTime>
#include <QLocalServer>

class Controller : public QObject
{
public:
    Controller(QString);

private:
    const QString RootDir;
    const qint32 requiredChildern;
    const QTime stopWatch;
    const QLocalServer socket;
};

#endif // CONTROLLER_H
