/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:46:23 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 17:28:01 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
	std::string title = "";
	std::cout << "Enter the name of the horde: ";
	std::getline(std::cin, title);
	int N;
	do {
		
		std::cout << "Enter the number of zombies (max:100): ";
		std::cin >> N;
		if (N < 0 || !(N >= 0 && N <= 100) || std::cin.fail())
			std::cout << "Invaild Number" << std::endl;
	} while (N < 0 || !(N >= 0 && N <= 100));
	Zombie *zombie = zombieHorde(N, title);
	delete [] zombie;
	return (0);
}