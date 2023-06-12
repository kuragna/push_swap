NAME  	=	push_swap
CC    	=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM    	=	rm -fr

SRC		= 	main.c create_stack.c \
		  	check.c push.c create_node.c \
			rotate.c get.c sort_functions.c \
			sort_three.c set_index.c stack_clear.c

OBJ   	=	$(addprefix src/, $(SRC:.c=.o))
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

