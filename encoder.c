
#include "encoder.h"

void	print_lst(t_tree *lst)
{
	t_tree	*aux;

	aux = lst;
	printf("\t------FRECUENCY LIST-------");
	while (aux)
	{
		printf("\n            [%c] => [%d]\n", aux->c, aux->frecuency);
		aux = aux->next;
	}
	printf("\t-------------------------\n");
}

void	ft_decoder(char *txt)
{
	t_tree	*tree;
	t_tree	*frecuency_lst;
	char	**table;
	int		tree_height;

	frecuency_lst = find_frecuency(txt);
	print_lst(frecuency_lst);
	tree = create_huffman_tree(&frecuency_lst);
	tree_height = tree_height_ft(tree);
	printf("\n\t\t\033[1;33m------TREE------\033[0m\n\n");
	print_tree(tree, 0, HEAD);
	printf("\n\t\t\033[1;33m----------------\033[0m\n");
	table = alloc_table(tree_height);
	create_table(table, tree, "", tree_height);
	print_table(table);
	free_tree(&tree);
	free_table(table);
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
