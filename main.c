
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	hex_test(void)
{
	hex_mod(0);
	hex_mod(-123);
	hex_mod(123);
	hex_mod(+234);
	hex_mod(INT_MIN);
	hex_mod(INT_MAX);
}

void	uint_test(void)
{
	uint_mod(0);
	uint_mod(-123);
	uint_mod(123);
	uint_mod(+234);
	uint_mod(INT_MIN);
	uint_mod(INT_MAX);
}

void	int_test(void)
{
	int_mod(0);
	int_mod(-123);
	int_mod(123);
	int_mod(+234);
	int_mod(INT_MIN);
	int_mod(INT_MAX);
}

void	print_test(void)
{
	str_mod("");
	str_mod("testeo string normal");
	str_mod("\ttabtest\0alo");
	str_mod(NULL);
}

int	main(void)
{
	// print_test();
	// int_test();
	// uint_test();
	// hex_test();
	return (0);
}
