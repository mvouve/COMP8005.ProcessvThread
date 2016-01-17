#include "parentprocesschannel.h"

void ParentProcessChannel::connect()
{
    struct sockaddr_un remote;

    if((sock_ = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        qDebug() << "ParentProcessChannel::connect() ERROR\n";
        return;
    }

    remote.sun_family = AF_UNIX;
    strcpy(remote.sunPath, NAME);

    int len = strlen(remote.sun_path) + sizeof(remote.sun_family);

    if(connect(sock_, (struct sockaddr *)&remote, len) == -1) {
        qDebug() << "ParentProcessChannel::connect() ERROR\n";
        return;
    }
}

int ParentProcessChannel::read()
{
    int epollFd;
    struct epoll_event ev, *events;

    ev.events = EPOLLIN | EPOLLET;

    epollFd = epollcreate1(0);
    epoll_ctl(epollFd, EPOLL_CTL_ADD, sock_, &ev);

    for(;;) {
        nfds = epoll_wait(epollFd, events, maxevents, -1);
        for(n = 0; n < nfds; ++n) {
            if(events[n].data.fd == sock_) {
                int client = accept(sock_, (struct sockaddr *) &local, &addrlen);

                setnonblocking(client);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = client;
                epoll_ctl(epollFd, EPOLL_CTL_ADD, client, &ev);
            } else {
                read()
            }
        }
    }
}
