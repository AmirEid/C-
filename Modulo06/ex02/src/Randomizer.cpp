/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Randomizer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:22 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 17:32:01 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Randomizer.hpp"

Base *generate(void) {
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;
    if (random == 0) {
        std::cout << "Instance of A created" << std::endl;
        return new A();
        //this is like Base *a = new A(); return a;
    }
    else if (random == 1) {
        std::cout << "Instance of B created" << std::endl;
        return new B();
    }
    else {
        std::cout << "Instance of C created" << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "Base is pointing to an instance of A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Base is pointing to an instance of B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Base is pointing to an instance of C" << std::endl;
    else
        std::cout << "Base is pointing to an unknown instance" << std::endl;
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "Base is pointing to an instance of A" << std::endl;
    } catch(...) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "Base is pointing to an instance of B" << std::endl;
        } catch (...) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "Base is pointing to an instance of C" << std::endl;
            } catch (...) {
                std::cout << "Base is pointing to an unknown instance" << std::endl;
            }
        }
    }
}