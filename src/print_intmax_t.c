
#include "libftprintf.h"

void	print_intmax_t(intmax_t n, t_specs *sp, t_buffer *b)
{
	if (n < 0)
		SET(sp->info, SIGN);
	print_uintmax_t((uintmax_t) ABS(n), sp, b);
}

void	print_uintmax_t(uintmax_t n, t_specs *sp, t_buffer *b)
{
	char		*alpha_16;
	size_t		len;
	uintmax_t	div;
	uintmax_t	base;
	uintmax_t	i;

	base = (uintmax_t) get_base(sp);
	alpha_16 = (GET(sp->type, T_X)) ? ALPHA_16 : UALPHA_16;
	len = 1;
	i = n;
	div = 1;
	SET(sp->info, (n == 0) ? IS_0 : ZERO);
	while (i >= base && ++len)
	{
		div *= base;
		i /= base;
	}
	len = check_flags_start(len, sp, b);
	if (!is_empty(sp))
		while (div)
		{
			b->add(alpha_16[(n / div) % base], b);
			div /= base;
		}
	check_flags_end(len, sp, b);
}
