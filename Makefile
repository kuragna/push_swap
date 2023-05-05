NAME  	=	push_swap
CC    	=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3
RM    	=	rm -fr
SRC   	= $(addprefix src/linked-list/, $(addsuffix .c, main ft_isnumber add_node insert issorted \
		  									check_number check_dup add_numbers stack_clear \
											 print_err small_stack stack_size operations ))
OBJ   	=	$(SRC:.c=.o)
LIB   	=	-L./libft/ -lft


all: $(NAME) 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft:
	make -C ./libft/

$(NAME): $(OBJ) libft
	$(CC) -o $@ $(CFLAGS) $(LIB) $(OBJ)

clean:
	make clean -C ./libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft


