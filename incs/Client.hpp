#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "Player.hpp"
# include <iostream>
# include <unistd.h>

class   Client : public Player
{
    public:
        Client();
        ~Client();
        Client(const Client& other) = delete;
        Client& operator=(const Client& other) = delete;

        int     getFd(void) const;
        void    setFd(int fd);
    private:
        int     fd;
};

#endif