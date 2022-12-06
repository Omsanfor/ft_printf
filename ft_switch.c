/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:38:55 by omsanfor          #+#    #+#             */
/*   Updated: 2022/01/03 13:56:09 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

char	*null_string(const char *str, int *init)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = 6;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	*init = 1;
	return (new);
}

int	ft_value_s(va_list args)
{
	char	*string_value;
	int		z;
	int		len;
	int		init_malloc;

	len = 0;
	init_malloc = 0;
	string_value = va_arg(args, char *);
	if (!string_value)
		string_value = null_string("(null)", &init_malloc);
	z = 0;
	while (string_value[z] != '\0')
	{
		len = len + ft_putchar(string_value[z]);
		z++;
	}
	if (init_malloc)
		free(string_value);
	return (len);
}

int	ft_value_d_i(va_list args)
{
	int		z;
	char	*string;
	int		len;

	len = 0;
	z = 0;
	string = ft_itoa_pr(va_arg(args, int));
	while (string[z] != '\0')
	{
		len = len + ft_putchar(string[z]);
		z++;
	}
	free(string);
	return (len);
}

int	ft_value_u(va_list args)
{
	int		z;
	char	*string;
	int		len;

	len = 0;
	z = 0;
	string = ft_utoa_pr(va_arg(args, unsigned int));
	if (string[z] == '\0')
		len = len + ft_putchar(string[z]);
	while (string[z] != '\0')
	{
		len = len + ft_putchar(string[z]);
		z++;
	}
	free(string);
	return (len);
}
