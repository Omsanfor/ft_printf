/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:39:19 by omsanfor          #+#    #+#             */
/*   Updated: 2022/01/03 13:56:49 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	num_sum(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa_pr(unsigned int n)
{
	char	*num;
	int		i;

	i = num_sum(n);
	if (i == 0)
		i++;
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (num == NULL)
		return (NULL);
	num[i] = 0;
	while (i-- > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
