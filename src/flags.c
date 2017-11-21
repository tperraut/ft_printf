
#include "libftprintf.h"

void	add_flags(char **fmt, t_specs *specs)
{
	while (is_contain(**fmt, FLAGS))
	{
		if (!GET(specs->flags, F_S) && **fmt == '#')
			SET(specs->flags, F_S);
		else if (!GET(specs->flags, F_Z) && **fmt == '0')
			SET(specs->flags, F_Z);
		else if (!GET(specs->flags, F_P) && **fmt == '+')
			SET(specs->flags, F_P);
		else if (!GET(specs->flags, F_M) && **fmt == '-')
			SET(specs->flags, F_M);
		else if (!GET(specs->flags, F_SP) && **fmt == ' ')
			SET(specs->flags, F_SP);
		(*fmt)++;
	}
}
