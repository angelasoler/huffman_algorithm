
#include "../includes/decoder.h"


void	get_decompress_data(t_decode *decode)
{
	size_t	len;
	int		i;
	int		total_len;

	i = 0;
	printf("\n");
	total_len = 0;
	decode->info.decoded_bytes = 0;
	while (total_len < decode->final_size)
	{
		while (!*decode->table[i])
			i++;
		len = strlen(decode->table[i]);
		while (strncmp((char *)&decode->bin_txt[total_len], decode->table[i], len))
		{
			i++;
			while (!*decode->table[i])
				i++;
			len = strlen(decode->table[i]);
		}
		printf("%c", (char)i);
		decode->info.decoded_bytes++;
		i = 0;
		total_len += len;
	}
	printf("\n");
}

UC	*bytes_to_str(UC *txt)
{
	UC			*bin_txt;
	int			init_size;
	int			bitwise;
	int			i;

	init_size = strlen((char *)txt);
	bin_txt = calloc(sizeof(char), (init_size * 8) + 1);
	for (i = 0; i < init_size; i++)
	{
		for (bitwise = 7; bitwise >= 0; bitwise--)
			bin_txt[(i * 8) + (7 - bitwise)] = ((txt[i] >> bitwise) & 1) + '0';
	}
	return (bin_txt);
}

void	decoder(t_decode *decode)
{
	UC	*txt;
	int	fd;

	decode->info.encoded_bytes = 0;
	txt = calloc(sizeof(char), 1024);
	fd = open("data/compress_file", O_RDONLY);
	read(fd, txt, 1024);
	decode->info.encoded_bytes = strlen((char*)txt);
	close(fd);
	decode->bin_txt = bytes_to_str(txt);
	get_decompress_data(decode);
	free(decode->bin_txt);
	free(txt);
}

void	conect_process(t_data *data)
{
	t_decode	decode;
	clock_t		start;
	clock_t		end;
	double		total;

	start = clock();
	decode.table = data->table;
	decode.final_size = data->bit_size;
	decoder(&decode);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n\t\033[1;36mCompressed bytes:\033[0m %d\n", decode.info.encoded_bytes);
	printf("\n\t\033[1;36mOriginal text bytes:\033[0m%d\n", decode.info.decoded_bytes);
	printf("\n\t\033[1;36mTime process takes:\033[0m %f sec\n", total);
	free_table(data->table);
	free(data->txt);
}
