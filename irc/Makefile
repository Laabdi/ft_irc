NAME = ircserv

CXX = c++

CXXFLAGS = -std=c++98 -I./Includes #-Wextra -Wall -Werror 

SRC = $(wildcard Client/Commands/*.cpp)

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
