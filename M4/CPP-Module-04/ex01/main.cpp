#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << "\n--- Array of Animals ---\n" << std::endl;

	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
	
	for(int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n--- Deep Copy Test ---\n" << std::endl;
	
	Dog basic;
	basic.getBrain()->setIdea(0, "Woof!");
	{
		Dog tmp = basic;
		std::cout << "Original idea: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea: " << tmp.getBrain()->getIdea(0) << std::endl;
	}

	return 0;
}