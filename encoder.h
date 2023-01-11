#include <stdio.h>
#include <stdlib.h>

typedef struct p_encoder
{
	char	c;
	int		frecuency;
	struct	p_encoder *next;
	struct	p_encoder *right;
	struct	p_encoder *left;
}	t_encoder;

