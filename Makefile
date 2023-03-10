
NAME =	labs

CC =	cc

WFLAGS = -Wall -Werror -Wextra

SRC =	encoder/encoder.c \
		encoder/huffman_tree_utils.c \
		encoder/list_utils.c \
		encoder/dev_utils.c \
		encoder/binary_table_utils.c \
		encoder/clear_utils.c \
		decoder/decoder.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)
	@make clean
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
	@rm -rf encoder/*.o
	@rm -rf decoder/*.o

.PONHY: re fclean clean all