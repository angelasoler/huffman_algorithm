ifneq (,$(findstring xterm,${TERM}))
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	RESET := $(shell tput -Txterm sgr0)
endif

define GIT =
	git add .
	git status
	read -p "${YELLOW}Commit Message:${RESET}" commit_message
	git commit -m "$$commit_message"
	git push origin
	git push labs
endef

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

commit:
	@$(GIT)

.PONHY: re fclean clean all