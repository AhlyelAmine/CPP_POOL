#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <cstdlib>
# include <algorithm>
# include <list>
# include <deque>

int Jacobsthal(int n);
void sort(std::pair<int, int> &pair);

template <typename T, typename Y>
class PmergeMe
{
	PmergeMe const & operator=(PmergeMe const &pmergeMe){(void)pmergeMe;return (*this);}
	PmergeMe(PmergeMe const &pmergeMe);
	Y			_glb;
	T			_tmpPortion;
	T			jacobSequence;
	int			odd;
	size_t		size;

    public:
		T			_mainPortion;

        // void read_input(int argc, char const *argv[]);
        // void sortPairs();
        // void fillContainers();
        // void makeJacobSeq();
        // void binaryInert();

        PmergeMe(){};
        ~PmergeMe(){};

        void read_input(int argc, char const *argv[])
        {
			std::pair <int, int> pair;
			odd = -1;
			for (int i = 1; i < argc; i++)
			{	
				std::string arg(argv[i]);	
				
				if (arg.find_first_not_of("0123456789") != std::string::npos)
					throw "Error\n";

				if (i % 2)
				{
					pair.first = atoi(argv[i]);
					pair.second = -1;
				}
				else
				{
					pair.second = atoi(argv[i]);
					_glb.push_back(pair);
				}
			}
			if (pair.second == -1)
				odd = pair.first;
				// _glb.push_back(pair);
        }

        void sortPairs()
        {
            for (size_t i = 0; i < _glb.size(); i++)
            {
                    sort(_glb[i]);
            }

                std::sort(_glb.begin(), _glb.end());
        }

        void fillContainers()
        {
            for (size_t i = 0; i < _glb.size(); i++)
            {
                    if (i)
						_tmpPortion.push_back(_glb[i].second);
                    else
						_mainPortion.push_back(_glb[i].second);
                    _mainPortion.push_back(_glb[i].first);
            }
            size = _tmpPortion.size() + 1;
            for (std::pair<int, int> &a :_glb)
            {
                    std::cout << " [" << a.first << ", " << a.second << "] ";
            }
            std::cout << "\na :";
            for (size_t i = 0; i < _mainPortion.size(); i++)
            {
                    std::cout << " " << _mainPortion[i] << ", ";
            }
            std::cout << "\nb :";
            for (size_t i = 0; i < _tmpPortion.size(); i++)
            {
                    std::cout << " " << _tmpPortion[i] << ", ";
            }
        }

        void makeJacobSeq()
        {
			size_t  index = 3;
			int     lastJacob = 1;

			while (true)
			{
					int jacobNum = Jacobsthal(index);
					if ((size_t)jacobNum <= size)
						jacobSequence.push_back(jacobNum);
					for (int j = jacobNum - 1; j != lastJacob; j--)
					{
						if ((size_t)jacobNum <= size)
							jacobSequence.push_back(j);
						if ((size_t)jacobSequence.back() == size)
						{
								break ;
						}
					}
					if (std::find(jacobSequence.begin(), jacobSequence.end(), size) != jacobSequence.end())
							break ;
					lastJacob = jacobNum;
					index++;
			}
			// std::cout << "jacob seq : ";
			// for (size_t i = 0; i < jacobSequence.size(); i++)
			// {
			// 	std::cout << " " << jacobSequence[i] << ", ";
			// }
			// std::cout << "\n";
        }

        void binaryInert2(int target)
		{
			int end = _mainPortion.size() - 1;
			int start = 0;
			while (start <= end)
			{
				int mid = (start + end) / 2;
				if (target <= _mainPortion[mid] && (!mid || target >= _mainPortion[mid - 1]))
				{
					_mainPortion.insert(_mainPortion.begin() + mid, target);
					break ;
				}
				else if (target >= _mainPortion[mid] && (size_t)mid == _mainPortion.size() - 1)
				{
					_mainPortion.insert(_mainPortion.begin() + mid, target);
					break ;
				}
				if (target < _mainPortion[mid])
					end = mid - 1;
				else if (target > _mainPortion[mid])
					start = mid + 1;
			}
		}
// int binary{
//  int left = 0;
//     int right = _data.size() - 1;

//     while (left <= right) {
//         int middle = (left + right) / 2;

//         if (_data[middle] == target) {
//             return middle;
//         } else if (_data[middle] < target) {
//             left = middle + 1;
//         } else {
//             right = middle - 1;
//         }
//     }

//     return left;}

        void binaryInert()
		{
			size_t i = 0;
		
			while (i < jacobSequence.size())
			{
				std::cout << odd;
				// int end = _mainPortion.size() - 1;
				// int start = end / 2;
				int target = _tmpPortion[jacobSequence[i] - 2];
				binaryInert2(target);
				i++;
			}

			// if (_mainPortion.front() == -1)
			// {
			// 	_mainPortion.erase(_mainPortion.begin());
			// }
			// std::cout << "\n a :";
			// for (size_t i=0; i < _mainPortion.size(); i++)
			// {
			// 	std::cout << " " << _mainPortion[i] << ", ";
			// }
			// std::cout << "\n";
		}
};

#endif
