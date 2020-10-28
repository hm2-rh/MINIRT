/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:56:49 by hrhirha           #+#    #+#             */
/*   Updated: 2020/10/27 13:56:51 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_double(char *s)
{
	int i;
	int	flt;

	i = 0;
	flt = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) && (flt == 0 || flt == 1))
			;
		else if (s[i] == '.' && flt == 0)
			flt++;
		else
			return (-1);
		i++;
	}
	return (1);
}

int		is_int(char *s)
{
	int i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		i++;
	}
	return (1);
}

int		is_whitespace(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (-1);
}

void	isvalid_rgb(char **sub)
{
	int	i;

	i = 0;
	while (i < tab_len(sub))
	{
		if (is_int(sub[i]) == -1)
		{
			ft_putstr_fd("Error\nWrong RGB values\n", 0);
			free_tab(sub);
			exit(-1);
		}
		i++;
	}
}

void	isvalid_vec(char **sub)
{
	int	i;

	i = 0;
	while (i < tab_len(sub))
	{
		if (is_double(sub[i]) == -1)
		{
			ft_putstr_fd("Error\nWrong VECTOR values\n", 0);
			free_tab(sub);
			exit(-1);
		}
		i++;
	}
}
