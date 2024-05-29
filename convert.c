/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:10:36 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/29 10:08:36 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_nbr(int nb, t_data *data)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		aux_printc('-', data);
		nbr = -nbr;
	}
	if (nbr / 10)
		convert_nbr(nbr / 10, data);
	aux_printc(nbr % 10 + '0', data);
}

void	convert_nbrbase(unsigned int nbr, char *base, int baselen, t_data *data)
{
	long	nb;
	char	*str;

	str = NULL;
	nb = nbr;
	if (data->errctl == -1)
		return ;
	if (nbr / baselen)
		convert_nbrbase(nbr / baselen, base, baselen, data);
	aux_printc(base[nbr % baselen], data);
}
/*
void	convert_ptrtoint(va_arg(args, void *), data)
{


}*/
