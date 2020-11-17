/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <hrhirha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:16:37 by hrhirha           #+#    #+#             */
/*   Updated: 2020/11/17 11:16:44 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	unrecognized_id(char **tab)
{
	ft_putstr_fd("Error\nUnrecognized id: ", 1);
	ft_putstr_fd(tab[0], 1);
	ft_putchar_fd('\n', 1);
	exit(-1);
}
