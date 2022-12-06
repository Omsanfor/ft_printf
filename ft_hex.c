/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:38:24 by omsanfor          #+#    #+#             */
/*   Updated: 2022/01/03 13:41:21 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	put_hex_lower(unsigned int c, int *len)
{
	if (c <= 9)
	{
		c = c + 48;
		write(1, &c, 1);
		(*len)++;
	}
	else if (c > 9 && c <= 15)
	{
		c = c + 87;
		write(1, &c, 1);
		(*len)++;
	}
	else
	{
		put_hex_lower((c / 16), len);
		put_hex_lower((c % 16), len);
	}
}

void	put_hex_upper(unsigned int c, int *len)
{	
	if (c <= 9)
	{
		c = c + 48;
		write(1, &c, 1);
		(*len)++;
	}
	else if (c > 9 && c <= 15)
	{
		c = c + 55;
		write(1, &c, 1);
		(*len)++;
	}
	else
	{
		put_hex_upper((c / 16), len);
		put_hex_upper((c % 16), len);
	}
}

void	put_pointer(unsigned long long int p, int *len)
{
	if (p <= 9)
	{
		p = p + 48;
		write(1, &p, 1);
		(*len)++;
	}
	else if (p > 9 && p <= 15)
	{
		p = p + 87;
		write(1, &p, 1);
		(*len)++;
	}
	else
	{
		put_pointer((p / 16), len);
		put_pointer((p % 16), len);
	}
}
