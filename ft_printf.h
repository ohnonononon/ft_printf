/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:50:09 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/26 21:58:30 by ohnudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

// typedef struct s_flags
// {
// }				t_flags;
//
typedef struct s_data
{
	int	errctl;
	int	lenght;
}				t_data;

void	aux_printc(const char c, t_data *data);
void	aux_printstr(const char *str, t_data *data);

void	convert_nbr(int nbr, t_data *data);
// void	convert_nbrbase(unsigned int nbr, int base, t_data *data);
// void	convert_ptrtoint(void *ptr, t_data *data);
//
 void	parse_format(const char *str, char format, t_data *data, va_list args);
int		ft_printf(const char *, ...);
#endif
