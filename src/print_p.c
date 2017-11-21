
#include "libftprintf.h"

void	print_p(size_t n, t_specs *specs, t_buffer *b)
{
	SET(specs->flags, F_S);
	specs->type = T_X;
	print_size_t(n, specs, b);
}
