/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Randomizer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:32 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 17:24:10 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RANDOMIZER_HPP
# define RANDOMIZER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);



#endif