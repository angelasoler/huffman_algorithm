
#include <time.h>
#include "encoder.h"

typedef struct p_info
{
	int	encoded_bytes;
	int	decoded_bytes;
	int	time;
}	t_info;

typedef struct p_decode
{
	UC		*bin_txt;
	char	**table;
	int		final_size;
	t_info	info;
}	t_decode;
