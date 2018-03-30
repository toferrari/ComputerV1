/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2018/03/30 17:01:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

int		error(string str)
{
	cout << str << endl;
	return (0);
}

// std::vector<std::string>& explode(const std::string& str, std::vector<std::string> &tokens)
// {
//     std::istringstream split(str); // flux d'exatraction sur un std::string
//     for (std::string each; std::getline(split, each, ' '); tokens.push_back(each));
//     return tokens;
// }

string	split_spaces(string str)
{
	int	i;

	i = -1;
	while ((i = str.find(' ')) != -1)
		str.erase(i, 1);
	return (str);
}

int		parse(string str, Equation equa)
{
	int					i;
	// vector<std::string>	tab;

	i = -1;
	str = split_spaces(str);
	while (str[++i])
	{
		if (str[i] == '=')
			equa.up_equal();
		else
			equa.extrac(&str);
	}
	i = str.find("p");
	string test = "salut ";
	test += '!';
	test.erase(4,1);
	cout << str << endl;
	cout << i << endl;
	// equa.ecrire();
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
			return (error("bad bonus"));
	parse(argv[1], equa);
	return (0);

}
