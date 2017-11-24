
#include "libftprintf.h"

void	print_int(int n, t_specs *sp, t_buffer *b)
{
	if (n < 0)
		SET(sp->info, SIGN);
	print_uint((unsigned int) ABS(n), sp, b);
}

void	print_uint(unsigned int n, t_specs *sp, t_buffer *b)
{
	char			*alpha_16;
	size_t			len;
	unsigned int	div;
	unsigned int	base;
	unsigned int	i;

	base = (unsigned int) get_base(sp);
	alpha_16 = (GET(sp->type, T_X)) ? ALPHA_16 : UALPHA_16;
	len = 1;
	i = n;
	div = 1;
	if (n == 0)
		SET(sp->info, IS_0);
	while (i >= base && ++len)
	{
		div *= base;
		i /= base;
	}
	len = check_flags_start(len, sp, b);
	while (div)
	{
		b->add(alpha_16[(n / div) % base], b);
		div /= base;
	}
	check_flags_end(len, sp, b);
}
