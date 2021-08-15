/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 07:31:34 by ochichep          #+#    #+#             */
/*   Updated: 2021/08/05 13:52:53 by ochichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_atoi(const char *ptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (ptr[i] == '-')
		sign *= -1;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + (ptr[i] - '0');
		i++;
	}
	if ((ptr[i] && (ptr[i] < '0' || ptr[i] > '9'))
		|| (result * sign > 2147483647) || (result * sign < -2147483648 ))
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	return (result * sign);
}
