/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:10:36 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/29 14:53:41 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

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

void	convert_nbrbase(unsigned long nbr, char *base, int blen, t_data *data)
{
	if (data->errctl == -1)
		return ;
	if (nbr / blen)
		convert_nbrbase(nbr / blen, base, blen, data);
	aux_printc(base[nbr % blen], data);
}

// tbf: ip! -> 0x0
void	convert_ptrtoint(void *ptr, t_data *data)
{
	intptr_t	ip;

	ip = (intptr_t) ptr;
	if (!ip)
	{
		aux_printstr("(nil)", data);
		return ;
	}
	aux_printstr("0x", data);
	convert_nbrbase(ip, "0123456789abcdef", 16, data);
}
