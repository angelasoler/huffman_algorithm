#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct p_tree
{
	char	c;
	int		frecuency;
	struct	p_tree *next;
	struct	p_tree *right;
	struct	p_tree *left;
}	t_tree;

t_tree		*find_frecuency(char *txt);
void		sort_list_by_frecuency(t_tree **tree);

t_tree		*swap_nodes(t_tree *p1, t_tree *p2);
t_tree		*create_node(char l, int f, t_tree *right, t_tree *left);
void		put_node(t_tree **lst, t_tree *node);
void		free_tree(t_tree **tree);
int			count_lst(t_tree *lst);
t_tree		*create_huffman_tree(t_tree **huffman_tree);

void	free_int_array(int *array, int size);