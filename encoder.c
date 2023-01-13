
#include "encoder.h"

void	print_tree(t_tree *tree)
{
	printf("   -------TABLE-------");
	while (tree)
	{
		printf("\n[%c] => [%d]\n", tree->c, tree->frecuency);
		tree = tree->next;
	}
	printf("   --------------------\n");
}

void	ft_decoder(char *txt)
{
	t_tree	*tree;

	tree = find_frecuency(txt);
	print_tree(tree);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (printf("Give me some input\n"));
	if (argc > 2)
		printf("Just a one string for now, please.\n");
	else
		ft_decoder(argv[1]);
}
