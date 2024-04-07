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
            // for (std::pair<int, int> &a :_glb)
            // {
            //         std::cout << " [" << a.first << ", " << a.second << "] ";
            // }
            // std::cout << "\na :";
            // for (size_t i = 0; i < _mainPortion.size(); i++)
            // {
            //         std::cout << " " << _mainPortion[i] << ", ";
            // }
            // std::cout << "\nb :";
            // for (size_t i = 0; i < _tmpPortion.size(); i++)
            // {
            //         std::cout << " " << _tmpPortion[i] << ", ";
            // }
        }

        void makeJacobSeq()
        {
			size_t  index = 3;
			int     lastJacob = 1;

			while (true)
			{
					int jacobNum = Jacobsthal(index);
					jacobSequence.push_back(jacobNum);
					for (int j = jacobNum - 1; j != lastJacob; j--)
					{
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

        void binaryInert()
		{
			size_t i = 0;
		
			while (i < jacobSequence.size() || odd != -1)
			{
				std::cout << odd;
				int end = _mainPortion.size() - 1;
				int start = end / 2;
				if (jacobSequence[i] - 1 > (int)_tmpPortion.size())
				{
					i++;
					continue ;
				}
				int target;
				if (i < jacobSequence.size())
					target = _tmpPortion[jacobSequence[i] - 2];
				else if (odd != -1)
				{
					std::cout << "odd : " << odd << "\n";
					target = odd;
					odd = -1;
				}
				while (start < end)
				{
					std::cout << "a\n";
					std::cout << "target : " << target << "; start : " << start << "; _mainPortion[start] : " << _mainPortion[start] << "; _mainPortion.size() : " << _mainPortion.size() << "; _mainPortion.back() : " << _mainPortion.back() << "\n";
					// if (target > _mainPortion[start] && (size_t)(start + 1) == _mainPortion.size())
					// {
					// 	_mainPortion.insert(_mainPortion.begin() + start, {target});
					// 	break ;
					// }
					if (target <= _mainPortion[start] && (!start && target >= _mainPortion[start - 1]))
					{

						_mainPortion.insert(_mainPortion.begin() + start, {target});
						break ;
					}
					if (target >= _mainPortion[start] && ((size_t)(start + 1) < _mainPortion.size() && target <= _mainPortion[start + 1]))
					{

						_mainPortion.insert(_mainPortion.begin() + start + 1, {target});
						break ;
					}
					if (target < _mainPortion[start])
					{
						end = start;
						start /= 2;
					}
					else if (target > _mainPortion[start])
					{
						start = start + ((end - start) / 2);
					}
				}
				i++;
			}

			if (_mainPortion.front() == -1)
			{
				_mainPortion.erase(_mainPortion.begin());
			}
			// std::cout << "\n a :";
			// for (size_t i=0; i < _mainPortion.size(); i++)
			// {
			// 	std::cout << " " << _mainPortion[i] << ", ";
			// }
			// std::cout << "\n";
		}
};

#endif
