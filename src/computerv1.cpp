/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/31 18:37:26 by tferrari         ###   ########.fr       */
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
	degre = 0;
	ldegre = -1;
	rdegre = -1;
	signe = 1;
	r1 = 0;
	r2 = 0;
}

std::vector<std::string>& explode(const std::string& str, std::vector<std::string> &tokens)
{
    std::istringstream split(str); // flux d'exatraction sur un std::string
    for (std::string each; std::getline(split, each, ' '); tokens.push_back(each));
    return tokens;
}

int			Equation::check_nb(string str, Equation equa, int lr)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!isdigit(str[i]) && str[i] != '.')
			return (0);
	if (lr == 1)
	{
		
	}
	return (1);
}

int			Equation::check_time(string str, Equation equa, int lr)
{
	cout << str << endl;

	return (1);
}

int			Equation::check_x(string str, Equation equa, int lr)
{
	int deg;

	cout << str << endl;
	deg = (lr == 1) ? equa.ldegre : equa.rdegre;
	// if (str[0] != 'X')
	// 	return (0);
	return (1);
}

int			Equation::check_transition(string str, Equation equa, int lr)
{
	cout << str << endl;
	if (str[0] == '=' && str[1] == '\0')
		return (1);
	else if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (1);
	return (0);
}

int			Equation::parse(Equation equa, string str)
{
	int	i;
	int	j;

	i = -1;
	std::vector<std::string> tab;
	tab = explode(str, tab);
	while (tab[++i][0])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '=')
		{
			if (!equa.check_nb(tab[i], equa, 1) || !check_time(tab[++i], equa, 1)
			|| !check_x(tab[++i], equa, 1) || !check_transition(tab[++i], equa, 1))
				return (0);
			i++;
		}
		if (tab[i][0] == '\0')
			return (0);
		while (tab[++i][0])
		{
			if (!equa.check_nb(tab[i], equa, 2) || !check_time(tab[++i], equa, 2)
			|| !check_x(tab[++i], equa, 2) || !check_transition(tab[++i], equa, 2))
				return (0);
		}
		equa.degre = (equa.ldegre > equa.rdegre) ? equa.ldegre : equa.rdegre;
		equa.ecrire(equa, equa.degre);
	}
	return (1);
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

	if (degre == 0)
		cout << "lol???" << endl;
	else if (degre == 1)
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
		else if (disc < 0)
			cout << "Discriminant is strictly negative, no solution !!" << endl;
	}
	else if (degre > 2)
		cout << "Polynomial degree: 3" << endl << "The polynomial degree is"
		"stricly greater than 2, I can't solve." << endl;
}
