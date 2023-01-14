
#include "encoder.h"
#define LEFT 0
#define RIGHT 1
#define	HEAD 42

void	print_tree(t_tree *tree, int size, int flag)
{
	if (tree->c)
	{
		if (flag == RIGHT)
			printf("\t\t\033[1;34m[right]\033[0m\n");
		else if (flag == LEFT)
			printf("\t\t\033[1;35m[left]\033[0m\n");
		printf("\t\033[1;32m[LEAF]\033[0m => [%c]\t\033[1;33m[HEIGHT]\033[0m => [%d]\n", tree->c, size);
	}
	else
	{
		print_tree(tree->right, size + 1, RIGHT);
		print_tree(tree->left, size + 1, LEFT);
	}
}

void	print_lst(t_tree *tree)
{
	t_tree	*aux;

	aux = tree;
	printf("\t------FRECUENCY LIST-------");
	while (aux)
	{
		printf("\n            [%c] => [%d]\n", aux->c, aux->frecuency);
		aux = aux->next;
	}
	printf("\t--------------------\n");
}

void	ft_decoder(char *txt)
{
	t_tree	*tree;
	t_tree	*frecuency_lst;

	frecuency_lst = find_frecuency(txt);
	print_lst(frecuency_lst);
	tree = create_huffman_tree(&frecuency_lst);
	printf("\t\t\033[1;33m------TREE------\033[0m\n");
	print_tree(tree, 0, HEAD);
	free_tree(&tree);
}

int	main(void)
{
	char	*buff;
	int		fd;

	buff = calloc(sizeof(char), 200);
	fd = open("file", O_RDONLY);
	read(fd, buff, 200);
	close(fd);
	ft_decoder(buff);
	free(buff);
	return (0);
}
