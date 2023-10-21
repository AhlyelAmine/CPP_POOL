#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("🔪");
        HumanA bob("saba", club);
        bob.attack();
        club.setType("🗡");
        bob.attack();
    }
    {
        Weapon club = Weapon("🔪");

        HumanB jim("lucifer");
        jim.setWeapon(club);
        jim.attack();
        club.setType("📎");
        jim.attack();
    }

    return 0;
}