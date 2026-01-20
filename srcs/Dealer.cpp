#include "../incs/Dealer.hpp"

void    Dealer::dealCard(Player& player)
{
    player.addCard(shoe.giveCard());
}
