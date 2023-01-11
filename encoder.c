
#include "encoder.h"

void	sort_list_by_frecuency(t_encoder *encoder)
{

}

//convert this function to put_and_sort
void	put_node(t_encoder **lst, t_encoder *node)
{
	t_encoder	*aux;

	if (!*lst)
		*lst = node;
	else
	{
		aux = *lst;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
	}
}

t_encoder	*create_node(char l, int f)
{
	t_encoder *encoder;

	encoder = malloc(sizeof(t_encoder));
	encoder->c = l;
	encoder->frecuency= f;
	encoder->next = NULL;
	encoder->right = NULL;
	encoder->left = NULL;
	return (encoder);
}

t_encoder	*find_frecuency(char *txt)
{
	int			i;
	int			*frecuency;
	t_encoder	*encoder;

	frecuency = calloc(sizeof(int), 255);
	i = 0;
	while (txt[i])
	{
		frecuency[txt[i]]++;
		i++;
	}
	for (i = 0; i < 256; i++)
	{
		if (frecuency[i])
			put_node(&encoder, create_node(i, frecuency[i]));
	}
	// sort_list_by_frecuency(frecuency);
	return (encoder);
}

t_encoder	*ft_decoder(char *txt)
{
	return (find_frecuency(txt));
}

int	main(int argc, char *argv[])
{
	t_encoder	*encoder;

	if (argc == 1)
		return (printf("Give me some input\n"));
	if (argc > 2)
		printf("Just a one string for now, please.\n");
	else
		encoder = ft_decoder(argv[1]);
	printf("   -------TABLE-------");
	while (encoder)
	{
		printf("\n[%c] => [%d]\n", encoder->c, encoder->frecuency);
		encoder = encoder->next;
	}
	printf("   --------------------\n");
}