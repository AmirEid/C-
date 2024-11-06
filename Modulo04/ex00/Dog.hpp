/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:09:10 by aeid              #+#    #+#             */
/*   Updated: 2024/11/06 18:13:11 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

  public:
    Dog();
    ~Dog();
    Dog(const Dog & src);
    Dog & operator=(const Dog & src);
    void makeSound() const;
};

# endif