# BlackJack

A terminal-based BlackJack game implementation in C++.

## Description

This is a classic BlackJack (21) card game that you can play directly in your terminal. The game features a dealer, a 6-deck shoe, and standard BlackJack rules. Players start with $500 and can place bets on each round.

## Features

- Standard BlackJack gameplay
- 6-deck shoe
- Betting system with starting money of $500
- Player actions: Hit, Stand
- Dealer follows standard house rules
- Win/Loss/Draw outcomes

## Requirements

- C++ compiler (c++)
- Make

## Installation

Clone the repository and compile the project:

```bash
make
```

This will create an executable named `bj`.

## Usage

Run the game:

```bash
./bj
```

Follow the on-screen prompts to:
1. Place your bet
2. Choose to Hit or Stand
3. Watch the dealer's turn
4. See the results and your winnings/losses

## Game Rules

- Each round starts with placing a bet
- Both player and dealer receive two cards
- Player acts first and can choose to Hit (draw another card) or Stand (keep current hand)
- Dealer must hit on 16 and below, stand on 17 and above
- Blackjack (21) pays out
- Going over 21 results in a bust (automatic loss)

## Project Structure

```
bj/
├── Makefile
├── incs/
│   ├── BlackJack.hpp
│   ├── Card.hpp
│   ├── Dealer.hpp
│   ├── Player.hpp
│   └── Shoe.hpp
└── srcs/
    ├── BlackJack.cpp
    ├── Card.cpp
    ├── Dealer.cpp
    ├── main.cpp
    ├── Player.cpp
    └── Shoe.cpp
```

## Compilation Options

- `make` or `make all` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile the entire project

## License

This is a personal project.
