/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:45:43 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 20:49:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  
  private:
    AMateria* _template[4];

  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource & src);
    MateriaSource & operator=(const MateriaSource & src);
    
    void learnMateria(AMateria*) = 0;
    AMateria* createMateria(std::string const & type) = 0;
    
};

# endif