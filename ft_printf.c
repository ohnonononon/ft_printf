/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:53:18 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/26 21:01:41 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	data;
	int		i;

	i = 0;
	data = (t_data){};
	va_start(args, str);
	while (str[i] != '\0' && data.errctl != -1)
	{
		if (str[i] != '%')
			aux_printc(str[i++], &data);
		else if (str[i] == '%')
			parse_format(str, str[++i], &data, args);
		if (data.errctl == -1)
			return (data.errctl);
	}
	
	va_end(args);
	return (data.lenght);
}
