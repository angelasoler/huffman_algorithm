
#include "encoder.h"

int	tree_height_ft(t_tree *tree)
{
	int	left;
	int	right;

	if (!tree)
		return (-1);
	else
	{
		right = tree_height_ft(tree->right) + 1;
		left = tree_height_ft(tree->left) + 1;
	}
	if (left > right)
		return (left);
	else
		return (right);
}

void	print_table(char **table)
{
	int	i;

	i = 0;
	printf("\n\t\033[1;36m------BINARY TABLE REF------\033[0m\n\n");
	while (i < 256)
	{
		if (*table[i])
			printf("\t\t[%c] => [%s]\n", (char)i, table[i]);
		i++;
	}
	printf("\n\t\033[1;36m---------------------------\033[0m\n");
}

char	**alloc_table(int rows)
{
	char	**table;
	int		i;

	table = calloc(sizeof(char*), 256);
	for (i = 0; i < 256; i++)
		table[i] = calloc(sizeof(char), rows);
	return (table);
}

void create_table(char **table, t_tree *tree, char *trail, int rows)
{
	char	aux_right[rows];
	char	aux_left[rows];

	if (tree->c)
		strcpy(table[(int)tree->c], trail);
	else
	{
		strcpy(aux_left, trail);
		strcpy(aux_right, trail);
		strcat(aux_left, "0");
		strcat(aux_right, "1");
		create_table(table, tree->left, aux_left, rows);
		create_table(table, tree->right, aux_right, rows);
	}
}
