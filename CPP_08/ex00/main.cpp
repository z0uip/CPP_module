#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    // --- Test avec un vector ---
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(15);
    vec.push_back(16);
    vec.push_back(23);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 15);
        std::cout << "vector: found " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "vector: " << e.what() << std::endl;
    }

    // --- Test valeur absente ---
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "vector: found " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "vector: " << e.what() << std::endl;
    }

    // --- Test avec une list ---
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "list: found " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "list: " << e.what() << std::endl;
    }

    // --- Test avec une deque ---
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(dq, 300);
        std::cout << "deque: found " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "deque: " << e.what() << std::endl;
    }

    return 0;
}