#include "Animal.h"

int Animal::numberOfInstances = 0;
const float Animal::SECRET_VAL = 3.14159268;

int Animal::getNumberOfInstances() {
  return numberOfInstances;
}

Animal::Animal(std::string name, IFlyable& flyStrategy, IRunnable& runStrategy, IEatable& eatStrategy) : 
  name(name), flyStrategy(flyStrategy), runStrategy(runStrategy), eatStrategy(eatStrategy)
{
  numberOfInstances++;
}

Animal::~Animal() {
  std::cout << "AnimalDestructor" << std::endl;
  numberOfInstances--;
}

void Animal::setName(std::string name) {
  this->name = name;
}

std::string Animal::getName() {
  return name;
}

void Animal::setWeight(float weight) {
  this->weight = weight;
}
    
float Animal::getWeight() {
  return weight;
}

float Animal::getSecretValue() {
  return SECRET_VAL;
}

// Specific strategy implementation
int Animal::fly() {
  return flyStrategy.fly();
}

int Animal::run() {
  return runStrategy.run();
}

int Animal::eat() {
  return eatStrategy.eat();
}

// Cat subclass
const int Cat::catValue = 18;
const float Cat::SECRET_CAT_VAL = 2.718;

Cat::Cat(std::string name, IFlyable& flyStrategy, IRunnable& runStrategy, IEatable& eatStrategy)
    : Animal(name, flyStrategy, runStrategy, eatStrategy) {
}

Cat::~Cat() {
  std::cout << "CatDestructor" << std::endl;
}

int Cat::getCatValue() {
  return catValue;
}

int Cat::fly() {
  return flyStrategy.fly() + 1;
}

int Cat::run() {
  return runStrategy.run() + 1;
}

int Cat::eat() {
  return eatStrategy.eat() + 1;
}

float Cat::getSecretValue(){
  return SECRET_CAT_VAL;
}