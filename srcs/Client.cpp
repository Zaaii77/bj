#include "../incs/Client.hpp"

Client::Client() : Player(), fd(-1)
{}

Client::~Client()
{
    if (fd != -1)
        close(fd);
}

int   Client::getFd(void) const
{
    return (fd);
}

void    Client::setFd(int fd)
{
    if (this->fd == -1)
        this->fd = fd;
}