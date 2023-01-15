
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

	encoded_str = calloc(sizeof(UC), 10240);
	while (*txt)
	{
		strcat((char*)encoded_str, table[(int)*txt]);
		txt++;
	}
	return (encoded_str);
}

UC	*ft_encoder(char *txt, t_data *data)
{
	t_tree	*tree;
	t_tree	*frecuency_lst;
	char	**table;
	int		tree_height;
	UC	*encoded_str;

	frecuency_lst = find_frecuency(txt);
	tree = create_huffman_tree(&frecuency_lst);
	tree_height = tree_height_ft(tree);
	table = alloc_table(tree_height);
	create_table(table, tree, "", tree_height);
	data->txt = txt;
	data->table = table;
	encoded_str = encode_str_ft(txt, table);
	data->bit_size = strlen((char*)encoded_str);
	str_to_bytes(&encoded_str, data->bit_size);
	free_tree(&tree);
	return (encoded_str);
}

int	main(void)
{
	char	*buff;
	int		fd[2];
	UC		*compress_str;
	t_data	decoder_data;

	buff = calloc(sizeof(char), 1024);
	fd[0] = open("data/input_file", O_RDONLY);
	fd[1] = open("data/compress_file", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	read(fd[0], buff, 1024);
	close(fd[0]);
	if (strlen(buff) < 755)
	{
		compress_str = ft_encoder(buff, &decoder_data);
		write(fd[1], compress_str, strlen((char*)compress_str));
		free(compress_str);
		conect_process(&decoder_data);
	}
	else
		printf("Sorry that's too much :'( \nTry less tha 755 chars\n");
	close(fd[1]);
	return (0);
}
