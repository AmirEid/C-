/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:29:28 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 15:26:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal & src);
        WrongAnimal & operator=(const WrongAnimal & src);
        virtual void makeSound() const;
        void setType(const std::string type);
        std::string getType() const;

    protected:
        std::string _type;
};

# endif