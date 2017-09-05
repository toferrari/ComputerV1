/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/05 17:35:56 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

int		error()
{
	cout << "not well formatted !!" << endl;
	return (0);
}

std::vector<std::string>& explode(const std::string& str, std::vector<std::string> &tokens)
{
    std::istringstream split(str); // flux d'exatraction sur un std::string
    for (std::string each; std::getline(split, each, ' '); tokens.push_back(each));
    return tokens;
}

int		main(int argc, char **argv)
{
	Equation equa;

	switch (argc)
	{
		case 1 :
			cout << "no equation enter !!!" << endl;
			break;
		case 2 :
		{
			int					i;
			int					j;
			vector<std::string>	tab;

			i = -1;
			tab = explode(argv[1], tab);
			while (tab[++i][0])
			{
				j = 0;
				while (tab[i][j] && tab[i][j] != '=')
				{
					if (!equa.check_nb(tab[i], 1) || !equa.check_star(tab[++i], 1, &i)
					|| !equa.check_x(tab[++i], 1, &i) || !equa.check_transition(tab[++i], 1))
						return (error());
					if (tab[i][j] && tab[i][j] != '=')
						i++;
				}
				if (tab[i][0] == '\0')
					return (0);
				while (tab[++i][0])
				{
					if (!equa.check_nb(tab[i], 2) || !equa.check_star(tab[++i], 2, &i)
					|| !equa.check_x(tab[++i], 2, &i))
						return (error());
					// cout << tab[i] << endl;
				}
			}
			// equa.calcul();
			equa.ecrire();
		}
			break;
		case 3 :
			cout << "too many argument !!!!" << endl;
			break;
	}
	return 0;
}
