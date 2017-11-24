
#include "libftprintf.h"

void	add_type(char **fmt, t_specs *sp)
{
	if (!is_contain(**fmt, TYPE))
		return;
	IF(!GET(sp->type, T_D) && **fmt == 'd', SET(sp->type, T_D))
	ELIF(!GET(sp->type, T_UD) && **fmt == 'D', SET(sp->type, T_UD))
	ELIF(!GET(sp->type, T_I) && **fmt == 'i', SET(sp->type, T_I))
	ELIF(!GET(sp->type, T_O) && **fmt == 'o', SET(sp->type, T_O))
	ELIF(!GET(sp->type, T_UO) && **fmt == 'O', SET(sp->type, T_UO))
	ELIF(!GET(sp->type, T_U) && **fmt == 'u', SET(sp->type, T_U))
	ELIF(!GET(sp->type, T_UU) && **fmt == 'U', SET(sp->type, T_UU))
	ELIF(!GET(sp->type, T_X) && **fmt == 'x', SET(sp->type, T_X))
	ELIF(!GET(sp->type, T_UX) && **fmt == 'X', SET(sp->type, T_UX))
	ELIF(!GET(sp->type, T_B) && **fmt == 'b', SET(sp->type, T_B))
	ELIF(!GET(sp->type, T_C) && **fmt == 'c', SET(sp->type, T_C))
	ELIF(!GET(sp->type, T_UC) && **fmt == 'C', SET(sp->type, T_UC))
	ELIF(!GET(sp->type, T_S) && **fmt == 's', SET(sp->type, T_S))
	ELIF(!GET(sp->type, T_US) && **fmt == 'S', SET(sp->type, T_US))
	ELIF(!GET(sp->type, T_P) && **fmt == 'p', SET(sp->type, T_P))
	(*fmt)++;
}
