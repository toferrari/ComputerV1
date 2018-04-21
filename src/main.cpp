/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2018/04/21 17:29:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

int		error(string str)
{
	cout << str << endl;
	return (0);
}

/* Split en vecteur */

std::vector<std::string>&	explode(const std::string& str, std::vector<std::string> &tokens)
{
	std::istringstream split(str); // flux d'exatraction sur un string
	for (std::string each; std::getline(split, each, ' '); tokens.push_back(each));
	return tokens;
}

/* Ajoute un espace pour séparer les inconnus */

string	space(string str)
{
	string	tmp;
	string	ret;

	tmp = "+-=";
	for (string::iterator i = str.begin(); i != str.end(); i++)
	{
		if (ret[ret.length() - 1] != ' ')
			ret += (tmp.find(*i) != -1 && i != str.begin()) ? " " : "";
		ret += *i;
		ret += (*i == '=') ? " " : "";
	}
	return (ret);
}

int		parse(string str, Equation equa)
{
	int					i;
	vector<std::string>	tab;

	i = -1;
	/* Supprime les espaces */
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	str = space(str);
	tab = explode(str, tab);
	while (tab[++i][0])
	{
		if (tab[i].find("=") != -1)
			equa.up_equal();
		else
			equa.degres(tab[i]);
	}
	equa.ecrire();
	return (1);
}

int		main(int argc, char **argv)
{
	Equation	equa;
	int			i;
	string		reg;

	i = 1;
	reg = string(INPUT_EQUA) + string(INPUT_EQUAL) + string(INPUT_EQUA);
	if (argc == 1 || (argc >= 2 && argv[1][0] == '\0'))
		return (error("No equation enter !!!"));
	if (!regex_match(argv[1], regex(reg)) ||
		regex_match(argv[1],  regex(INPUT_WRONG)))
		return (error("Not well Formatted"));
	while (++i < argc)
		if (!equa.bonus(argv[i]))
			return (error("bad bonus\n<equation> [-s]"));
	parse(argv[1], equa);
	return (0);

}
