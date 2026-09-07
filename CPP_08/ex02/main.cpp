#include "MutantStack.hpp"
#include <list>
int main()
{
    // --- Test de base (exemple du sujet) ---
    std::cout << "--- Test de base ---" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl; // attendu: 17

    mstack.pop();

    std::cout << "size: " << mstack.size() << std::endl; // attendu: 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // --- Conversion en std::stack classique ---
    std::cout << "\n--- Test conversion std::stack ---" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "s.top(): " << s.top() << std::endl; // doit correspondre au top de mstack
    std::cout << "s.size(): " << s.size() << std::endl;

    // --- Comparaison avec une list pour vérifier la cohérence ---
    std::cout << "\n--- Comparaison avec std::list ---" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    l.pop_back();
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);

    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // --- Test iterator vide ---
    std::cout << "\n--- Test stack vide ---" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "begin == end ? " << (emptyStack.begin() == emptyStack.end()) << std::endl; // attendu: 1

    // --- Test avec un autre type (double) ---
    std::cout << "\n--- Test avec double ---" << std::endl;
    MutantStack<double> dstack;
    dstack.push(1.5);
    dstack.push(2.7);
    MutantStack<double>::iterator dit = dstack.begin();
    MutantStack<double>::iterator dite = dstack.end();
    while (dit != dite)
    {
        std::cout << *dit << std::endl;
        ++dit;
    }

    return 0;
}