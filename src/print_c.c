
#include "libftprintf.h"

void	print_c(char c, t_specs *specs, t_buffer *b)
{
	if (specs && b)
		b->add(c, b);
}
