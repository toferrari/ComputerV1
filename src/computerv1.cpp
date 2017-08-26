/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/26 17:40:27 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

Equation::Equation()
{
	la = 3;
	lb = 6;
	lc = 3;
	ra = 0;
	rb = 0;
	rc = 0;
	disc = 0;
	degre = 0;
	r1 = 0;
	r2 = 0;
}

int			Equation::discriment(int a, int b, int c)
{
	return ((b * b) - (4 * a * c));
}

int			Equation::unknow(int a, int b)
{
	return ((-b) / a);
}

int			Equation::discriment_r1(int a, int b, int disc)
{
	return ((-b - sqrt(disc)) / (2 * a));
}

int			Equation::discriment_r2(int a, int b, int disc)
{
	return ((-b + sqrt(disc)) / (2 * a));
}

int			Equation::discriment_zero(int a, int b)
{
	return ((-b) / (2 * a));
}

void		Equation::ecrire(Equation equa, int degre)
{
	int disc;

	if (degre == 1)
		cout << "Polynomial degree: 1" << endl << "The solution is:" << endl,
		cout << "x = " << unknow(la, lb) << endl;
	else if (degre == 2)
	{
		cout << "Polynomial degree: 2" << endl << "The solution is:" << endl;
		disc = discriment(equa.la, equa.lb, equa.lc);
		if (disc > 0)
			cout << "Discriminant is strictly positive, the two solutions are:",
			cout << endl << "x1 = " << discriment_r1(equa.la, equa.lb, disc),
			cout << endl << "x2 = " << discriment_r2(equa.la, equa.lb, disc),
			cout << endl;
		else if (disc == 0)
			cout << "Discriminant equals zero, the only one solution is :",
			cout << endl << "x = " << discriment_zero(equa.la, equa.lb) << endl;
	}
	else if (degre > 2)
		cout << "Polynomial degree: 3" << endl << "The polynomial degree is"
		"stricly greater than 2, I can't solve." << endl;
}
