/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:12:40 by amireid           #+#    #+#             */
/*   Updated: 2025/01/11 19:34:10 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <pthread.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
//#include <sys/sysctl.h> //this only works on mac
#include <string>
#include <sstream>
#include <iomanip>
# define RED "\033[1;31m"
# define RESET "\033[0m"

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& );
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& );

    std::vector<int> sortVectorWithThreads(std::vector<int>& nums);
    
private:
    size_t getOptimalThreadCount(size_t dataSize);
    //int getNumCPU();
    std::vector<int> generateJacobsthalSequence(int maxPendCount);
    static void* sortPairsSection(void* arg);
};

#endif