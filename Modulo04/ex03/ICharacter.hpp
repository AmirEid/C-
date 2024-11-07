/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:52:18 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 22:13:24 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"


// {} this in the destructor means that this destructor does not do anything while destroyed.
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

# endif