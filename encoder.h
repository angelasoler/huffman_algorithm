#include <stdio.h>
#include <stdlib.h>

typedef struct p_tree
{
	char	c;
	int		frecuency;
	struct	p_tree *next;
	struct	p_tree *right;
	struct	p_tree *left;
}	t_tree;

int			count_list(t_tree *lst);
t_tree		*swap_nodes(t_tree *p1, t_tree *p2);
void		put_node(t_tree **lst, t_tree *node);
t_tree		*create_node(char l, int f);
void    	sort_list_by_frecuency(t_tree **tree);
t_tree		*find_frecuency(char *txt);
