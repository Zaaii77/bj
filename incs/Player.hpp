#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Card.hpp"
# include <string>
# include <iostream>

class   Player
{
  public:
    Player() = default;
    Player(std::string playerName, unsigned int startMoney) : name(playerName), money(startMoney) {hand.clear();};
    ~Player() {};
    Player(const Player& other);
    Player& operator=(const Player& other);
    void            addCard(Card card);
    unsigned int    getMoney(void);
    void            addMoney(unsigned int gain);
    int             getCardValue(int index);
    int             getHandSum(void);
    void            clearHand(void);
  private:
    std::string         name;
    unsigned int        money;
    std::vector<Card>   hand;
    int                 handSum;
};

#endif