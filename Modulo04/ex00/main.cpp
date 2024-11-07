/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:04:52 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 15:32:26 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main ()
{
    {
        const Animal *animal = new Animal();
        const Animal animal1 = Animal();
        const Animal animal2 = Animal("ciao");
        const Animal *dog = new Dog();
        const Animal animal3 = Dog();
        const Animal animal5 = Animal(*animal);
        delete animal;
        delete dog;
    }
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    {
        const Dog* dog = new Dog();
        const Dog dog1 = Dog(*dog);
        delete dog;
    }
       {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
    }
}