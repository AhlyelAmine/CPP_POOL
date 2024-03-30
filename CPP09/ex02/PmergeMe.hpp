#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <cstdlib>
#include<algorithm>

class PmergeMe
{
    public:
        // std::vector <int> vector;
        std::vector <std::pair<int, int> > vector;
        std::vector <int> vector_a;
        std::vector <int> vector_b;

        PmergeMe(){};
        ~PmergeMe(){};
};

#endif
