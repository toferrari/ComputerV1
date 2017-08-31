/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:05:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/31 18:32:31 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_HPP
# define COMPUTERV1_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <vector>

using namespace std;

class Equation
{
public:

	Equation();
	int			check_nb(string str, Equation equa, int lr);
	int			check_time(string str, Equation equa, int lr);
	int			check_x(string str, Equation equa, int lr);
	int			check_transition(string str, Equation equa, int lr);
	int			parse(Equation equa, string str);
	int			discriment(int a, int b, int c);
	int			unknow(int a, int b);
	int			discriment_r1(int a, int b, int disc);
	int			discriment_r2(int a, int b, int disc);
	int			discriment_zero(int a, int b);
	void		ecrire(Equation test, int degre);

private:

	double		la;
	double		lb;
	double		lc;
	double		ra;
	double		rb;
	double		rc;
	int			signe;
	int			degre;
	int			rdegre;
	int			ldegre;
	int			disc;
	int			r1;
	int			r2;
};

#endif
