#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("🔪");
        std::cout << "weapon : " << &club << std::endl;
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("⚔️");
        bob.attack();
    }
    {
        Weapon club = Weapon("🔪");
        HumanB jim("Jim");
        // jim.setWeapon(club);
        jim.attack();
        club.setType("⚔️");
        jim.attack();
    }
    return 0;
}