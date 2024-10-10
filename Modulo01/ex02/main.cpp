/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:33:30 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 17:44:02 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <new>
# include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN 🧟";
	std::string* brainPtr = &brain;
	std::string& brainRef = brain;

	std::cout << "String Variable ADDRESS: " << &brain << std::endl;
	std::cout << "String Pointer ADDRESS: " << brainPtr << std::endl;
	std::cout << "String Reference ADDRESS: " << &brainRef << std::endl;
	std::cout << std::endl;
	std::cout << "Pointer ADDRESS itself: " << &brainPtr << std::endl;
	std::cout << "Reference ADDRESS itself: " << &brainRef << std::endl;
	std::cout << std::endl;
	std::cout << "String Variable VALUE: " << brain << std::endl;
	std::cout << "String Pointer VALUE: " << *brainPtr << std::endl;
	std::cout << "String Reference VALUE: " << brainRef << std::endl;
	
	return (0);
}