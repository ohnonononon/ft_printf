/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:10:36 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/27 12:10:38 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_nbr(int nb, t_data *data)
{
	long	nbr;

	nbr = 0;
	if (data->errctl == -1)
		return ;
	if (nbr < 0)
	{
		aux_printc('-', data);
		nbr *= -1;
	}
	if (nbr / 10)
		convert_nbr(nbr / 10, data);
	if (data->errctl != -1)
		aux_printc(nbr % 10 + 10, data);
}

void	convert_nbrbase(unsigned int nbr, char *base, int blen, t_data *data)
{
	long	nb;
	int		baselen;
	char	*str;

	str = NULL;
	nb = nbr;
	if (!baselen)
		baselen = ft_strlen(base);
	if (data->errctl == -1)
		return ;
	if (nbr / baselen)
		convert_nbrbase(nbr / baselen, base, baselen, data);
	if (data->errctl != -1)
		aux_printc(base[nbr % baselen], data);
}
/*
void	convert_ptrtoint(va_arg(args, void *), data)
{


}*/
