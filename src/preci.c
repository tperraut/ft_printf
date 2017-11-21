
#include "libftprintf.h"

void	add_preci(char **fmt, t_specs *specs)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		SET(specs->info, PRECI);
	}
	else
		return;
	specs->preci = uatoi(fmt);
}
