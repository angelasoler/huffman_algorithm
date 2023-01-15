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

void	sort_list_by_frecuency(t_tree **encoder)
{
	t_sort	var;
	int		i;
	int		n;

	if (!*encoder)
		return ;
	var.size = count_lst(*encoder);
	for (i = 0; i <= var.size; i++)
	{
		var.head = encoder;
		var.sort = 0;
		for (n = 0; n < var.size - i - 1; n++)
		{
			var.p1 = *var.head;
			var.p2 = var.p1->next;
			if (var.p1->frecuency > var.p2->frecuency)
			{
				*var.head = swap_nodes(var.p1, var.p2);
				var.sort = 1;
			}
			var.head = &(*var.head)->next;
		}
		if (!var.sort)
			break;
	}
}

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
