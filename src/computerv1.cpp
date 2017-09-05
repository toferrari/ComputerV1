/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/05 18:16:22 by tferrari         ###   ########.fr       */
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
	r1 = 0;
	r2 = 0;
}

int			Equation::check_nb(string str, int lr)
{
	int		i;

	i = -1;
	if (lr == 1)
		ldegre += 1;
	else
		rdegre +=1;
	while (str[++i])
		if (!isdigit(str[i]) && str[i] != '.')
			return (0);
	tmp = atof(str.c_str()) * signe;
	signe = 1;
	return (1);
}

int			Equation::check_star(string str, int lr, int *i)
{
	if (((ldegre == 0 || rdegre == 0) && (str[0] == '+' || str[0] == '-')) ||
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
	if ((deg == 0 && (str[0] == '+' || str[0] == '-')) ||
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
	// cout << str[2] << endl;
	return (1);
}

int			Equation::check_transition(string str, int lr)
{
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
	return ((b * b) - (4 * a * c));
}

double			Equation::unknow(double c, double b)
{
	printf ("a = %f, b = %f, res = %f\n", c, -b, (-b) / c);
	return ((-b) / c);
}

double			Equation::discriment_r1(double a, double b, double disc)
{
	return ((-b - sqrt(disc)) / (2 * a));
}

double			Equation::discriment_r2(double a, double b, double disc)
{
	return ((-b + sqrt(disc)) / (2 * a));
}

double			Equation::discriment_zero(double a, double b)
{
	return ((-b) / (2 * a));
}

void		Equation::ecrire()
{
	degre = (ldegre > rdegre) ? ldegre : rdegre;
	if (degre == 0)
		cout << "lol???" << endl;
	else if (degre == 1)
		cout << "Polynomial degree: 1" << endl << "The solution is:" << endl,
		cout << "x = " << unknow(lc - rc, lb - rb) << endl;
	else if (degre == 2)
	{
		cout << "Polynomial degree: 2" << endl << "The solution is:" << endl;
		disc = discriment(la - ra, lb - rb, lc - rc);
		if (disc > 0)
			cout << "Discriminant is strictly positive, the two solutions are:",
			cout << endl << "x1 = " << discriment_r1(la - ra, lb - rb, disc),
			cout << endl << "x2 = " << discriment_r2(la - ra, lb - rb, disc),
			cout << endl;
		else if (disc == 0)
			cout << "Discriminant equals zero, the only one solution is :",
			cout << endl << "x = " << discriment_zero(la - ra, lb - rb) << endl;
		else if (disc < 0)
			cout << "Discriminant is strictly negative, no solution !!" << endl;
	}
	else if (degre > 2)
		cout << "Polynomial degree: 3" << endl << "The polynomial degree is"
		"stricly greater than 2, I can't solve." << endl;
}
