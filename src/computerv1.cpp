/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2018/03/30 17:01:00 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

Equation::Equation()
{
	a = 0;
	b = 0;
	c = 0;
	equal = 0;
	disc = 0;
	degre = -1;
	signe = 1;
	show = 0;
	r1 = 0;
	r2 = 0;
}

int			Equation::bonus(string str)
{
	if (str.find("-s"))
		show = 1;
	return (1);
}

void			Equation::extrac(string *str)
{
	int		tmp;
	int		len;

	tmp = atoi((*str).c_str());
	len = to_string(tmp).length();
	len += ((*str).find("-") == 0 && tmp == 0) ? 1 : 0;
	(*str).erase(0, len);
	cout << *str << endl;
}

void			Equation::up_equal()
{
	equal++;
}

double			Equation::discriment(double a, double b, double c)
{
	double tmp;

	tmp = ABS(4 * a * c);
	if (show)
	{
		cout << "Δ = b² - 4ac" << endl;
		cout << "Δ = " << b << "² - 4 * " << a << " * " << c << endl;
		if ((4 * a * c) < 0)
			cout << "Δ = " << b * b << " + " << tmp << endl;
		else
			cout << "Δ = " << b * b << " - " << 4 * a * c << endl;
		cout << "Δ = " << (b * b) - (4 * a * c) << endl;
	}
	return ((b * b) - (4 * a * c));
}

double			Equation::unknow(double c, double b)
{
	return ((-c) / b);
}

double			Equation::discriment_r1(double a, double b, double disc)
{
	if (show == 1)
	{
		printf("\033[4m-b -√(Δ)\033[0m\n	2a\n");
		printf("x1 = \033[4m-(%f) -√(%f)\033[0m\n	2 * %f\n", b, disc, a);
		printf("x1 = ");
	}
	return ((-b - ft_sqrt(disc)) / (2 * a));
}

double			Equation::discriment_r2(double a, double b, double disc)
{
	if (show == 1)
	{
		printf("\033[4m-b +√(Δ)\033[0m\n	2a\n");
		printf("x2 = \033[4m-(%f) +√(%f)\033[0m\n	2 * %f\n", b, disc, a);
		printf("x2 = ");
	}
	return ((-b + ft_sqrt(disc)) / (2 * a));
}

double			Equation::discriment_zero(double a, double b)
{
	return ((-b) / (2 * a));
}

void			Equation::ecrire()
{
	cout << degre << endl;
	if ((degre == 1 && b != 0) || (degre == 2 && a == 0))
		cout << "Polynomial degree: 1\nThe solution is:\n",
		cout << "x = " << unknow(c , b) << endl;
	else if (degre == 2)
	{
		cout << "Polynomial degree: 2" << endl << "The solution is:" << endl;
		disc = discriment(a , b , c);
		if (disc > 0)
			cout << "Discriminant is strictly positive, the two solutions are:",
			cout << endl << "x1 = " << discriment_r1(a , b , disc),
			cout << "\n\n" << "x2 = " << discriment_r2(a , b , disc) << endl;
		else if (disc == 0)
			cout << "Discriminant equals zero, the only one solution is :",
			cout << endl << "x = " << discriment_zero(a , b) << endl;
		else if (disc < 0)
			cout << "Discriminant is strictly negative, no solution !!\n";
	}
	else if (degre > 2)
		cout << "Polynomial degree: 3\nThe polynomial degree is"
		"stricly greater than 2, I can't solve.\n";
	else
		cout << "lol???\n";
}
