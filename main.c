
#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("%d\n", printf("%s %p\n", (char *)NULL, NULL));
	ft_printf("%d\n", ft_printf("%s %p\n", (char *)NULL, NULL));
	
	return (0);
}
