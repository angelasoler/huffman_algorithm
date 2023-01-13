#include "encoder.h"

void    sort_list_by_frecuency(t_tree **encoder)
{
    t_tree   **head;
	t_tree   *p1;
	t_tree   *p2;
    int		size;
	int		sort;
	int		i;
	int		n;

	if (!*encoder)
		return ;
    size = count_list(*encoder);
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
	int			i;
	int			*frecuency;
	t_tree	*encoder;

	frecuency = calloc(sizeof(int), 255);
	i = 0;
	while (txt[i])
	{
		frecuency[(int)txt[i]]++;
		i++;
	}
	for (i = 0; i < 256; i++)
	{
		if (frecuency[i])
			put_node(&encoder, create_node(i, frecuency[i]));
	}
	sort_list_by_frecuency(&encoder);
	return (encoder);
}
