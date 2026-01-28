#include "../incs/Multiplayer.hpp"

Multiplayer::Multiplayer() : socket(-1), maxFd(0)
{
    FD_ZERO(&fds);
}

Multiplayer::~Multiplayer()
{}