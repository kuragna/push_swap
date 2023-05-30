NAME  	=	push_swap
CC    	=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3
RM    	=	rm -fr




SRC		= $(addsuffix .c, main create_node create_stack insert issorted check_dup parsing stack_clear \
		  				  print_err small_stack operations check get_pos pop get_min get_max)
SRC		:= $(addprefix src/linked-list/, $(SRC))

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


