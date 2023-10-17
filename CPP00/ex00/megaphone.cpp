#include <iostream>

int main(int ac , char **av)
{
    if (ac == 1)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str(av[i]);
            for (size_t j = 0; j < str.size(); j++)
                std::cout << (char)std::toupper(str[j]);
        }
        std::cout<<std::endl;
    }
}
