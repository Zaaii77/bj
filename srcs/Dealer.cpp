#include "../incs/Dealer.hpp"

void    Dealer::dealCard(Player& player)
{
    player.addCard(shoe.giveCard());
}

void    Dealer::checkShoe(void)
{
    if (shoe.size() < 52)
        shoe.resetShoe();
}

void    Dealer::pickCard(void)
{
    hand.push_back(shoe.giveCard());
}
