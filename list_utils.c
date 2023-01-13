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

t_tree	*create_node(char l, int f, t_tree *right, t_tree *left)
{
	t_tree *encoder;

	encoder = malloc(sizeof(t_tree));
	encoder->c = l;
	encoder->frecuency= f;
	encoder->next = NULL;
    encoder->right = right;
    encoder->left = left;
	return (encoder);
}

t_tree   *alloc_huffman_tree(t_tree *huffman_tree)
{
    t_tree *aux;

    aux = huffman_tree;
    while (aux)
    {
        put_node(&huffman_tree, create_node(0, (aux->frecuency + aux->next->frecuency), aux, aux->next));
        sort_list_by_frecuency(huffman_tree);
        aux = aux->tree;
    }
    return (0);
}
