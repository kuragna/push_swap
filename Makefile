NAME  	=	push_swap
CC    	=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3
RM    	=	rm -fr
SRC   	= $(addprefix src/linked-list/, $(addsuffix .c, main create_node insert issorted \
		  									 check_dup parsing stack_clear \
											 print_err small_stack stack_size operations \
											 find_biggest find_smallest check get_pos pop))
OBJ   	=	$(SRC:.c=.o)
LIB   	=	./libft/libft.a


all: $(LIB) $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIB):
	make -C ./libft/

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(LIB) $(OBJ)

clean:
	make clean -C ./libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re LIB


