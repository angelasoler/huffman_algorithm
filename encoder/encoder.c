
#include "../includes/encoder.h"

void	str_to_bytes(UC **str, int qbits)
{
	t_compress	comp;
	int			bitwise;
	int			i;

	comp.aux = *str;
	if (qbits % 8)
		comp.new_size = (qbits / 8) + 2;
	else
		comp.new_size = (qbits / 8) + 1;
	comp.bytes = calloc(sizeof(UC), comp.new_size);
	for (i = 0; i < (comp.new_size - 1); i++)
	{
		bitwise = 7;
		while(bitwise >= 0)
		{
			comp.bytes[i] |= (*comp.aux - '0') << bitwise;
			bitwise--;
			comp.aux++;
		}
	}
	free(*str);
	*str = comp.bytes;
}

unsigned char	*encode_str_ft(char *txt, char **table)
{
	UC	*encoded_str;

	encoded_str = calloc(sizeof(UC), 1024);
	while (*txt)
	{
		strcat((char*)encoded_str, table[(int)*txt]);
		txt++;
	}
	return (encoded_str);
}

UC	*ft_encoder(char *txt)
{
	t_tree	*tree;
	t_tree	*frecuency_lst;
	char	**table;
	int		tree_height;
	UC	*encoded_str;

	frecuency_lst = find_frecuency(txt);
	print_lst(frecuency_lst);
	tree = create_huffman_tree(&frecuency_lst);
	tree_height = tree_height_ft(tree);
	printf("\n\t\t\033[1;33m------TREE------\033[0m\n\n");
	print_tree(tree, 0, HEAD);
	printf("\n\t\t\033[1;33m----------------\033[0m\n");
	table = alloc_table(tree_height);
	create_table(table, tree, "", tree_height);
	print_table(table);
	encoded_str = encode_str_ft(txt, table);
	str_to_bytes(&encoded_str, strlen((char*)encoded_str));
	print_enconded_bytes_str(encoded_str);
	free_tree(&tree);
	free_table(table);
	return (encoded_str);
}

int	main(void)
{
	char	*buff;
	int		fd[2];
	UC	*compress_str;

	buff = calloc(sizeof(char), 200);
	fd[0] = open("data/input_file", O_RDONLY);
	fd[1] = open("data/compress_file", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	read(fd[0], buff, 200);
	close(fd[0]);
	compress_str = ft_encoder(buff);
	free(buff);
	write(fd[1], compress_str, strlen((char*)compress_str));
	close(fd[1]);
	free(compress_str);
	return (0);
}
