SRC = v_erase_test.cpp main.cpp v_popback_test.cpp \
		v_insert_test.cpp v_swap_test.cpp v_empty_test.cpp \
		v_construct_test.cpp v_pushback_test.cpp v_relation_test.cpp \
		v_nonswap_test.cpp v_bracket_test.cpp v_assignment_test.cpp \
		v_rbegin_test.cpp v_rend_test.cpp v_reserve_test.cpp \
		v_resize_test.cpp v_size_test.cpp v_at_test.cpp

SRC_DIR = tests/

EXE = $(SRC:.cpp=)

DXE1 = exe_ft

DXE2 = exe_std

INC = includes

OBJ_DIR = objs

FT = ft_

STD = std_

CC = c++

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(FT) $(STD)

$(FT): 
	mkdir -p objs exe_ft
	for d in $(EXE); do \
		$(CC) $(CFLAGS) -I$(INC) -D CT=ft -c $(SRC_DIR)$$d.cpp -o $(OBJ_DIR)/$(@)$$d.o; \
		$(CC) $(CFLAGS) $(OBJ_DIR)/$(FT)$$d.o -o $(DXE1)/$(@)$$d; \
    done
	
$(STD): 
	mkdir -p objs exe_std
	for d in $(EXE); do \
		$(CC) $(CFLAGS) -I$(INC) -D CT=std -c $(SRC_DIR)$$d.cpp -o $(OBJ_DIR)/$@$$d.o; \
		$(CC) $(CFLAGS) $(OBJ_DIR)/$(STD)$$d.o -o $(DXE2)/$(@)$$d; \
	done

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(DXE1) $(DXE2)

re: fclean all

.PHONY: all clean fclean re