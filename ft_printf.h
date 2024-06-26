/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnudes </var/spool/mail/ohnudes>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:50:09 by ohnudes           #+#    #+#             */
/*   Updated: 2024/05/29 16:24:35 by ohnudes          ###   ########.fr       */
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

//testing
void	ptr_test(void);
void	print_test(void);
void	int_test(void);
void	uint_test(void);
void	hex_test(void);

// modular blocks for testing and format
void	ptr_mod(void *p);
void	hex_mod(unsigned int x);
void	int_mod(int d);
void	uint_mod(unsigned int d);
void	str_mod(char *str);
#endif
