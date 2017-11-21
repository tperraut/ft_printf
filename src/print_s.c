
#include "libftprintf.h"

void	print_s(char *s, t_specs *specs, t_buffer *b)
{
	if (specs && b)
		b->addstr(s, b);
}
