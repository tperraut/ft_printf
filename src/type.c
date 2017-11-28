
#include "libftprintf.h"

void	add_type(char **fmt, t_specs *sp)
{
	if (!is_contain(**fmt, TYPE))
		return;
	if (!GET(sp->type, T_D) && **fmt == 'd')
		SET(sp->type, T_D);
	else if (!GET(sp->type, T_UD) && **fmt == 'D')
		SET(sp->type, T_UD);
	else if (!GET(sp->type, T_I) && **fmt == 'i')
		SET(sp->type, T_I);
	else if (!GET(sp->type, T_O) && **fmt == 'o')
		SET(sp->type, T_O);
	else if (!GET(sp->type, T_UO) && **fmt == 'O')
		SET(sp->type, T_UO);
	else if (!GET(sp->type, T_U) && **fmt == 'u')
		SET(sp->type, T_U);
	else if (!GET(sp->type, T_UU) && **fmt == 'U')
		SET(sp->type, T_UU);
	else if (!GET(sp->type, T_X) && **fmt == 'x')
		SET(sp->type, T_X);
	else if (!GET(sp->type, T_UX) && **fmt == 'X')
		SET(sp->type, T_UX);
	else if (!GET(sp->type, T_B) && **fmt == 'b')
		SET(sp->type, T_B);
	else if (!GET(sp->type, T_C) && **fmt == 'c')
		SET(sp->type, T_C);
	else if (!GET(sp->type, T_UC) && **fmt == 'C')
		SET(sp->type, T_UC);
	else if (!GET(sp->type, T_S) && **fmt == 's')
		SET(sp->type, T_S);
	else if (!GET(sp->type, T_US) && **fmt == 'S')
		SET(sp->type, T_US);
	else if (!GET(sp->type, T_P) && **fmt == 'p')
		SET(sp->type, T_P);
	(*fmt)++;
}
