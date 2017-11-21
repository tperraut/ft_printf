
#include "libftprintf.h"

size_t	uatoi(char **fmt)
{
	size_t	n;

	IF_RETURN(!fmt || !*fmt, 0);
	n = 0;
	if (!(**fmt < '0' || **fmt > '9'))
	{
		n = **fmt - '0';
		(*fmt)++;
	}
	while (!(**fmt < '0' || **fmt > '9'))
	{
		n *= 10;
		n += **fmt - '0';
		(*fmt)++;
	}
	return (n);
}

char	get_base(t_specs *specs)
{
	if (GET(specs->type, (T_X | T_UX)))
		return (16);
	if (GET(specs->type, (T_O | T_UO)))
		return (8);
	if (GET(specs->type, T_B))
		return (2);
	return (10);
}

char	is_contain(char c, char *str)
{
	if (!str)
		return (FALSE);
	while (*str)
	{
		if (c == *str)
			return (TRUE);
		str++;
	}
	return (FALSE);
}
