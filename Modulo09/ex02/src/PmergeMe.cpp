/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:14:09 by amireid           #+#    #+#             */
/*   Updated: 2025/01/11 19:40:50 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
// this solution is based on the Ford-Johnson algorithm but enhanced with multi threading
// and the Jacobsthal sequence for efficient merging and std::sort 
// maybe i could use as well std::lower_bound (binary search)for enhancing the result. (done)
// This struct is used to pass data to the thread function
struct ThreadData {
    std::vector<std::pair<int, int> >* pairs;
    size_t startIdx;
    size_t endIdx;
};

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& ) {}
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& ) {return *this;}

//Jacobsthal sequence: a number is equal the sum of (the previous number + 2 * the one before the previous number)
std::vector<int> PmergeMe::generateJacobsthalSequence(int maxPendCount) {
    std::vector<int> sequence;
    int a = 1, b = 3;
    while (b < maxPendCount) {
        sequence.push_back(b);
        int temp = b;
        b = a + 2 * b;
        a = temp;
    }
    return sequence;
}

// This function is getting the number of CPU cores. please note that this is only for unix based systems..NOT WINDOWS!
// int PmergeMe::getNumCPU() {
//     int numCores = 1;
//     #ifdef _SC_NPROCESSORS_ONLN
//         numCores = sysconf(_SC_NPROCESSORS_ONLN);
//     #elif defined(_WIN32)
//         SYSTEM_INFO sysinfo;
//         GetSystemInfo(&sysinfo);
//         numCores = sysinfo.dwNumberOfProcessors;
//     #endif
//     return numCores;
// }

// This is to optimize the number of threads used based on the data size..
// for example if the data is small, we use one thread..etc
size_t PmergeMe::getOptimalThreadCount(size_t dataSize) {
    //int numCores = getNumCPU();
    //size_t maxThreads = numCores * 2;

    if (dataSize < 1000) {
        return 1;
    } else if (dataSize < 5000) {
        return 2;
    } else {
        return 3;
    }
}

// comparison for sorting pairs based on the second element
struct FordJohnsonPairComparator {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second < b.second;
    }
};

// thread routine 
void* PmergeMe::sortPairsSection(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    std::sort(data->pairs->begin() + data->startIdx, data->pairs->begin() + data->endIdx, FordJohnsonPairComparator());
    return NULL;
}
// The algorithm itself
std::vector<int> PmergeMe::sortVectorWithThreads(std::vector<int>& nums) {
    std::vector<int> numbers = nums;
    std::vector<std::pair<int, int> > pairs;
    bool hasOddNumber = numbers.size() % 2 != 0;
    int oddNumber = numbers[numbers.size() - 1];
    if (hasOddNumber) { numbers.pop_back(); }

    // Create pairs
    for (size_t i = 0; i < numbers.size(); i += 2) {
        int n1 = numbers[i], n2 = numbers[i + 1];
        pairs.push_back(std::make_pair(std::min(n1, n2), std::max(n1, n2)));
    }

    // get the optimal number of threads
    size_t numThreads = getOptimalThreadCount(numbers.size());
    size_t sectionSize = pairs.size() / numThreads;
    pthread_t threads[numThreads];
    ThreadData threadData[numThreads];

    // split the pairs into sections and launch threads
    for (size_t i = 0; i < numThreads; ++i) {
        size_t startIdx = i * sectionSize;
        size_t endIdx = (i == numThreads - 1) ? pairs.size() : (i + 1) * sectionSize;
        threadData[i].pairs = &pairs;
        threadData[i].startIdx = startIdx;
        threadData[i].endIdx = endIdx;
        pthread_create(&threads[i], NULL, sortPairsSection, (void*)&threadData[i]);
    }
    for (size_t i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Merge sorted pairs
    std::vector<int> S;
    std::vector<int> pend;
    // push the larger elements to S and the small ones to pend
    for (size_t i = 0; i < pairs.size(); ++i) {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    // Insert the first pending element to the beginning of S
    S.insert(S.begin(), pend[0]);
    pend.erase(pend.begin());
    
    // Generate the Jacobsthal sequence for efficient merging
    std::vector<int> jbInsertionSequence = generateJacobsthalSequence(pend.size());

    // Merge the remaining pending elements into S
    size_t pendIdx = 0;
    bool lastInsertWasJacobsthal = false;
    while (pendIdx < pend.size()) {
        int val;
        if (!jbInsertionSequence.empty() && !lastInsertWasJacobsthal) {
            val = pend[jbInsertionSequence[0] - 1];
            jbInsertionSequence.erase(jbInsertionSequence.begin());
            lastInsertWasJacobsthal = true;
        } else {
            val = pend[pendIdx];
            pendIdx++;
            lastInsertWasJacobsthal = false;
        }
        // Binary search for val insertion
        std::vector<int>::iterator insertPos = std::lower_bound(S.begin(), S.end(), val);
        S.insert(insertPos, val);
    }

    // If there was an odd element, insert it
    if (hasOddNumber) {
        std::vector<int>::iterator insertPos = std::lower_bound(S.begin(), S.end(), oddNumber);
        S.insert(insertPos, oddNumber);
    }
    return S;
}

