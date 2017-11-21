
#include "libftprintf.h"

void	print_intmax_t(intmax_t n, t_specs *specs, t_buffer *b)
{
	if (n < 0)
		SET(specs->info, SIGN);
	print_uintmax_t((uintmax_t) ABS(n), specs, b);
}

void	print_uintmax_t(uintmax_t n, t_specs *specs, t_buffer *b)
{
	char		*alpha_16;
	size_t		len;
	uintmax_t	div;
	uintmax_t	base;
	uintmax_t	i;

	base = (uintmax_t) get_base(specs);
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
