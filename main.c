#include "ft_printf.h"
#include <stdio.h>

void	test_mod(char *s)
{
	char	*tittle = "test for\t";

	char *s2 = ft_strjoin(tittle, s);
	char *s3 = ft_strjoin(tittle, "\n");
	write(1, tittle, ft_strlen(tittle));
	free (s2);
	free (s3);
	write(1, "### FT ###\t", 12);
	int	r1 = ft_printf("%s\n", s);
	write(1, "### OG ###\t", 12);
	int r2 = printf("%s\n", s);

	write(1, "ft res\t", 8);
	ft_putnbr_fd(r1, 1);
	write(1, "\nog res\t\n", 8);
	ft_putnbr_fd(r2, 1);
}

// tests for strings and chars.
void	print_test(void)
{
	test_mod("");
	test_mod("");
	test_mod("");
	test_mod("");
}

int	main(void)
{
	print_test();
	return (0);
}
