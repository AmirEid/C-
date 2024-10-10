/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:46:23 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 16:21:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Zombie1 is on the Heap");
	zombie->announce();
	randomChump("Zombie2 is on the Stack");
	delete zombie;
	return (0);
}