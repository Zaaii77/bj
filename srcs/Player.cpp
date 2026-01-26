#include "../incs/Player.hpp"

Player::Player(const Player& other)
{
	*this = other;
}

Player&	Player::operator=(const Player& other)
{
	if (this != &other)
	{
		hand = other.hand;
		money = other.money;
		name = other.name;
	}
	return (*this);
}

void	Player::addCard(Card card)
{
	hand.push_back(card);
	handSum += card.getValue();
}

void	Player::addMoney(unsigned int gain)
{
	money += gain;
}

unsigned int	Player::getMoney(void)
{
	return (money);
}

int	Player::getCardValue(int index)
{
	if (static_cast<size_t>(index) >= hand.size())
		throw (std::runtime_error("You try to access outside the player's hand"));
	return (hand[index].getValue());
}

int	Player::getHandSum(void)
{
	return (handSum);
}

void	Player::clearHand(void)
{
	hand.clear();
	handSum = 0;
}

size_t	Player::handSize(void)
{
	return (hand.size());
}

int	Player::getBet(void)
{
	return (bet);
}

bool	Player::setBet(int amount)
{
	if (money - amount >= 0)
		bet = amount;
	else
	{
		std::cout << "You try to spend more money than you have..." << std::endl;
		return (false);
	}
	return (true);
}