/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:42:05 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 21:46:39 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {

    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal & src);
        Animal & operator=(const Animal & src);
        virtual void makeSound() const = 0;
        void setType(const std::string type);
        std::string getType() const ;
        
    protected:
    std::string _type;

};

# endif