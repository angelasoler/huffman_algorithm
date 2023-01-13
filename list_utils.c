#include "encoder.h"

int	count_list(t_tree *lst)
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

t_tree *swap_nodes(t_tree *p1, t_tree *p2)
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

t_tree	*create_node(char l, int f)
{
	t_tree *encoder;

	encoder = malloc(sizeof(t_tree));
	encoder->c = l;
	encoder->frecuency= f;
	encoder->next = NULL;
	encoder->right = NULL;
	encoder->left = NULL;
	return (encoder);
}

t_tree   *alloc_huffman_tree(t_tree *huffman_tree)
{
    (void)huffman_tree;
    return (0);
}
