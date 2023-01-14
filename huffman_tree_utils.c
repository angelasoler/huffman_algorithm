#include "encoder.h"

t_tree	*remove_two_nodes(t_tree **huffman_tree)
{
	t_tree *head;
	t_tree *p1;
	t_tree *p2;

	head = *huffman_tree;
	p1 = head;
	p2 = p1->next;
	head = p2->next;
	p1->next = NULL;
	p2->next= NULL;
	*huffman_tree = head;
	return (head);
}

t_tree	*create_huffman_tree(t_tree **huffman_tree)
{
	t_tree *aux;
	t_tree *parent;

	aux = *huffman_tree;
	while (1)
	{
		if (count_lst(aux) == 1)
			break ;
		parent = create_node(0, (aux->frecuency + aux->next->frecuency), aux, aux->next);
		put_node(huffman_tree, parent);
		sort_list_by_frecuency(huffman_tree);
		aux = remove_two_nodes(huffman_tree);
	}
	return (aux);
}

void	sort_list_by_frecuency(t_tree **encoder)
{
	t_tree	**head;
	t_tree	*p1;
	t_tree	*p2;
	int		size;
	int		sort;
	int		i;
	int		n;

	if (!*encoder)
		return ;
	size = count_lst(*encoder);
	for (i = 0; i <= size; i++)
	{
		head = encoder;
		sort = 0;
		for (n = 0; n < size - i - 1; n++)
		{
			p1 = *head;
			p2 = p1->next;
			if (p1->frecuency > p2->frecuency)
			{
				*head = swap_nodes(p1, p2);
				sort = 1;
			}
			head = &(*head)->next;
		}
		if (!sort)
			break;
	}
}

t_tree	*find_frecuency(char *txt)
{
	int		i;
	int		*frecuency;
	t_tree	*encoder;

	encoder = NULL;
	frecuency = calloc(sizeof(int), 256);
	i = 0;
	while (txt[i])
	{
		frecuency[(int)txt[i]]++;
		i++;
	}
	for (i = 0; i < 256; i++)
	{
		if (frecuency[i])
			put_node(&encoder, create_node(i, frecuency[i], NULL, NULL));
	}
	sort_list_by_frecuency(&encoder);
	free(frecuency);
	return (encoder);
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
