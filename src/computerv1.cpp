/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2018/04/18 18:45:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

Equation::Equation()
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
	disc = 0.0;
	degre = 0;
	signe = 1.0;
	show = 0;
	r1 = 0;
	r2 = 0;
}

int			Equation::bonus(string str)
{
	if (str.find("-s") != -1)
		show = 1;
	return (1);
}

void			Equation::number(float nb, int deg)
{
	degre = (degre < deg) ? deg : degre;
	if (deg == 2)
		a += signe * nb;
	else if (deg == 1)
		b += signe * nb;
	else
		c += signe * nb;
}

void			Equation::degres(string str)
{
	int	i;
	int j;
	int	tmp;

	if ((i = str.find("X^")) != -1)
		number(atof(str.c_str()), atoi(&str[i + 2]));
		// degre = (degre >= (tmp = atoi(&str[i + 2]))) ? degre : tmp;
	else if ((j = str.find("X")) != -1)
		number(atof(str.c_str()), 1);
	else
		number(atof(str.c_str()), 0);
}

void			Equation::up_equal()
{
	signe = -1.0;
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
		printf("x1 = \033[4m-(%.2f) -√(%.2f)\033[0m\n	2 * %.2f\n", b, disc, a);
		printf("x1 = ");
	}
	return ((-b - ft_sqrt(disc)) / (2 * a));
}

double			Equation::discriment_r2(double a, double b, double disc)
{
	if (show == 1)
	{
		printf("\033[4m-b +√(Δ)\033[0m\n	2a\n");
		printf("x2 = \033[4m-(%.2f) +√(%.2f)\033[0m\n	2 * %.2f\n", b, disc, a);
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
}
