
#include "encoder.h"

void	print_tree(t_tree *tree)
{
	printf("   -------TREE-------");
	printf("         [HEAD]\n");
	printf("          [%d]\n", tree->frecuency);
	while (tree)
	{
		if (!tree->c)
		{
			printf("        [PARENT]\n");
			printf("          [%d]\n", tree->frecuency);
		}
		else
		{
			printf("        [PARENT]\n");
			printf("\n[%c] => [%d]\n", tree->c, tree->frecuency);
		}
		tree = tree->next;
	}
	printf("   --------------------\n");
}

void	print_lst(t_tree *tree)
{
	t_tree	*aux;

	aux = tree;
	printf("   ------FRECUENCY LIST-------");
	while (aux)
	{
		printf("\n[%c] => [%d]\n", aux->c, aux->frecuency);
		aux = aux->next;
	}
	printf("   --------------------\n");
}

void	ft_decoder(char *txt)
{
	t_tree	*tree;
	t_tree	*frecuency_lst;

	frecuency_lst = find_frecuency(txt);
	print_lst(frecuency_lst);
	tree = create_huffman_tree(&frecuency_lst);
	print_tree(tree);
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
