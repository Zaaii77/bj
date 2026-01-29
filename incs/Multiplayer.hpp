#ifndef MULTIPLAYER_HPP
# define MULTIPLAYER_HPP

# include "BlackJack.hpp"
# include "Client.hpp"
# include <sys/socket.h>
# include <sys/select.h>
# include <vector>
# include <netinet/in.h>
# include <string.h>

class Multiplayer
{
    public:
        Multiplayer();
        ~Multiplayer();
        Multiplayer(const Multiplayer& other ) = delete;
        Multiplayer&    operator=(const Multiplayer& other) = delete;
    private:
        int                 socketFd;
        std::vector<Client> clients;
        const int           maxPlayer = 4;
        struct sockaddr_in  sockaddr;
};

#endif