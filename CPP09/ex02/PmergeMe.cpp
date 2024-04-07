#include "PmergeMe.hpp"

int Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void sort(std::pair<int, int> &pair)
{
    if (pair.first < pair.second)
    {
        int tmp = pair.first;
        pair.first = pair.second;
        pair.second = tmp;
    }
}
