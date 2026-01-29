#include "../incs/Multiplayer.hpp"

Multiplayer::Multiplayer() : socketFd(-1)
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1)
        throw (std::runtime_error("Error with socket()"));
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(6697);
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(socketFd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
    {
        close(socketFd);
        throw (std::runtime_error("Error with bind()"));
    }
    if (listen(socketFd, maxPlayer) == -1)
    {
        close(socketFd);
        throw (std::runtime_error("Error with listen()"));
    }
}

Multiplayer::~Multiplayer()
{
    if (socketFd != -1)
        close(socketFd);
}
