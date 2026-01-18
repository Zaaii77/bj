#ifndef CARD_HPP
# define CARD_HPP

# include <vector>
# include <stdexcept>

enum	Type {
	AS = 0,
	TWO = 1,
	THREE = 2,
	FOUR = 3,
	FIVE = 4,
	SIX = 5,
	SEVEN = 6,
	EIGHT = 7,
	NINE = 8,
	TEN = 9,
	JACK = 10,
	QUEEN = 11,
	KING = 12
};

class   Card
{
    public:
        Card(int val);
        ~Card() {};
        Card() {};
        Card(const Card& other);
        Card&   operator=(const Card& other);
        Card(Card&& other) = default;
        Card&   operator=(Card&& other) = default;
        const Type& getType(void) const;
    private:
        Type type;
};

#endif