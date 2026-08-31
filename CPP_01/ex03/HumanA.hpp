#include "HumanB.hpp"
#include <string>
#include <iostream>

class HumanA
{
    private :

    std::string name;
    Weapon &weapon;

    public :

    void attack(void);
    HumanA(std::string name, Weapon &weapon);
};