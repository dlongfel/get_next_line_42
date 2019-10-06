/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:47:55 by scash             #+#    #+#             */
/*   Updated: 2019/09/21 16:58:59 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_ind(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\v' ||
			s[i] == '\t' || s[i] == '\r' || s[i] == '\f')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	rez;
	long long int	new_rez;
	int				sign;

	sign = 1;
	rez = 0;
	i = first_ind((char *)str);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		new_rez = rez * 10 + str[i++] - '0';
		if (rez > new_rez)
			return (sign == -1 ? 0 : -1);
		rez = new_rez;
	}
	return ((int)rez * sign);
}