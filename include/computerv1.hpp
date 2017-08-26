/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:05:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/26 17:39:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_HPP
# define COMPUTERV1_HPP

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Equation
{
public:

	Equation();
	int			discriment(int a, int b, int c);
	int			unknow(int a, int b);
	int			discriment_r1(int a, int b, int disc);
	int			discriment_r2(int a, int b, int disc);
	int			discriment_zero(int a, int b);
	void		ecrire(Equation test, int degre);

private:

	int			la;
	int			lb;
	int			lc;
	int			ra;
	int			rb;
	int			rc;
	int			degre;
	int			disc;
	int			r1;
	int			r2;
};

#endif
