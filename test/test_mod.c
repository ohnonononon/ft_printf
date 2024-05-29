/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:09:31 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/29 15:16:06 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void	ptr_mod(void *p)
{
	char	*tittle = "\nTEST FOR";

	if (!p)
		p = 0;
	printf("%s\t<<%p>>\n", tittle, p);

	write(1, "### FT ###\t", 12);
	int	r1 = ft_printf("%p\n", p) - 1;

	write(1, "### OG ###\t", 12);
	int r2 = printf("%p\n", p) - 1;

	printf("FT: %d\tOG: %d\n", r1 - 1, r2 - 1);
}

void	hex_mod(unsigned int x)
{
	char	*tittle = "\nTEST FOR";

	if (!x)
		x = 0;
	printf("%s\t<<%x>>\n", tittle, x);

	write(1, "### FT ###\t", 12);
	int	r1 = ft_printf("%x\n", x) - 1;

	write(1, "### OG ###\t", 12);
	int r2 = printf("%x\n", x) - 1;

	printf("FT: %d\tOG: %d\n", r1 - 1, r2 - 1);
}

void	uint_mod(unsigned int d)
{
	char	*tittle = "\nTEST FOR";

	if (!d)
		d = 0;
	printf("%s\t<<%u>>\n", tittle, d);

	write(1, "### FT ###\t", 12);
	int	r1 = ft_printf("%u\n", d) - 1;

	write(1, "### OG ###\t", 12);
	int r2 = printf("%u\n", d) - 1;
	printf("FT: %d\tOG: %d\n", r1 - 1, r2 - 1);
}

void	int_mod(int d)
{
	char	*tittle = "\nTEST FOR";

	if (!d)
		d = 0;
	printf("%s\t<<%d>>\n", tittle, d);

	write(1, "### FT ###\t", 12);
	int	r1 = ft_printf("%d\n", d) - 1;

	write(1, "### OG ###\t", 12);
	int r2 = printf("%d\n", d) - 1;
	printf("FT: %d\tOG: %d\n", r1 - 1, r2 - 1);

	write(1, "ft res\t", 8);
	ft_putnbr_fd(r1, 1);
	write(1, "\nog res\t\n", 8);
	ft_putnbr_fd(r2, 1);
	write(1, "\n", 1);
}

void	str_mod(char *s)
{
	char	*tittle = "\nTEST FOR";

	if (!s)
		s = NULL;
	printf("%s\t<<%s>>\n", tittle, s);
	write(1, "### FT ###\t", 12);
	int	r1 = ft_printf("%s\n", s) - 1;
	write(1, "### OG ###\t", 12);
	int r2 = printf("%s\n", s) - 1;
	printf("FT: %d\tOG: %d\n", r1 - 1, r2 - 1);
}
