#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <cstdlib>
# include <algorithm>
# include <list>


template <typename T, typename Y>
class PmergeMe
{
    public:
        // struct s_container vec;
        // struct s_container lst;

        Y _glb;
        T                  _mainPortion;
        T                  _tmpPortion;
        T                  jacobSequence;

        size_t size;

        // std::vector <int> vector;
        // std::vector <std::pair<int, int> > vector;
        // std::vector <int> vector_a;
        // std::vector <int> vector_b;
// 
        // std::list <std::pair<int, int> > list;
        // std::list <int> list_a;
        // std::list <int> list_b;
// 

        // 
        void read_input(int argc, char const *argv[])
        {
    	    std::pair <int, int> pair;	
    	    for (int i = 1; i < argc; i++	)
    	    {	
    	        std::string arg(argv[i]);	
    	        //check is integer needed	
	
    	        if (arg.find_first_not_of("0123456789") != std::string::npos)
    	        {
					// std::cerr << "2Error\n";
					throw "Error\n";
    	        }
    	        if (i % 2)
    	        {
					pair.first = atoi(argv[i]);
					pair.second = -1;
    	        }
    	        else
    	        {
					pair.second = atoi(argv[i]);
					this->_glb.push_back(pair);
    	        }
    	    }
        }

        void sortPairs()
        {
            for (size_t i = 0; i < this->_glb.size(); i++)
            {
                    sort(this->_glb[i]);
            }

                std::sort(this->_glb.begin(), this->_glb.end());
        }
        void fillContainers()
        {
            for (size_t i = 0; i < this->_glb.size(); i++)
            {
                    if (i)
                    this->_tmpPortion.push_back(this->_glb[i].second);
                    else
                    this->_mainPortion.push_back(this->_glb[i].second);
                    this->_mainPortion.push_back(this->_glb[i].first);
            }
            this->size = this->_tmpPortion.size() + 1;
            // for (std::pair<int, int> &a :merge.vector)
            // {
                    // std::cout << " [" << a.first << ", " << a.second << "] ";
            // }
            // std::cout << "\na :";
            // for (size_t i = 0; i < this->_mainPortion.size(); i++)
            // {
                    // std::cout << " " << this->_mainPortion[i] << ", ";
            // }
            // std::cout << "\nb :";
            // for (size_t i = 0; i < this->_tmpPortion.size(); i++)
            // {
                    // std::cout << " " << this->_tmpPortion[i] << ", ";
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
					if (jacobSequence.back() == this->size)
					{
							break ;
					}
					}
					if (std::find(jacobSequence.begin(), jacobSequence.end(), this->size) != jacobSequence.end())
							break ;
					lastJacob = jacobNum;
					index++;
			}
			// std::cout << "jacob seq : ";
			// for (size_t i = 0; i < jacobSequence.size(); i++)
			// {
			//     std::cout << " " << jacobSequence[i] << ", ";
			// }
			// std::cout << "\n";
        }
        void binaryInert()
		{
			size_t i = 0;
		
			while (i < jacobSequence.size())
			{
				int end = this->_mainPortion.size() - 1;
				int start = end / 2;
				if (jacobSequence[i] - 1 > (int)this->_tmpPortion.size())
				{
					i++;
					continue ;
				}
				int target = this->_tmpPortion[jacobSequence[i] - 2];
				while (start < end)
				{
					if (target <= this->_mainPortion[start] && (!start || target >= this->_mainPortion[start - 1]))
					{
						this->_mainPortion.insert(this->_mainPortion.begin() + start, {target});
						// this->_tmpPortion.erase(this->_tmpPortion.begin() + jacobSequence[i] - 2);
						break ;
					}
					if (target < this->_mainPortion[start])
					{
						end = start;
						start /= 2;
					}
					else if (target > this->_mainPortion[start])
					{
						start = start + ((end - start) / 2);
					}
				}
				i++;
			}
		
			// std::cout << "\n a :";
			for (size_t i=0; i < this->_mainPortion.size(); i++)
			{
				std::cout << " " << this->_mainPortion[i] << ", ";
			}
		}

        PmergeMe(){};
        ~PmergeMe(){};
};

#endif
