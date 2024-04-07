#include "PmergeMe.hpp"
#include <time.h>

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vector;
        PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > deque;
        clock_t start_vec, end_vec, start_deq, end_deq;

        try
        {
            vector.read_input(argc, argv);
            deque.read_input(argc, argv);

            std::cout << "Before:\t";
            for (int i = 1; i < argc; i++) {
                std::cout << argv[i] << " ";
            }

            start_vec = clock();
            vector.sortPairs();
            vector.fillContainers();
            vector.makeJacobSeq();
            vector.binaryInert();
            end_vec = clock();

            start_deq = clock();
            deque.sortPairs();
            deque.fillContainers();
            deque.makeJacobSeq();
            deque.binaryInert();
            end_deq = clock();

            std::cout << "\nAfter:\t";
            for (size_t i = 0; i < vector._mainPortion.size(); i++){
                std::cout << vector._mainPortion[i] << " ";
            }
            std::cout << "\nTime to process a range of 5 elements with std::vector : "<< ((double)(end_vec - start_vec)) << " us";
            std::cout << "\nTime to process a range of 5 elements with std::vector : "<< ((double)(end_deq - start_deq)) << " us";
        }
        catch(const char * e)
        {
            std::cerr << e << " e\n";
            return (1);
        }
        return (0);
    }
    std::cerr << "Error\n";
    return (1);
}
