
#include <time.h>
#include "encoder.h"

/**
 * @brief dedcodeing info
 */
typedef struct p_info
{
	int	encoded_bytes;
	int	decoded_bytes;
	int	time;
}	t_info;

/**
 * @brief auxiliar structure for decoding
 */
typedef struct p_decode
{
	UC		*bin_txt;
	char	**table;
	int		final_size;
	t_info	info;
}	t_decode;
