#include "bigint.hpp"

int main() {
    // Création de bigints
    bigint num1(242);
    bigint num2(10);
    bigint num3;
    bigint num4("123");

    std::cout << "Test des constructeurs:" << std::endl;
    std::cout << "num1 = "; num1.print();
    std::cout << "num2 = "; num2.print();
    std::cout << "num3 = "; num3.print();
    std::cout << "num4 = "; num4.print();
    std::cout << std::endl;

    // Test des opérateurs arithmétiques
    std::cout << "Tests arithmétiques:" << std::endl;
    bigint result = num1 + num2;
    std::cout << "num1 + num2 = "; result.print();

    num3 = num1;
    num3 += num2;
    std::cout << "num3 += num2: "; num3.print();
    std::cout << std::endl;

    // Test des comparaisons
    std::cout << "Tests de comparaison:" << std::endl;
    std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
    std::cout << "num2 < num1: " << (num2 < num1) << std::endl;
    std::cout << std::endl;

    // Test du décalage
    std::cout << "Tests de décalage:" << std::endl;
    bigint shifted = num2 << 1;
    std::cout << "num2 << 1 = "; shifted.print();
    shifted = num2 << 3;
    std::cout << "num2 << 3 = "; shifted.print();

    return 0;
}
