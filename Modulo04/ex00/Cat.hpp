/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:05 by aeid              #+#    #+#             */
/*   Updated: 2024/11/06 19:21:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
  
  public:
    Cat();
    ~Cat();
    Cat(const Cat & src);
    Cat & operator=(const Cat & src);
    void makeSound() const;
};

# endif