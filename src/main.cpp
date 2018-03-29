/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2018/03/29 16:17:58 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

int		error(string str)
{
	cout << str << endl;
	return (0);
}

std::vector<std::string>& explode(const std::string& str, std::vector<std::string> &tokens)
{
    std::istringstream split(str); // flux d'exatraction sur un std::string
    for (std::string each; std::getline(split, each, ' '); tokens.push_back(each));
    return tokens;
}

int		parse(string str, Equation equa)
{
	int					i;
	int					j;
	vector<std::string>	tab;

	i = -1;
	tab = explode(str, tab);
	while (tab[++i][0])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '=')
		{
			if (!equa.check_nb(tab[i], 1) || !equa.check_star(tab[++i], &i)
			|| !equa.check_x(tab[++i], 1, &i) || !equa.check_transition(tab[++i], 1))
				return (error("not well formatted"));
			if (tab[i][j] && tab[i][j] != '=')
				i++;
		}
		if (tab[i][0] == '\0')
			return (0);
		while (tab[++i][0])
		{
			if (!equa.check_nb(tab[i], 2) || !equa.check_star(tab[++i], &i)
			|| !equa.check_x(tab[++i], 2, &i)|| !equa.check_transition(tab[++i], 2))
				return (error("not well formatted"));
		}
	}
	equa.reduc();
	equa.ecrire();
	return (1);
}

int		main(int argc, char **argv)
{
	Equation	equa;
	int			i;
	string		reg;
	// regex		reg;

	i = 1;
	reg = string(INPUT_EQUA) + string(INPUT_EQUAL) + string(INPUT_EQUA);
	if (argc == 1 || (argc >= 2 && argv[1][0] == '\0'))
		return (error("no equation enter !!!"));
	if (!regex_match(argv[1], regex(reg)) ||
		regex_match(argv[1], regex(INPUT_WRONG)))
		cout << "wrong" << endl;
	else
		cout << "ok" << endl;

	// cout << boolalpha << ret << endl;
	// while (++i < argc)
	// 	if (!equa.bonus(argv[i]))
	// 		return (error("bad bonus"));
	// parse(argv[1], equa);
	return (0);

}
