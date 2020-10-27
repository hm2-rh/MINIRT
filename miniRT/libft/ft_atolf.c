/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:08:13 by hrhirha           #+#    #+#             */
/*   Updated: 2019/10/31 10:54:03 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int		ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static	void	floating_num(const char *str, int *i, double *flt, double *res)
{
	*i += 1;
	*flt = 10;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*res += (str[*i] - 48) / *flt;
		*flt *= 10;
		*i += 1;
	}
}

double			ft_atolf(const char *str)
{
	int			i;
	double		flt;
	int			sign;
	double		res;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - 48);
	if (str[i] == '.')
		floating_num(str, &i, &flt, &res);
	return (res * sign);
}
