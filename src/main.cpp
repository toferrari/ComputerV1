/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/26 17:31:27 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

// using namespace std;

int main(int argc, char **argv)
{
	Equation test;

	switch (argc)
	{
		case 1 :
			cout << "no equation enter !!!" << endl;
			break;
		case 2 :
			test.ecrire(test, 2);
			break;
		case 3 :
			cout << "too many argument !!!!" << endl;
			break;
	}
	return 0;
}
