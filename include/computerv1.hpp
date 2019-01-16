/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:05:46 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/16 13:44:09 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_HPP
# define COMPUTERV1_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <regex>

# define ABS(x) (x < 0) ? -x : x
# define INPUT_EQUA "([+-]?(([0-9]+)(\\.[0-9]+)?((\\*?)([xX](\\^[0-9]+)?)?)|[Xx](\\^[0-9])?))+"
# define INPUT_EQUAL "(=)"
# define INPUT_WRONG "(([-+])?([0-9]+)(\\.[0-9]+)?)(=)(([-+])?([0-9]+)(\\.[0-9]+)?)"

using namespace std;

double				ft_sqrt(double nb);
bool				isnum(string str);

class Equation
{
public:

	Equation();
	void			degres(string str);
	void			number(float nb, int deg);
	void			up_equal();
	double			discriment();
	double			unknow();
	double			discriment_r1();
	double			discriment_r2();
	double			discriment_zero();
	void			complex_r1(double racine_disc_reduce);
	void			complex_r2(double racine_disc_reduce);
	void			execpt();
	void			reducted();
	int				bonus(string str);
	void			ecrire();
	void			complex_reduce();
	int				pgcd(double x, double y);
	int				reduce_racine();

private:

	double		a;
	double		b;
	double		c;
	int			equal;
	float		signe;
	int			degre;
	int			show;
	double		disc;
	double		r1;
	double		r2;
};

#endif
