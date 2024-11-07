/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:05 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 17:07:30 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
  
  public:
    Cat();
    ~Cat();
    Cat(const Cat & src);
    Cat & operator=(const Cat & src);
    void makeSound() const;
  
  private:
    Brain *_brain;
};

# endif