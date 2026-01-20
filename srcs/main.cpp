#include "../incs/BlackJack.hpp"

int main(void)
{
    srand(time(0));
    BlackJack   bj;

    bj.dealCardToPlayer(bj.getPlayer());
    return (0);
}
