#include <string>
#include <iostream>

class Weapon
{
    private :

    std::string type;

    public :

    Weapon(std::string);
    std::string getType(void);
    void setType(std::string type);
};
