#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define LEFT 0
#define RIGHT 1
#define	HEAD 42
#define UC unsigned char

typedef struct p_tree
{
	char	c;
	int		frecuency;
	struct	p_tree *next;
	struct	p_tree *right;
	struct	p_tree *left;
}	t_tree;

typedef struct p_sort
{
	t_tree	**head;
	t_tree	*p1;
	t_tree	*p2;
	int		size;
	int		sort;
}	t_sort;

typedef struct p_compress
{
	UC		*aux;
	UC		*bytes;
	int		new_size;
}	t_compress;

t_tree	*find_frecuency(char *txt);
void	sort_list_by_frecuency(t_tree **tree);

t_tree	*swap_nodes(t_tree *p1, t_tree *p2);
t_tree	*create_node(char l, int f, t_tree *right, t_tree *left);
void	put_node(t_tree **lst, t_tree *node);
void	free_tree(t_tree **tree);
int		count_lst(t_tree *lst);
t_tree	*create_huffman_tree(t_tree **huffman_tree);

void	print_tree(t_tree *tree, int size, int flag);
void	print_table(char **table);
void	print_lst(t_tree *lst);
void	print_enconded_bytes_str(UC *encoded_str);

void	free_table(char **table);;
void	create_table(char **table, t_tree *tree, char *trail, int rows);
int		tree_height_ft(t_tree *tree);
char	**alloc_table(int rows);