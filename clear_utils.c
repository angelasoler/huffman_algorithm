
#include "encoder.h"

void	free_table(char **table)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_tree(t_tree **tree)
{
	t_tree	*aux;

	aux = *tree;
	if (!aux)
		return ;
	free_tree(&aux->right);
	free_tree(&aux->left);
	free(aux);
}

