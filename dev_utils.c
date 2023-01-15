#include "encoder.h"

void	print_enconded_bytes_str(UC *encoded_str)
{
    printf("\n\t\033[1;31m  ------COMPRESSED RESULT------\033[0m\n\n");
    printf("\n\t   \033[1;32m------|DEC|---|SYMBOL|-----\033[0m\n\n");
	while (*encoded_str)
	{
		printf("\n\t    \033[1;33m     [%3d]    [ %1c ]      \033[0m\n\n", *encoded_str, *encoded_str);
		encoded_str++;
	}
    printf("\n\t   \033[1;32m---------------------------\033[0m\n\n");
    printf("\n\t\033[1;31m  -----------------------------\033[0m\n\n");
}
