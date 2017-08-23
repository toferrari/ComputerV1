/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:00:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/23 13:16:12 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int		nb1;
	int		nb2;

    cout << "nombre 1 ?" << endl;
	cin >> nb1;
	// cin.ignore();
	cout << "nombre 2" << endl;
	cin >> nb2;
	// getline(cin, nom);
	cout << "resultat addition = " << nb1 + nb2 << endl;
    return 0;
}
