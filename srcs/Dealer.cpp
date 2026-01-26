#include "../incs/Dealer.hpp"

void    Dealer::dealCard(Player& player)
{
    player.addCard(shoe.giveCard());
}

void    Dealer::checkShoe(void)
{
    handSum = 0;
    hand.clear();
    if (shoe.size() < 52)
        shoe.resetShoe();
}

void    Dealer::pickCard(void)
{
    hand.push_back(shoe.giveCard());
    handSum += hand.back().getValue();
}

void	Dealer::pickSecondCard(void)
{
	secondCard = shoe.giveCard();
}

const Card&	Dealer::getSecondCard(void)
{
	return (secondCard);
}

int     Dealer::getHandSum(void)
{
    return (handSum);
}

int     Dealer::getCardValue(int index)
{
    if (static_cast<size_t>(index) >= hand.size())
        throw (std::runtime_error("You try to access outside the dealer's hand"));
    return (hand[index].getValue());
}

size_t  Dealer::getDeckSize(void)
{
    return (hand.size());
}
