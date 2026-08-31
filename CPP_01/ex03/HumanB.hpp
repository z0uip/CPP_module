#include <string>
#include "Weapon.hpp"
#include <iostream>


class HumanB
{
    private :

    std::string name;
    Weapon *weapon;

    public :

    void    attack(void);
    HumanB(std::string name);
    void    setWeapon(Weapon &weapon);
};