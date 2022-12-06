/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:39:12 by omsanfor          #+#    #+#             */
/*   Updated: 2022/01/03 13:39:12 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar(char a)
{
	write (1, &a, 1);
	return (1);
}

static int	ft_check_symbol(va_list args, char *newstr)
{
	int	len;

	len = 0;
	if (*newstr == 'c')
		len = len + ft_putchar(va_arg(args, int));
	else if (*newstr == 's')
		len = len + ft_value_s(args);
	else if (*newstr == 'p')
	{
		write(1, "0x", 2);
		len = len + 2;
		put_pointer((va_arg(args, unsigned long long int)), &len);
	}
	else if (*newstr == 'x')
		put_hex_lower((va_arg(args, unsigned int)), &len);
	else if (*newstr == 'X')
		put_hex_upper((va_arg(args, unsigned int)), &len);
	else if (*newstr == 'd' || *newstr == 'i')
		len = len + ft_value_d_i(args);
	else if (*newstr == 'u')
		len = len + ft_value_u(args);
	else if (*newstr == '%')
		len = len + ft_putchar('%');
	return (len);
}

int	ft_printf(const char *input, ...)
{
	char		*newstr;
	va_list		args;
	int			len;

	len = 0;
	if (input == NULL)
		return (-1);
	newstr = (char *)input;
	va_start(args, input);
	while (*newstr != '\0')
	{
		if (*newstr == '%' && *(newstr + 1) != '\0')
		{
			newstr++;
			len = len + ft_check_symbol(args, newstr);
			newstr++;
		}
		else
		{
			len = len + ft_putchar(*newstr);
			newstr++;
		}
	}
	return (len);
}
