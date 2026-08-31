#include <iostream>
#include <string>
#include "iter.hpp"

// Fonction "normale" qui affiche un int (const reference)
void printInt(const int &n) {
    std::cout << n << " ";
}

// Fonction qui modifie l'élément (non-const reference)
void doubleInt(int &n) {
    n *= 2;
}

// Fonction template, utilisable avec n'importe quel type affichable
template <typename T>
void printElem(const T &elem) {
    std::cout << elem << " ";
}

int main(void) {
    // Test 1 : tableau d'int, fonction qui affiche (const ref)
    int tab[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(tab) / sizeof(tab[0]);

    std::cout << "Tableau initial : ";
    iter(tab, len, printInt);
    std::cout << std::endl;

    // Test 2 : la même fonction iter, mais avec une fonction qui modifie (non-const ref)
    iter(tab, len, doubleInt);
    std::cout << "Apres doubleInt : ";
    iter(tab, len, printInt);
    std::cout << std::endl;

    // Test 3 : tableau de std::string, avec une fonction template instanciee
    std::string words[] = {"salut", "les", "amis"};
    size_t wlen = sizeof(words) / sizeof(words[0]);

    std::cout << "Tableau de strings : ";
    iter(words, wlen, printElem<std::string>);
    std::cout << std::endl;

    return 0;
}