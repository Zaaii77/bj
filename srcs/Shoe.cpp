#include "../incs/BlackJack.hpp"
#include <algorithm>
#include <random>

Shoe::Shoe()
{
	resetShoe();
}

void	Shoe::resetShoe(void)
{
	this->cards.clear();
	this->cards.reserve(static_cast<std::size_t>(DECK_NUMBER * 52));

	for (int j = 0; j < DECK_NUMBER; j++)
		for (int h = 0; h < 4; h++)
			for (int i = 0; i < 13; i++)
				this->cards.push_back(Card(i));

	std::random_device rd;
	std::mt19937 s(rd());
	std::shuffle(this->cards.begin(), this->cards.end(), s);
}

Card	Shoe::giveCard(void)
{
	if (this->cards.empty())
		throw std::out_of_range("Shoe::giveCard() called on empty shoe");

	int randomDraw = rand() % static_cast<int>(this->cards.size());
	Card drawed = std::move(this->cards[randomDraw]);
	this->cards.erase(this->cards.begin() + randomDraw);
	return (drawed);
}

int	Shoe::size(void)
{
	return static_cast<int>(cards.size());
}
