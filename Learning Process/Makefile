SRC = main.cpp 
	
OBJ = $(SRC:.cpp=.o)

FT = ft_container

STD = std_container

CC = c++

RM = rm -f

CFLAGS = -Wall -Wextra -std=c++98

NAME = main

%.o : %.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all: $(FT) $(STD)

$(FT):
	$(CC) $(CFLAGS) -D CT=-c 

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re