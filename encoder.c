
#include "encoder.h"

void	sort_list_by_frecuency(t_encoder *encoder)
{

}

void	put_node(t_encoder *encoder, char l, int f)
{

}

t_encoder	*find_frecuency(char *txt)
{
	int	i;
	int	*frecuency;
	// t_encoder encoder;

	frecuency = calloc(sizeof(int), 255);
	// encoder = malloc(sizeof(t_encoder) * 1);
	i = 0;
	while (txt[i])
	{
		frecuency[txt[i]]++;
		i++;
	}
	for (i = 0; i < 255; i++)
	{
		if (frecuency[i])
			printf("\n[%c] => [%d]\n", i, frecuency[i]);
			// encoder = create_node(i + 'a', frecuency[i]);
	}
	// sort_list_by_frecuency(frecuency);
	return (0);
}

t_encoder	*ft_decoder(char *txt)
{
	return (find_frecuency(txt));
}

int	main(int argc, char *argv[])
{
	// t_encoder	*encoder;

	if (argc == 1)
		return (printf("Give me some input\n"));
	if (argc > 2)
		printf("Just a one string for now, please.\n");
	else
		// encoder = 
		ft_decoder(argv[1]);
	// printf("   -------TABLE-------");
	// while (encoder)
	// {
	// 	printf("\n[%c] => [%d]\n", encoder->c, encoder->frecuency);
	// 	encoder = encoder->next;
	// }
	// printf("   --------------------");
}