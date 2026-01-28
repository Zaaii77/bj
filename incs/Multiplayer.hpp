#ifndef MULTIPLAYER_HPP
# define MULTIPLAYER_HPP

# include "BlackJack.hpp"
# include "Client.hpp"
# include <sys/socket.h>
# include <sys/select.h>
# include <vector>

class Multiplayer
{
    public:
        Multiplayer();
        ~Multiplayer();
        Multiplayer(const Multiplayer& other ) = delete;
        Multiplayer&    operator=(const Multiplayer& other) = delete;
    private:
        int                 socket;
        std::vector<Client> clients;
        const int           maxPlayer = 4;
};

#endif