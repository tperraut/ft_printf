
#include "libftprintf.h"

void	print_size_t(size_t n, t_specs *specs, t_buffer *b)
{
	char	*alpha_16;
	size_t	len;
	size_t	div;
	size_t	base;
	size_t	i;

	base = get_base(specs);
	alpha_16 = (GET(specs->type, T_X)) ? ALPHA_16 : UALPHA_16;
	len = 1;
	i = n;
	div = 1;
	IF(n == 0, SET(specs->info, IS_0))
	while (i >= base)
	{
		div *= base;
		i /= base;
		len++;
	}
	len = check_flags_start(len, specs, b);
	while (div)
	{
		b->add(alpha_16[(n / div) % base], b);
		div /= base;
	}
	check_flags_end(len, specs, b);
}
