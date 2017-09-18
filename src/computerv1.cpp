/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/18 17:26:16 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

Equation::Equation()
{
	la = 0;
	lb = 0;
	lc = 0;
	ra = 0;
	rb = 0;
	rc = 0;
	disc = 0;
	degre = -1;
	ldegre = -1;
	rdegre = -1;
	signe = 1;
	show = 0;
	r1 = 0;
	r2 = 0;
}

int			Equation::bonus(string str)
{
	if (str[0] == '-' && str[1] == 's')
		show = 1;
	return (1);
}

int			Equation::check_nb(string str, int lr)
{
	int		i;

	i = -1;
	if (lr == 1)
		ldegre += 1;
	else
		rdegre +=1;
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (!isdigit(str[i]) && str[i] != '.')
			return (0);
	tmp = atof(str.c_str()) * signe;
	signe = 1;
	return (1);
}

int			Equation::check_star(string str, int *i)
{
	if (((ldegre == 0 || rdegre == 0) && (str[0] == '+' || str[0] == '-' || str[0] == '=')) ||
	(rdegre == 0 && str[0] == '\0'))
	{
		(*i)--;
		return (1);
	}
	if (str[0] != '*' || str[1])
		return (0);
	return (1);
}

int			Equation::check_x(string str, int lr, int *i)
{
	int deg;

	deg = (lr == 1) ? ldegre : rdegre;
	if ((deg == 0 && (str[0] == '+' || str[0] == '-' || str[0] == '=')) ||
	(rdegre == 0 && str[0] == '\0'))
		(*i)--;
	else if (str[0] != 'X' || str[1] != '^' || !isdigit(str[2]) || str[3])
		if (!(str[0] == 'X' && str[1] == '\0'))
			return (0);
	if (lr == 1)
	{
		if (ldegre == 0)
			lc = tmp;
		else if (ldegre == 1)
			lb = tmp;
		else if (ldegre == 2)
			la = tmp;
	}
	else
	{
		if (rdegre == 0)
			rc = tmp;
		else if (rdegre == 1)
			rb = tmp;
		else if (rdegre == 2)
			ra = tmp;
	}
	return (1);
}

int			Equation::check_transition(string str, int lr)
{
	if (lr == 2 && str[0] == '\0')
		return (1);
	if (str[0] == '=' && str[1] == '\0')
		return (1);
	else if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
	{
		if (str[0] == '-')
			signe = -1;
		return (1);
	}
	return (0);
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
	return ((-b - sqrt(disc)) / (2 * a));
}

double			Equation::discriment_r2(double a, double b, double disc)
{
	if (show == 1)
	{
		printf("\033[4m-b +√(Δ)\033[0m\n	2a\n");
		printf("x2 = \033[4m-(%f) +√(%f)\033[0m\n	2 * %f\n", b, disc, a);
		printf("x2 = ");
	}
	return ((-b + sqrt(disc)) / (2 * a));
}

double			Equation::discriment_zero(double a, double b)
{
	return ((-b) / (2 * a));
}

void			Equation::reduc()
{
	la -= ra;
	lb -= rb;
	lc -= rc;
}

void			Equation::prt_nb(int degre)
{
	double tmp;

	cout << "Reduced form: ";
	if (degre == 2 && la != 0)
		cout << la << " * X^2 ";
	if (degre >= 1 && lb != 0)
	{
		if (lb > 0 && degre == 2)
			cout << "+ ";
		else if (lb < 0 && degre == 2)
			cout << "- ";
		tmp = ABS(lb);
		cout << lb << " * X";
	}
	if (lc != 0)
	{
		if (lc > 0)
			cout << " + ";
		else
			cout << " - ";
		tmp = ABS(lc);
		cout << lc << " = 0" << endl;
	}
}

void			Equation::ecrire()
{
	degre = (ldegre > rdegre) ? ldegre : rdegre;
	if (degre > 0)
		prt_nb(degre);
	if ((degre == 1 && lb != 0) || (degre == 2 && la == 0))
		cout << "Polynomial degree: 1" << endl << "The solution is:" << endl,
		cout << "x = " << unknow(lc , lb) << endl;
	else if (degre == 2)
	{
		cout << "Polynomial degree: 2" << endl << "The solution is:" << endl;
		disc = discriment(la , lb , lc);
		if (disc > 0)
			cout << "Discriminant is strictly positive, the two solutions are:",
			cout << endl << "x1 = " << discriment_r1(la , lb , disc),
			cout << "\n\n" << "x2 = " << discriment_r2(la , lb , disc),
			cout << endl;
		else if (disc == 0)
			cout << "Discriminant equals zero, the only one solution is :",
			cout << endl << "x = " << discriment_zero(la , lb) << endl;
		else if (disc < 0)
			cout << "Discriminant is strictly negative, no solution !!" << endl;
	}
	else if (degre > 2)
		cout << "Polynomial degree: 3" << endl << "The polynomial degree is"
		"stricly greater than 2, I can't solve." << endl;
	else
		cout << "lol???" << endl;
}
