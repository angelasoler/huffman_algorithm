
NAME =	labs

CC =	cc

WFLAGS = -Wall -Werror -Wextra

SRC =	encoder.c \
		huffman_tree_utils.c \
		list_utils.c \
		utils.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)creating ./labs$(RESET)"
	$(CC) $(WFLAGS) -g3 -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -g3 $(WFLAGS) -c $< -o $@

re: fclean all
	@make clean

fclean: clean
	rm -rf $(NAME)

clean:
	@rm -rf *.o

.PONHY: re fclean clean all