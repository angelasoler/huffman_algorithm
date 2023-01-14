#include "encoder.h"

int	count_lst(t_tree *lst)
{
	int ret;

	ret = 0;
	while (lst)
	{
		lst = lst->next;
		ret++;
	}
	return (ret);
}

t_tree	*swap_nodes(t_tree *p1, t_tree *p2)
{
	t_tree	*aux;

	aux = p2->next;
	p2->next = p1;
	p1->next = aux;
	return (p2);
}

void	put_node(t_tree **lst, t_tree *node)
{
	t_tree	*aux;

	if (!*lst)
		*lst = node;
	else
	{
		aux = *lst;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
	}
}

t_tree	*create_node(char l, int f, t_tree *right, t_tree *left)
{
	t_tree *node;

	node = malloc(sizeof(t_tree));
	node->c = l;
	node->frecuency = f;
	node->next = NULL;
	node->right = right;
	node->left = left;
	return (node);
}
