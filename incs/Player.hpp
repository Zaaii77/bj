#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Card.hpp"
# include <string>

class   Player
{
    public:
        Player(std::string playerName, unsigned int startMoney) : name(playerName), money(startMoney) {hand.clear();};
        ~Player() {};
        Player(const Player& other) = delete;
        Player& operator=(const Player& other) = delete;
    private:
        std::vector<Card>   hand;
        unsigned int        money;
        std::string         name;
};

#endif