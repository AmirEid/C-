/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:58:19 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 19:35:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
    
    public:
        Ice();
        ~Ice();
        Ice(const Ice & src);
        Ice & operator=(const Ice & src);
        AMateria* clone() const;
        void use(ICharacter & target);
};

# endif