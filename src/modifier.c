
#include "libftprintf.h"

void	add_mod(char **fmt, t_specs *specs)
{
	char	c;

	c = '\0';
	if (is_contain(**fmt, MOD))
	{
		c = **fmt;
		(*fmt)++;
	}
	else
		return;
	if (!GET(specs->mod, M_LL) && **fmt == 'l' && c == 'l')
		SET(specs->mod, M_LL);
	else if (!GET(specs->mod, M_L) && c == 'l')
		SET(specs->mod, M_L);
	else if (!GET(specs->mod, M_HH) && **fmt == 'h' && c == 'h')
		SET(specs->mod, M_HH);
	else if (!GET(specs->mod, M_H) && c == 'h')
		SET(specs->mod, M_H);
	else if (!GET(specs->mod, M_J) && c == 'j')
		SET(specs->mod, M_J);
	else if (!GET(specs->mod, M_Z) && c == 'z')
		SET(specs->mod, M_Z);
	if (is_contain(**fmt, MOD))
		(*fmt)++;
}
