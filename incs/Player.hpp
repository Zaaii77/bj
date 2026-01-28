#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Card.hpp"
# include <string>
# include <iostream>

class   Player
{
    public:
        Player() = default;
        Player(std::string playerName, unsigned int startMoney) : name(playerName), money(startMoney), handSum(0), hasAnAce(false) {hand.clear();};
        ~Player() {};
        Player(const Player& other);
        Player& operator=(const Player& other);
        void                addCard(Card card);
        float               getMoney(void);
        void                addMoney(float gain);
        int                 getCardValue(size_t index);
        int                 getHandSum(void);
        void                clearHand(void);
        size_t              handSize(void);
        float               getBet(void);
        bool                setBet(float amount);
        void                setName(const std::string& n);
        const std::string&  getName(void) const;
    private:
        std::string         name;
        float               money;
        std::vector<Card>   hand;
        int                 handSum;
        unsigned int        bet;
        bool                hasAnAce;
};

#endif