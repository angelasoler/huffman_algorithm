
#include "encoder.h"

void    sort_list_by_frecuency(t_encoder *encoder)
{

}

void    put_node(t_encoder *encoder, char l, int f)
{

}

t_encoder   *find_frecuency(char *txt)
{
    int i;
    int *frecuency;
    t_encoder encoder;

    frecuency = calloc(sizeof(int), 26);
    encoder = malloc(sizeof(t_encoder) * );
    i = 0;
    while (!txt[i])
    {
        if (txt[i] >= 'a' && txt[i] <= 'z' )
        frecuency[txt[i] - 'a']++;
        i++;
    }
    for (int c = 0; c < 26; c++)
        encoder = create_node(c + 'a', frecuency[c]);
    sort_list_by_frecuency(frecuency);
}

t_encoder *ft_decoder(char *txt)
{
    return (find_frecuency(txt));
}

int main(int argc, char *argv[])
{
    t_encoder decoder;

    if (argc == 1)
        return (printf("Give me some input\n"));
    if (argc > 2)
        printf("Just a complete string for now, please.\n");
    else
        decoder = ft_decoder(argv[1]);
    printf("   -------TABLE-------");
    while (decoder)
    {
        printf("\n[%c] => [%d]\n", decoder->l, decoder->f);
        decoder = decoder->next;
    }
    printf("   --------------------");
}