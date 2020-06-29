/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:06:31 by fmelda            #+#    #+#             */
/*   Updated: 2019/07/18 20:40:46 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_number(char *str)
{
	int		i;

	if (!str || !str[0])
		return (0);
	i = -1;
	if ((str[0] == '+' || str[0] == '-') && ft_strlen(str) != 1)
		i = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
