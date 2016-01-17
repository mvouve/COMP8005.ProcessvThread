#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>

enum class ChannelType {
    Parent,
    Child
};

class Channel
{
public:
    virtual int read(QString *) = 0;
    virtual int write(QString *) = 0;
    virtual int connect() = 0;
};

#endif // CHANNEL_H
