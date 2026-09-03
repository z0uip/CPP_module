#include "Span.hpp"

int main()
{
    // --- Test de base (exemple du sujet) ---
    std::cout << "--- Test de base ---" << std::endl;
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // attendu: 2
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;   // attendu: 14

    // --- Test d'exception : dépasser N éléments ---
    std::cout << "\n--- Test overflow ---" << std::endl;
    try
    {
        sp.addNumber(42); // sp est déjà plein (N=5)
        std::cout << "Erreur: aucune exception levée !" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapee: " << e.what() << std::endl;
    }

    // --- Test d'exception : span sur container vide ---
    std::cout << "\n--- Test span sur Span vide ---" << std::endl;
    Span empty(5);
    try
    {
        empty.shortestSpan();
        std::cout << "Erreur: aucune exception levee !" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapee: " << e.what() << std::endl;
    }

    // --- Test d'exception : span avec un seul element ---
    std::cout << "\n--- Test span avec un seul element ---" << std::endl;
    Span one(5);
    one.addNumber(42);
    try
    {
        one.longestSpan();
        std::cout << "Erreur: aucune exception levee !" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception attrapee: " << e.what() << std::endl;
    }

    // --- Test avec un range d'iterateurs ---
    std::cout << "\n--- Test addRange (range d'iterateurs) ---" << std::endl;
    std::list<int> vec;
    vec.push_back(1);
    vec.push_back(50);
    vec.push_back(25);
    vec.push_back(100);

    Span spRange(10);
    spRange.addRange(vec.begin(), vec.end());

    std::cout << "shortestSpan: " << spRange.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << spRange.longestSpan() << std::endl;

    // --- Test avec 10 000 nombres ---
    std::cout << "\n--- Test avec 10 000 nombres ---" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Span bigSpan(10000);
    for (int i = 0; i < 10000; i++)
        bigSpan.addNumber(std::rand());

    std::cout << "shortestSpan: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << bigSpan.longestSpan() << std::endl;

    return 0;
}