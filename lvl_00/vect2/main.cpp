#include "vect2.hpp"

int main() {
    // Test des constructeurs
    vect2 a;
    vect2 b(8, 9);
    vect2 c(3, 3);

    std::cout << "Constructeurs :" << std::endl;
    std::cout << "a = "; a.print();
    std::cout << "b = "; b.print();
    std::cout << "c = "; c.print();
    std::cout << std::endl;

    // Test operator[]
    std::cout << "Accès aux composants :" << std::endl;
    std::cout << "b[0] = " << b[0] << ", b[1] = " << b[1] << std::endl;
    std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << std::endl;
    c[0] = 7;
    std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << std::endl;
    std::cout << std::endl;

    // Test des opérations avec scalaires
    std::cout << "Opérations avec scalaires :" << std::endl;
    a = vect2(3, 3);
    std::cout << "a = "; a.print();
    vect2 tmp = a * 2;
    std::cout << "a * 2 = "; tmp.print();
    tmp = b + 2;
    std::cout << "b + 2 = "; tmp.print();
    std::cout << std::endl;

    // Test des opérations avec vecteurs
    std::cout << "Opérations entre vecteurs :" << std::endl;
    tmp = a + b;
    std::cout << "a + b = "; tmp.print();
    tmp = a * b;
    std::cout << "a * b = "; tmp.print();
    std::cout << std::endl;

    // Test des opérateurs d'incrémentation
    std::cout << "Incrémentation :" << std::endl;
    std::cout << "a++ = "; (a++).print();
    std::cout << "++a = "; (++a).print();
    std::cout << "a-- = "; (a--).print();
    std::cout << "--a = "; (--a).print();
    std::cout << std::endl;

    // Test des comparaisons
    std::cout << "Comparaisons :" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << std::endl;

    // Test des opérations d'assignation
    std::cout << "Opérations d'assignation :" << std::endl;
    a += 2;
    std::cout << "a += 2: "; a.print();
    a *= 3;
    std::cout << "a *= 3: "; a.print();
    a += b;
    std::cout << "a += b: "; a.print();
    a *= b;
    std::cout << "a *= b: "; a.print();

    return 0;
}
