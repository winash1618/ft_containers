# SRC = v_erase_test.cpp
SRC = set_construct_test.cpp set_begin_test.cpp set_clear_test.cpp \
		set_count_test.cpp set_empty_test.cpp set_end_test.cpp \
		set_equal_range_test.cpp set_erase_test.cpp set_find_test.cpp \
		set_get_allocator_test.cpp set_insert_test.cpp

SRC_DIR = tests/set_tests/

EXE = $(SRC:.cpp=)

DXE1 = exe_ft

DXE2 = exe_std

INC = includes

OBJ_DIR = objs

FT = ft_

STD = std_

CC = c++

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

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