#include <iostream>
#include "Animal.h"

int main(int argc, char* argv[]) {
  std::cout << "Hello World!" << std::endl;
  
  std::string name = "Piero";
  NoFly fStrategy;
  RunFast rStrategy;
  EatLots eStrategy;
  Animal genericAnimal(name, fStrategy, rStrategy, eStrategy);
  std::cout << "Animal fly: " << genericAnimal.fly() << std::endl;
  std::cout << "Animal run: " << genericAnimal.run() << std::endl;
  std::cout << "Animal eat: " << genericAnimal.eat() << std::endl;

  NoFly catFly;
  RunSlow catRun;
  EatLittle catEat;
  Cat testCat("Fuffy", catFly, catRun, catEat);
  std::cout << testCat.getName() << std::endl;
  std::cout << "Cat Weight: " << testCat.getWeight() << std::endl;
  testCat.setWeight(88.8);
  std::cout << "New cat weight: " << testCat.getWeight() << std::endl;
  std::cout << "Cat fly: " << testCat.fly() << std::endl;
  std::cout << "Cat run: " << testCat.run() << std::endl;
  std::cout << "Cat eat: " << testCat.eat() << std::endl;
  std::cout << "Cat value: " << testCat.getCatValue() << std::endl;

  std::cout << "Number of animals: " << Animal::getNumberOfInstances() << std::endl;
  std::cout << "test: " << genericAnimal.getNumberOfInstances() << std::endl;

  std::cout << "I'm leaving.." << std::endl;
  return 0;
}