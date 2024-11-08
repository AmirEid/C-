#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include "colors.h"

class AMateria {
protected:
    std::string _type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria & src);
    AMateria & operator=(const AMateria & src);

    void printer(Color color, std::string text) const;

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0; //This one should return a new instance of the same type
    virtual void use(ICharacter& target); 
};

#endif // AMATERIA_H
