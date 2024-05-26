/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:54 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/26 21:34:44 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aux_printc(const char c, t_data *data)
{
	data->errctl = write(1, &c, 1);
	data->lenght++;
}

void	aux_printstr(const char *str, t_data *data)
{
	while (*str && data->errctl < -1)
	{
		data->errctl = write(1, str, 1);
		data->lenght++;
	}
}

void	convert_nbr(int nb, t_data *data)
{

}

void	convert_nbrbase(unsigned int nbr, int base, t_data *data)
{
	char	*str;
	long	nb;

	str = NULL;
	nb = nbr;
	if (base == 10)
		str = "0123456789";
	else if (base == 16)
		str = "0123456789abcdef";
	else if (base == -16)
		str = "0123456789ABCDEF";
}

void	parse_format(const char *str, char format, t_data *data, va_list args)
{
	if (data->errctl == -1)
		return ;
	if (format == 'c')
		aux_printc(va_arg(args, int), data);
	else if (format == 's')
		aux_printstr(va_arg(args, char *), data);
	else if (format == 'i' || format == 'd')
		convert_nbr(va_arg(args, int), data);
	else if (format == 'u')
		convert_nbrbase(va_arg(args, unsigned int), 10, data);
	else if (format == 'x')
		convert_nbrbase(va_arg(args, unsigned int), 16, data);
	else if (format == 'X')
		convert_nbrbase(va_arg(args, unsigned int), -16, data);
	else if (format == 'p')
		convert_ptrtoint(va_arg(args, void *), data);
	else if (format == '%')
		aux_printc('%', data);
	else
		data->errctl = -1;
}
