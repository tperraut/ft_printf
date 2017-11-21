#include "libftprintf.h"

void	init_specs(t_specs *specs)
{
	if (!specs)
		return;
	specs->preci = 0;
	specs->width = 1;
	specs->flags = ZERO;
	specs->mod = ZERO;
	specs->info = ZERO;
	specs->type = ZERO;
}
