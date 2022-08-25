SRC = main.cpp 
	
OBJ = $(SRC:.cpp=.o)

INC = includes

OBJ_DIR = objs

FT = ft_container

STD = std_container

CC = c++

RM = rm -rf

CFLAGS = -Wall -Wextra -std=c++98

NAME = main

all: $(FT) $(STD)

$(FT): $(SRC)
	mkdir -p objs
	$(CC) $(CFLAGS) -I$(INC) -D CT=ft -c $(SRC) -o $(OBJ_DIR)/$@.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(FT).o -o $@
$(STD): $(SRC)
	mkdir -p objs
	$(CC) $(CFLAGS) -I$(INC) -D CT=std -c $(SRC) -o $(OBJ_DIR)/$@.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(STD).o -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(FT) $(STD)

re: fclean all

.PHONY: all clean fclean re