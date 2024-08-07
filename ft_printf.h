/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimatura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:36:24 by nimatura          #+#    #+#             */
/*   Updated: 2024/08/07 18:50:21 by nimatura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	errctl;
	int	lenght;
}				t_data;

void	aux_printc(const char c, t_data *data);
void	aux_printstr(const char *str, t_data *data);

void	convert_nbr(int nbr, t_data *data);
void	convert_nbrbase(unsigned long nbr, char *base, int blen, t_data *data);
void	convert_ptrtoint(void *ptr, t_data *data);

void	parse_format(char format, t_data *data, va_list args);
int		ft_printf(const char *str, ...);

#endif
