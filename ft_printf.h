/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:38:51 by omsanfor          #+#    #+#             */
/*   Updated: 2022/01/03 13:48:08 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h> 

//ft_printf.c
int		ft_putchar(char a);
int		ft_printf(const char *input, ...);

//ft_switch.c
int		ft_value_s(va_list args);
int		ft_value_p_x_X(va_list args, char *newstr);
int		ft_value_d_i(va_list args);
int		ft_value_u(va_list args);

//ft_hex.c
void	put_hex_lower(unsigned int c, int *len);
void	put_hex_upper(unsigned int c, int *len);
void	put_pointer(unsigned long long int p, int *len);

//ft_itoa.c
char	*ft_itoa_pr(int n);

//ft_utoa.c
char	*ft_utoa_pr(unsigned int n);

#endif