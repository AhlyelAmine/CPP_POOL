
// void sort(std::pair<int, int> &pair)
// {
//     if (pair.first < pair.second)
//     {
//         int tmp = pair.first;
//         pair.first = pair.second;
//         pair.second = tmp;
//     }
// }

// int Jacobsthal(int n)
// {
//     // base case
//     if (n == 0)
//         return 0;
 
//     // base case
//     if (n == 1)
//         return 1;
 
//     // recursive step.
//     return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
// }
// void read_input(PmergeMe &merge, int argc, char const *argv[])
// {
//     std::pair <int, int> pair;
//     for (int i = 1; i < argc; i++)
//     {
//         std::string arg(argv[i]);

//         //check is integer needed
        
//         if (arg.find_first_not_of("0123456789") != std::string::npos)
//         {
//             // std::cerr << "2Error\n";
//             throw "Error\n";
//         }
//         if (i % 2)
//         {
//             pair.first = atoi(argv[i]);
//             pair.second = -1;
//         }
//         else
//         {
//             pair.second = atoi(argv[i]);
//             merge.vector.push_back(pair);
//         }
//     }
// }

// void    sortPairs(PmergeMe &merge)
// {
//     for (size_t i = 0; i < merge.vector.size(); i++)
//     {
//         sort(merge.vector[i]);
//     }

//     std::sort(merge.vector.begin(), merge.vector.end());
// }


// void    fillVecs(PmergeMe &merge)
// {
//     for (size_t i = 0; i < merge.vector.size(); i++)
//     {
//         if (i)
//             merge.vector_b.push_back(merge.vector[i].second);
//         else
//             merge.vector_a.push_back(merge.vector[i].second);
//         merge.vector_a.push_back(merge.vector[i].first);
//     }

//     // for (std::pair<int, int> &a :merge.vector)
//     // {
//         // std::cout << " [" << a.first << ", " << a.second << "] ";
//     // }
//     // std::cout << "\na :";
//     // for (size_t i = 0; i < merge.vector_a.size(); i++)
//     // {
//         // std::cout << " " << merge.vector_a[i] << ", ";
//     // }
//     // std::cout << "\nb :";
//     // for (size_t i = 0; i < merge.vector_b.size(); i++)
//     // {
//         // std::cout << " " << merge.vector_b[i] << ", ";
//     // }
// }

// void    makeJacobSeq(std::vector<int> &jacobSequence, PmergeMe merge)
// {
//     size_t index = 3;
//     int lastJacob = 1;
//     int target = merge.vector_b.size() + 1;

//     while (true)
//     {
//         int jacobNum = Jacobsthal(index);
//         jacobSequence.push_back(jacobNum);
//         for (int j = jacobNum - 1; j != lastJacob; j--)
//         {

//             jacobSequence.push_back(j);
//             if (jacobSequence.back() == target)
//             {
//                 break ;
//             }
//         }
//         if (std::find(jacobSequence.begin(), jacobSequence.end(), target) != jacobSequence.end())
//                 break ;
//         lastJacob = jacobNum;
//         index++;
//     }
        
//     // std::cout << "jacob seq : ";
//     // for (size_t i = 0; i < jacobSequence.size(); i++)
//     // {
//     //     std::cout << " " << jacobSequence[i] << ", ";
//     // }
//     // std::cout << "\n";
// }

// void    binaryInert(PmergeMe &merge, std::vector<int> jacobSequence)
// {
//     size_t i = 0;

//     while (i < jacobSequence.size())
//     {
//         int end = merge.vector_a.size() - 1;
//         int start = end / 2;
//         if (jacobSequence[i] - 1 > (int)merge.vector_b.size())
//         {
//             i++;
//             continue ;
//         }
//         int target = merge.vector_b[jacobSequence[i] - 2];
//         (void)target;
//         while (start < end)
//         {
//             if (target <= merge.vector_a[start] && (!start || target >= merge.vector_a[start - 1]))
//             {
//                 merge.vector_a.insert(merge.vector_a.begin() + start, {target});
//                 // merge.vector_b.erase(merge.vector_b.begin() + jacobSequence[i] - 2);
//                 break ;
//             }
//             if (target < merge.vector_a[start])
//             {
//                 end = start;
//                 start /= 2;
//             }
//             else if (target > merge.vector_a[start])
//             {
//                 start = start + ((end - start) / 2);
//             }
//         }
//             i++;
//     }

//     // std::cout << "\n a :";
//     for (size_t i=0; i < merge.vector_a.size(); i++)
//     {
//         std::cout << " " << merge.vector_a[i] << ", ";
//     }
// }

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        // std::vector<int> jacobSequence;
        PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vector;
        PmergeMe<std::list<int>, std::list<std::pair<int, int> > > list;

        try
        {
            vector.read_input(argc, argv);
            list.read_input(argc, argv);
        }
        catch(const char * e)
        {
            std::cerr << e << '\n';
        }

        std::list<int> a;

        vector.sortPairs();
        vector.fillContainers();
        vector.binaryInert();

        list.sortPairs();
        list.fillContainers();
        list.binaryInert();
// 
        // sortPairs(merge);
// 
        // fillVecs(merge);
// 
        // makeJacobSeq(jacobSequence, merge);
// 
        // binaryInert(merge, jacobSequence);

        return 0;
    }
    std::cerr << "1Error\n";
    return 0;
}
