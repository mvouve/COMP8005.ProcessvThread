#ifndef PROCESSCHANNEL_H
#define PROCESSCHANNEL_H

#include <QString>

enum class ProcessType {
    Child,
    Parent
};

class ProcessChannel
{
public:
    ProcessChannel();
private:
    ProcessType type_;
protected:
    const QString NAME = "prime_socket";
    int sock_;
};

#endif // PROCESSCHANNEL_H
