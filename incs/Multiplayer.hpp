#ifndef MULTIPLAYER_HPP
# define MULTIPLAYER_HPP

# include "BlackJack.hpp"
# include <sys/socket.h>
# include <sys/select.h>

class Multiplayer
{
    public:
        Multiplayer();
        ~Multiplayer();
    private:
        int     socket;
        fd_set  fds;
        int     maxFd;
};

#endif