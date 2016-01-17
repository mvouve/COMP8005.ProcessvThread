#ifndef PARENTPROCESSCHANNEL_H
#define PARENTPROCESSCHANNEL_H


#include "processchannel.h"
#include <sys/epoll.h>

class ParentProcessChannel : ProcessChannel
{
public:
    ParentProcessChannel();
};

#endif // PARENTPROCESSCHANNEL_H
