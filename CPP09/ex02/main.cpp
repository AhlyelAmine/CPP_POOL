#include "PmergeMe.hpp"

void sort(std::pair<int, int> &pair)
{
    if (pair.first < pair.second)
    {
        int tmp = pair.first;
        pair.first = pair.second;
        pair.second = tmp;
    }
}

int Jacobsthal(int n)
{
    // base case
    if (n == 0)
        return 0;
 
    // base case
    if (n == 1)
        return 1;
 
    // recursive step.
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        PmergeMe merge;
        std::pair <int, int> pair;
        for (int i = 1; i < argc; i++)
        {
            std::string arg(argv[i]);

            //check is integer needed
            
            if (arg.find_first_not_of("0123456789") != std::string::npos)
            {
                std::cerr << "2Error\n";
                return 0;
            }
            if (i % 2)
            {
                pair.first = atoi(argv[i]);
                pair.second = -1;
            }
            else
            {
                pair.second = atoi(argv[i]);
                merge.vector.push_back(pair);
            }
        }
        // if (pair.second == -1)
        //     merge.vector.push_back(pair);
        for (size_t i = 0; i < merge.vector.size(); i++)
        {
            sort(merge.vector[i]);
            // if (merge.vector[i].second != -1)
            // {
            //     merge.vector_a.push_back(merge.vector[i].first);
            //     merge.vector_b.push_back(merge.vector[i].second);
            // }
        }
        std::sort(merge.vector.begin(), merge.vector.end());
        for (size_t i = 0; i < merge.vector.size(); i++)
        {
            if (i)
                merge.vector_b.push_back(merge.vector[i].second);
            else
                merge.vector_a.push_back(merge.vector[i].second);
            merge.vector_a.push_back(merge.vector[i].first);
        }
        for (std::pair<int, int> &a :merge.vector)
        {
            std::cout << " [" << a.first << ", " << a.second << "] ";
        }
        std::cout << "\na :";
        for (size_t i = 0; i < merge.vector_a.size(); i++)
        {
            std::cout << " " << merge.vector_a[i] << ", ";
        }
        std::cout << "\nb :";
        for (size_t i = 0; i < merge.vector_b.size(); i++)
        {
            std::cout << " " << merge.vector_b[i] << ", ";
        }
        std::vector<int> jacobSequence;
        size_t index = 3;
        int lastJacob = 1;
        int target = merge.vector_b.size() + 1;
        while (true)
        {
            int jacobNum = Jacobsthal(index);
            jacobSequence.push_back(jacobNum);
            for (int j = jacobNum - 1; j != lastJacob; j--)
            {
                jacobSequence.push_back(j);
                if (jacobSequence.back() == target)
                    break ;
            }
            if (std::find(jacobSequence.begin(), jacobSequence.end(), target) != jacobSequence.end())
                    break ;
            lastJacob = jacobNum;
            index++;
        }
        int i = 0;
        while (!merge.vector_b.empty())
        {
            int comp, start = 0, end = merge.vector_a.size() - 1, target = merge.vector_b[jacobSequence[i] - 2];
            while (start <= end)
            {
                comp = start + (end - start) / 2;
                if (target <= merge.vector_a[comp])
                {
                    if (!comp || target >= merge.vector_a[comp - 1])
                    {
                std::cout << "a\n";
                        i++;
                        merge.vector_a.insert(merge.vector_a.begin() + comp, {target});
                        break ;
                    }
                }
                start += 1; 
            }
        }
        std::cout << " jacobSequence :";
        for (size_t i=0; i < jacobSequence.size(); i++)
        {
            std::cout << " " << jacobSequence[i] << ", ";
        }
        return 0;
    }
    std::cerr << "1Error\n";
    return 0;
}
