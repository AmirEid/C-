/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:59:06 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 23:12:45 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
    
    public:
        Cure();
        ~Cure();
        Cure(const Cure & src);
        Cure & operator=(const Cure & src);
        AMateria* clone() const;
        void use(ICharacter & target);
};

# endif