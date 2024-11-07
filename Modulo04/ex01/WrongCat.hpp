/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:07:54 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 15:28:09 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat & src);
        WrongCat & operator=(const WrongCat & src);
        void makeSound() const ;
};

# endif