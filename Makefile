NAME = bj

INC_DIR = ./incs
INC = -I$(INC_DIR)

SRC_DIR = srcs
OBJ_DIR = obj

SRC =	$(SRC_DIR)/main.cpp $(SRC_DIR)/Card.cpp $(SRC_DIR)/Shoe.cpp \
		$(SRC_DIR)/BlackJack.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/Dealer.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPP = c++
CFLAGS = -Wall -Wextra -Werror -g
RM = @rm -rf
AR = ar -rcs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) has been compiled."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(RM) $(OBJ_DIR)
	@echo "obj/ dir and .o files deleted."

fclean: clean
	$(RM) $(NAME)
	$(RM) .shell_history
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re