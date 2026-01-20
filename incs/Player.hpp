#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Card.hpp"
# include <string>

class   Player
{
    public:
		Player() = default;
        Player(std::string playerName, unsigned int startMoney) : name(playerName), money(startMoney) {hand.clear();};
        ~Player() {};
        Player(const Player& other) = delete;
        Player& operator=(const Player& other);
    private:
		std::string         name;
        unsigned int        money;
        std::vector<Card>   hand;
};

#endif