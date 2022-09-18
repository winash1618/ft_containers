# SRC = v_erase_test.cpp
SRC = m_construct_test.cpp m_at_test.cpp m_begin_test.cpp m_clear_test.cpp \
		m_count_test.cpp m_empty_test.cpp m_end_test.cpp m_equal_range_test.cpp \
		m_erase_test.cpp m_find_test.cpp m_get_allocator_test.cpp m_insert_test.cpp \
		m_key_comp_test.cpp m_lower_bound_test.cpp m_max_size_test.cpp \
		m_operator[]_test.cpp m_operator=_test.cpp m_rbegin_test.cpp \
		m_rend_test.cpp m_size_test.cpp m_swap_test.cpp m_upper_bound_test.cpp \
		m_value_comp_test.cpp m_relational_operators_test.cpp \
		m_non_member_swap_test.cpp

SRC_DIR = tests/map_tests/

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