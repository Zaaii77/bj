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
	if (card.getType() == AS)
		hasAnAce = true;
	handSum += card.getValue();
}

void	Player::addMoney(float gain)
{
	money += gain;
}

float	Player::getMoney(void)
{
	return (money);
}

int	Player::getCardValue(size_t index)
{
	if (index >= hand.size())
		throw (std::runtime_error("You try to access outside the player's hand"));
	return (hand[index].getValue());
}

int	Player::getHandSum(void)
{
	if (hasAnAce && handSum + 10 <= 21)
		return (handSum + 10);
	return (handSum);
}

void	Player::clearHand(void)
{
	hasAnAce = false;
	hand.clear();
	handSum = 0;
}

size_t	Player::handSize(void)
{
	return (hand.size());
}

float	Player::getBet(void)
{
	return (bet);
}

bool	Player::setBet(float amount)
{
	if (money - amount >= 0.f)
	{
		bet = amount;
		money -= amount;
	}
	else
	{
		std::cout << "You're trying to spend more money than you have." << std::endl;
		return (false);
	}
	return (true);
}