/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:35:10 by amireid           #+#    #+#             */
/*   Updated: 2024/12/26 15:45:16 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./inc/easyfind.hpp"
# include <vector>
# include <list>
# include <deque>
# include <set>

int main () {
    //try the exception version
    
    // {
    //     try {
    //         std::vector<int> vec;
    //         vec.push_back(1);
    //         vec.push_back(2);
    //         vec.push_back(3);
    //         vec.push_back(4);
    //         easyfind(vec, 3);
    //         easyfind(vec, 7);
    //     } catch (const ExceptionNotFound &e) {
    //         std::cerr << e.what() << std::endl;
    //     }
    // }
    
    //try the return error version
    std::cout << "Vector :" << std::endl;
    {
        std::vector<int> vec;
        for (int i = 0; i < 10 ; i++)
            vec.push_back(i);
        vec.push_back(4);
        vec.push_back(-1);
        for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
            std::cout << *i << " ";
        std::cout << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 3);
        if (it != vec.end())
            std::cout << "Element: " << *it << " Found in position: " << std::distance(vec.begin(), it) << std::endl;
    }
    std::cout << "List :" << std::endl;
    {
        std::list<int> list;
        for (int i = 0; i < 10 ; i++)
            list.push_back(i);
        list.push_back(4);
        list.push_back(-1);
        for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
            std::cout << *i << " ";
        std::cout << std::endl;
        std::list<int>::iterator it = easyfind(list, 3); 
        if (it != list.end())
            std::cout << "Element: " << *it << " Found in position: " << std::distance(list.begin(), it) << std::endl;
    }
    std::cout << "Set :" << std::endl;
    {
        std::set<int> list;
        for (int i = 0; i < 10 ; i++)
            list.insert(i);
        list.insert(4);
        list.insert(-1);
        for (std::set<int>::iterator i = list.begin(); i != list.end(); i++)
            std::cout << *i << " ";
        std::cout << std::endl;
        std::set<int>::iterator it = easyfind(list, 3);
        if (it != list.end())
            std::cout << "Element: " << *it << " Found in position: " << std::distance(list.begin(), it) << std::endl;
    }
    std::cout << "Deque :" << std::endl;
    {
        std::deque<int> list;
        for (int i = 0; i < 10 ; i++)
            list.push_back(i);
        list.push_back(4);
        list.push_back(-1);
        for (std::deque<int>::iterator i = list.begin(); i != list.end(); i++)
            std::cout << *i << " ";
        std::cout << std::endl;
        std::deque<int>::iterator it = easyfind(list, 3);
        if (it != list.end())
            std::cout << "Element: " << *it << " Found in position: " << std::distance(list.begin(), it) << std::endl;
    }
}