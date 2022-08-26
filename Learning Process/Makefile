SRC = v_erase_test.cpp main.cpp

EXE = $(SRC:.cpp=)

DXE = exe

INC = includes

OBJ_DIR = objs

FT = ft_

STD = std_

CC = c++

RM = rm -rf

CFLAGS = -Wall -Wextra -std=c++98

NAME = main

all: $(FT) $(STD)

$(FT): $(SRC)
	mkdir -p objs exe
	for d in $(EXE); do \
        $(CC) $(CFLAGS) -I$(INC) -D CT=ft -c $$d.cpp -o $(OBJ_DIR)/$(@)$$d.o; \
		$(CC) $(CFLAGS) $(OBJ_DIR)/$(FT)$$d.o -o $(DXE)/$(@)$$d; \
    done
	
$(STD): $(SRC)
	mkdir -p objs exe
	for d in $(EXE); do \
		$(CC) $(CFLAGS) -I$(INC) -D CT=std -c $$d.cpp -o $(OBJ_DIR)/$@$$d.o; \
		$(CC) $(CFLAGS) $(OBJ_DIR)/$(STD)$$d.o -o $(DXE)/$(@)$$d; \
	done
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(DXE)

re: fclean all

.PHONY: all clean fclean re