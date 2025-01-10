/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:14:34 by amireid           #+#    #+#             */
/*   Updated: 2025/01/10 17:55:49 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./inc/MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    //stack should be 5 then 17
    std::cout << mstack.top() << std::endl;
    std::cout << "----" << std::endl;
    // 5 should be removed and show only 17
    mstack.pop();
    //size should be 1
    std::cout << mstack.size() << std::endl;
    std::cout << "----" << std::endl;
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int> s(mstack); 
    return 0;
}