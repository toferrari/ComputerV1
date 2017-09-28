/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:52:54 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/28 16:15:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

double		ft_sqrt(double nb)
{
	double	res;
	int		j;
	double	x;

	j = -1;
	x = 1;
	while (++j < 100)
	{
		res = (x + (nb / x)) / 2;
		x = res;
	}
	return (res);
}
