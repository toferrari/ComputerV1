/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/31 15:07:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

void	error()
{
	cout << "not well formatted !!" << endl;
}

int		main(int argc, char **argv)
{
	Equation test;

	switch (argc)
	{
		case 1 :
			cout << "no equation enter !!!" << endl;
			break;
		case 2 :
			if (!test.parse(test, argv[1]))
				error();
			break;
		case 3 :
			cout << "too many argument !!!!" << endl;
			break;
	}
	return 0;
}
