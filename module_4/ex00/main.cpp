#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal*			animal		= new Animal();
    Animal*			chien		= new Dog();
    Animal*			chat		= new Cat();
    WrongAnimal*	wrongAnimal	= new WrongCat();

    std::cout << std::endl;

    std::cout << animal->getType() << std::endl;
    std::cout << chien->getType() << std::endl;
    std::cout << chat->getType() << std::endl;
    std::cout << wrongAnimal->getType() << std::endl;

    std::cout << std::endl;

    animal->makeSound();
    chien->makeSound();
    chat->makeSound();
    wrongAnimal->makeSound();

	std::cout << std::endl;

    delete animal;
    delete chien;
    delete chat;
    delete wrongAnimal;

    return 0;
}