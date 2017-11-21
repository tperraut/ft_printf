
#include "libftprintf.h"

void	add_type(char **fmt, t_specs *specs)
{
	if (!is_contain(**fmt, TYPE))
		return;
	IF(!GET(specs->type, T_D) && **fmt == 'd', SET(specs->type, T_D))
	ELIF(!GET(specs->type, T_UD) && **fmt == 'D', SET(specs->type, T_UD))
	ELIF(!GET(specs->type, T_I) && **fmt == 'i', SET(specs->type, T_I))
	ELIF(!GET(specs->type, T_O) && **fmt == 'o', SET(specs->type, T_O))
	ELIF(!GET(specs->type, T_UO) && **fmt == 'O', SET(specs->type, T_UO))
	ELIF(!GET(specs->type, T_U) && **fmt == 'u', SET(specs->type, T_U))
	ELIF(!GET(specs->type, T_UU) && **fmt == 'U', SET(specs->type, T_UU))
	ELIF(!GET(specs->type, T_X) && **fmt == 'x', SET(specs->type, T_X))
	ELIF(!GET(specs->type, T_UX) && **fmt == 'X', SET(specs->type, T_UX))
	ELIF(!GET(specs->type, T_B) && **fmt == 'b', SET(specs->type, T_B))
	ELIF(!GET(specs->type, T_C) && **fmt == 'c', SET(specs->type, T_C))
	ELIF(!GET(specs->type, T_UC) && **fmt == 'C', SET(specs->type, T_UC))
	ELIF(!GET(specs->type, T_S) && **fmt == 's', SET(specs->type, T_S))
	ELIF(!GET(specs->type, T_US) && **fmt == 'S', SET(specs->type, T_US))
	ELIF(!GET(specs->type, T_P) && **fmt == 'p', SET(specs->type, T_P))
	(*fmt)++;
}
