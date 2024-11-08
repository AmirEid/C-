/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:49:02 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 20:10:35 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define RESET   "\033[0m"
# define CYAN    "\033[36m"
# define BRIGHT_RED  "\033[91m"
# define S_CONSTRUCTOR "String param, constructor called "
# define C_CONSTRUCTOR "Copier constructor called "
# define DCONSTRUCTOR "Decostructor called "
# define CURECONST "Cure constructor called "
# define CUREDECONT "Cure decostructor called " 
# define CURECOPYCONST "Cure copy constructor called "
# define ICECONST "Ice constructor called "
# define ICEDECON "Ice decostructor called "
# define ICECPY "Ice copy constructor called "
# define CHARCONST "Character constructor called "
# define CHARDECON "Character decostructor called "
# define CHARCPY "Character copy constructor called "

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria & src);
        AMateria & operator=(const AMateria & src);
        virtual ~AMateria();
        void printer(std::string text, std::string type) const;

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0; //This one should return a new instance of the same type
        //if you clone an ice materia, you will get a new ice materia.
        virtual void use(ICharacter& target); 
        //this member function will display: • Ice: "* shoots an ice bolt at <name> *"
        //• Cure: "* heals <name>’s wounds *"
        //<name> is the name of the character passed as a parameter.
};

# endif