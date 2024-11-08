/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:05:10 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 20:20:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {

    private:
        std::string _name;
        AMateria* _inventory[4];
    
    public:
        Character(const std::string & name);
        Character(const Character & src);
        Character & operator=(const Character & src);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter & target);
        void printer(std::string text, std::string type) const;
};

# endif