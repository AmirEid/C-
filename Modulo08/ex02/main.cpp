/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:14:34 by amireid           #+#    #+#             */
/*   Updated: 2024/12/27 17:21:07 by amireid          ###   ########.fr       */
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
    // 5 should be removed and show only 17
    mstack.pop();
    //size should be 1
    std::cout << mstack.size() << std::endl;
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