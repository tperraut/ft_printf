
#include "libftprintf.h"

void	add_width(char **fmt, t_specs *specs)
{
	specs->width = uatoi(fmt);
}
