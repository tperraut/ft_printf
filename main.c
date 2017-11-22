#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"
#include <locale.h>
#define __TEST__

int	main(void) {
	int a;
	setlocale(LC_ALL, "");
#ifdef __TEST__
	printf("REAL:%04.2i:\n", 42);
	ft_printf("MINE:%04.2i:\n", 42);
#endif
#ifndef __TEST__
	printf(":----BASIC TEST----:\n");
	printf(":T %%d : %d:\n", INT_MIN);
	ft_printf(":B %%d : %d:\n\n", INT_MIN);
	printf(":T %%D : %ld:\n", LONG_MIN);
	ft_printf(":B %%D : %D:\n\n", LONG_MIN);
	printf(":T %%i : %i:\n", INT_MIN);
	ft_printf(":B %%i : %i:\n\n", INT_MIN);
	printf(":T %%o : %o:\n", UINT_MAX);
	ft_printf(":B %%o : %o:\n\n", UINT_MAX);
	printf(":T %%O : %lo:\n", ULONG_MAX);
	ft_printf(":B %%O : %O:\n\n", ULONG_MAX);
	printf(":T %%u : %u:\n", UINT_MAX);
	ft_printf(":B %%u : %u:\n\n", UINT_MAX);
	printf(":T %%U : %lu:\n", ULONG_MAX);
	ft_printf(":B %%u : %U:\n\n", ULONG_MAX);
	printf(":T %%x : %x:\n", UINT_MAX);
	ft_printf(":B %%x : %x:\n\n", UINT_MAX);
	printf(":T %%X : %X:\n", UINT_MAX);
	ft_printf(":B %%X : %X:\n\n", UINT_MAX);
	printf(":T %%c : %c:\n", 'c');
	ft_printf(":B %%c : %c:\n\n", 'c');
	printf(":T %%C : %lc:\n", L'€');
	ft_printf(":B %%C : %C:\n\n", L'€');
	printf(":T %%s : %s:\n", "DONE");
	ft_printf(":B %%s : %s:\n\n", "DONE");
	printf(":T %%S : %ls:\n", L"DONé");
	ft_printf(":B %%S : %S:\n\n", L"DONé");
	printf(":T %%p : %p:\n", &a);
	ft_printf(":B %%p : %p:\n\n", &a);
	ft_printf(":B %%b : %b:\n\n", 42);

	printf(":----MODIFIER TEST----:\n");
	printf(":----L----:\n");
	printf(":T %%ld : %ld:\n", LONG_MIN);
	ft_printf(":B %%ld : %ld:\n\n", LONG_MIN);
	printf(":T %%lD : %ld:\n", LONG_MIN);
	ft_printf(":B %%lD : %lD:\n\n", LONG_MIN);
	printf(":T %%li : %li:\n", LONG_MIN);
	ft_printf(":B %%li : %li:\n\n", LONG_MIN);
	printf(":T %%lo : %lo:\n", ULONG_MAX);
	ft_printf(":B %%lo : %lo:\n\n", ULONG_MAX);
	printf(":T %%lO : %lo:\n", ULONG_MAX);
	ft_printf(":B %%lO : %lO:\n\n", ULONG_MAX);
	printf(":T %%lu : %lu:\n", ULONG_MAX);
	ft_printf(":B %%lu : %lu:\n\n", ULONG_MAX);
	printf(":T %%lU : %lu:\n", ULONG_MAX);
	ft_printf(":B %%lU : %lU:\n\n", ULONG_MAX);
	printf(":T %%lx : %lx:\n", ULONG_MAX);
	ft_printf(":B %%lx : %lx:\n\n", ULONG_MAX);
	printf(":T %%lX : %lX:\n", ULONG_MAX);
	ft_printf(":B %%lX : %lX:\n\n", ULONG_MAX);
	printf(":T %%lc : %lc:\n", L'€');
	ft_printf(":B %%lc : %lc:\n\n", L'€');
	printf(":T %%ls : %ls:\n", L"DONé");
	ft_printf(":B %%ls : %ls:\n\n", L"DONé");
	ft_printf(":B %%lb : %lb:\n\n", ULONG_MAX);

	printf(":----LL----:\n");
	printf(":T %%lld : %lld:\n", LLONG_MIN);
	ft_printf(":B %%lld : %lld:\n\n", LLONG_MIN);
	printf(":T %%lli : %lli:\n", LLONG_MIN);
	ft_printf(":B %%lli : %lli:\n\n", LLONG_MIN);
	printf(":T %%llo : %llo:\n", ULLONG_MAX);
	ft_printf(":B %%llo : %llo:\n\n", ULLONG_MAX);
	printf(":T %%llu : %llu:\n", ULLONG_MAX);
	ft_printf(":B %%llu : %llu:\n\n", ULLONG_MAX);
	printf(":T %%llx : %llx:\n", ULLONG_MAX);
	ft_printf(":B %%llx : %llx:\n\n", ULLONG_MAX);
	printf(":T %%llX : %llX:\n", ULLONG_MAX);
	ft_printf(":B %%llX : %llX:\n\n", ULLONG_MAX);
	ft_printf(":B %%llb : %llb:\n\n", ULLONG_MAX);

	printf(":----H----:\n");
	printf(":T %%hd : %hd:\n", SHRT_MIN);
	ft_printf(":B %%hd : %hd:\n\n", SHRT_MIN);
	printf(":T %%hi : %hi:\n", SHRT_MIN);
	ft_printf(":B %%hi : %hi:\n\n", SHRT_MIN);
	printf(":T %%ho : %ho:\n", USHRT_MAX);
	ft_printf(":B %%ho : %ho:\n\n", USHRT_MAX);
	printf(":T %%hu : %hu:\n", USHRT_MAX);
	ft_printf(":B %%hu : %hu:\n\n", USHRT_MAX);
	printf(":T %%hx : %hx:\n", USHRT_MAX);
	ft_printf(":B %%hx : %hx:\n\n", USHRT_MAX);
	printf(":T %%hX : %hX:\n", USHRT_MAX);
	ft_printf(":B %%hX : %hX:\n\n", USHRT_MAX);
	ft_printf(":B %%hb : %hb:\n\n", USHRT_MAX);

	printf(":----HH----:\n");
	printf(":T %%hhd : %hhd:\n", CHAR_MIN);
	ft_printf(":B %%hhd : %hhd:\n\n", CHAR_MIN);
	printf(":T %%hhi : %hhi:\n", CHAR_MIN);
	ft_printf(":B %%hhi : %hhi:\n\n", CHAR_MIN);
	printf(":T %%hho : %hho:\n", UCHAR_MAX);
	ft_printf(":B %%hho : %hho:\n\n", UCHAR_MAX);
	printf(":T %%hhu : %hhu:\n", UCHAR_MAX);
	ft_printf(":B %%hhu : %hhu:\n\n", UCHAR_MAX);
	printf(":T %%hhx : %hhx:\n", UCHAR_MAX);
	ft_printf(":B %%hhx : %hhx:\n\n", UCHAR_MAX);
	printf(":T %%hhX : %hhX:\n", UCHAR_MAX);
	ft_printf(":B %%hhX : %hhX:\n\n", UCHAR_MAX);
	ft_printf(":B %%hhb : %hhb:\n\n", UCHAR_MAX);

	printf(":----J----:\n");
	printf(":T %%jd : %jd:\n", INTMAX_MIN);
	ft_printf(":B %%jd : %jd:\n\n", INTMAX_MIN);
	printf(":T %%ji : %ji:\n", INTMAX_MIN);
	ft_printf(":B %%ji : %ji:\n\n", INTMAX_MIN);
	printf(":T %%jo : %jo:\n", UINTMAX_MAX);
	ft_printf(":B %%jo : %jo:\n\n", UINTMAX_MAX);
	printf(":T %%ju : %ju:\n", UINTMAX_MAX);
	ft_printf(":B %%ju : %ju:\n\n", UINTMAX_MAX);
	printf(":T %%jx : %jx:\n", UINTMAX_MAX);
	ft_printf(":B %%jx : %jx:\n\n", UINTMAX_MAX);
	printf(":T %%jX : %jX:\n", UINTMAX_MAX);
	ft_printf(":B %%jX : %jX:\n\n", UINTMAX_MAX);
	ft_printf(":B %%jb : %jb:\n\n", UINTMAX_MAX);

	printf(":----Z----:\n");
	printf(":T %%zd : %zd:\n", SIZE_MAX);
	ft_printf(":B %%zd : %zd:\n\n", SIZE_MAX);
	printf(":T %%zi : %zi:\n", SIZE_MAX);
	ft_printf(":B %%zi : %zi:\n\n", SIZE_MAX);
	printf(":T %%zo : %zo:\n", SIZE_MAX);
	ft_printf(":B %%zo : %zo:\n\n", SIZE_MAX);
	printf(":T %%zu : %zu:\n", SIZE_MAX);
	ft_printf(":B %%zu : %zu:\n\n", SIZE_MAX);
	printf(":T %%zx : %zx:\n", SIZE_MAX);
	ft_printf(":B %%zx : %zx:\n\n", SIZE_MAX);
	printf(":T %%zX : %zX:\n", SIZE_MAX);
	ft_printf(":B %%zX : %zX:\n\n", SIZE_MAX);
	ft_printf(":B %%zb : %zb:\n\n", SIZE_MAX);
#endif
	return(0);
}
