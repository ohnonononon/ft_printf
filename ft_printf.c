/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:53:18 by ohnudes           #+#    #+#             */
/*   Updated: 2024/08/18 17:11:57 by nimatura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	init_data(t_data data)
{
	data.errctl = 0;
	data.lenght = 0;
	return (data);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	data;
	int		i;

	i = 0;
	data = init_data(data);
	va_start(args, str);
	while (str[i] != '\0' && data.errctl != -1)
	{
		if (str[i] != '%')
			aux_printc(str[i++], &data);
		else if (str[i] == '%')
		{
			parse_format(str[++i], &data, args);
			i++;
		}
		if (data.errctl == -1)
			return (data.errctl);
	}
	va_end(args);
	return (data.lenght);
}
/*

#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	int_test(int a)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%d\n", a);
	og_result = printf("%d\n", a);
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

static void	char_test(unsigned char c)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%c\n", c);
	og_result = printf("%c\n", c);
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

static void	str_test(char *str)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%s\n", str);
	og_result = printf("%s\n", str);
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

static void	hex_test(unsigned int x)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%x\n", x);
	og_result = printf("%x\n", x);
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

static void	uc_hex_test(unsigned int x)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%X\n", x);
	og_result = printf("%X\n", x);
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

static void	ptr_test(void *ptr)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%p\n", ptr);
	og_result = printf("%p\n", ptr);
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

static void	fstyle_test(char *str)
{
	int og_result;
	int ft_result;

	ft_result = ft_printf("%d\n", ft_printf("%s\n", str));
	og_result = printf("%d\n", printf("%s\n", str));
	ft_printf("ft %d	og %d\n", ft_result - 1, og_result - 1);
}

int	main(void)
{
	// INT TESTS
	int_test(0);
	int_test(123);
	int_test(-123);
	int_test(INT_MAX);
	int_test(INT_MIN);

	// CHAR TESTS
	char_test('@');
	char_test(128);

	// STR TEST
	str_test("abcdef");
	str_test("xyz\0aylmao");
	str_test(NULL);

	// HEX TEST
	hex_test(0);
	hex_test(123456);
	hex_test(INT_MAX);
	hex_test(INT_MIN);

	// AGAIN
	uc_hex_test(0);
	uc_hex_test(123456);
	uc_hex_test(INT_MAX);
	uc_hex_test(INT_MIN);

	// PTR TEST
	ptr_test(NULL);
	ptr_test("aylmao");
	char	*str;
	str = ft_strdup("heap alloc");
	ptr_test(str);
	free(str);

	// freestyle
	fstyle_test("0123456789");
}*/
