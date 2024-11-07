/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:04:52 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 18:02:29 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"

int main ()
{
    Dog basic;
    {
        Dog tmp = basic;
    }
    std::cout << std::endl;
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        delete j;
        delete i;
    }
    std::cout << std::endl;
    {
        const Animal *animal[6] = { new Dog(), new Dog(), new Cat(), new Cat()};
        for (int i = 0; i < 4; i++)
            delete animal[i];
    }
}