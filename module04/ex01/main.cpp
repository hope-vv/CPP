#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"
#include "headers/Brain.hpp"
#include "headers/WrongCat.hpp"

// int main()
// {
//     Animal *animal[4];
//     int i = 0;
//     while (i < 2){
//         animal[i] = new Dog();
//         i++;
//     }
//     while (i < 4){
//         animal[i] = new Cat();
//         i++;
//     }
//     i = 0;
//     while (i < 4) {
//         std::cout << animal[i]->getType() << " says: ";
//         animal[i]->makeSound();
//         i++;
//     }
//     i = 0;
//     while (i < 4){
//         delete animal[i];
//         i++;
//     }
// }

int main()
{
    Cat original;
    original.getBrain()->setIdea(0, "Catch birds.");
    original.getBrain()->setIdea(1, "Sleep on keyboard.");

    std::cout << "Original Cat Idea 0: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original Cat Idea 1: " << original.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Using Animal* for polymorphism ---\n";
    Animal *animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    // for (int i = 2; i < 4; i++)
    //     animals[i] = new Cat();
    animals[2] = new Cat(original);
    animals[3] = new Cat();
    for (int i = 0; i < 4; i++) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}
