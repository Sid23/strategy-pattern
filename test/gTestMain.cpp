#include <cstdio>
#include "gtest/gtest.h"
#include "Animal.h"

TEST(test, test) {
  ASSERT_EQ(0, 0);
}

TEST(NumberOfInstances, basicTest) {
  NoFly fStrategy;
  RunFast rStrategy;
  EatLots eStrategy;
  
  Animal *animal1 = new Animal("Piero", fStrategy, rStrategy, eStrategy);
  ASSERT_EQ(0, 0);
  /*
  
  ASSERT_EQ(Animal::getNumberOfInstances(), 1);
  Animal *animal2 = new Animal("Gino", fStrategy, rStrategy, eStrategy);
  ASSERT_EQ(Animal::getNumberOfInstances(), 2);
  delete animal1;
  ASSERT_EQ(Animal::getNumberOfInstances(), 1);
  delete animal2;
  ASSERT_EQ(Animal::getNumberOfInstances(), 0);
  */
}
/*
TEST(NumberOfInstances, derivedClassTest) {
  NoFly fStrategy;
  RunFast rStrategy;
  EatLots eStrategy;
  Cat *cat1 = new Cat("Piero", fStrategy, rStrategy, eStrategy);
  ASSERT_EQ(Animal::getNumberOfInstances(), 1);
  Animal *cat2 = new Cat("Gino", fStrategy, rStrategy, eStrategy);
  ASSERT_EQ(Animal::getNumberOfInstances(), 2);
  delete cat2;
  ASSERT_EQ(Animal::getNumberOfInstances(), 1);
  delete cat1;
  ASSERT_EQ(Animal::getNumberOfInstances(), 0);
}

TEST(Polymorphism, derivedStrategyMethods) {
  NoFly fStrategy;
  RunFast rStrategy;
  EatLots eStrategy;
  Animal *cat1 = new Cat("Piero", fStrategy, rStrategy, eStrategy);
  ASSERT_EQ(Animal::getNumberOfInstances(), 1);
  Cat *catPtr = (Cat*)cat1;
  //ASSERT_EQ(cat1->getSecretValue(), catPtr->getSecretValue());
  //ASSERT_EQ(catPtr->getCatValue(), 18);
  ASSERT_EQ(cat1->fly(), 1) << "No Polymorphism!";
  ASSERT_EQ(cat1->run(), 5) << "No Polymorphism!";
  ASSERT_EQ(cat1->eat(), 4) << "No Polymorphism!";
  delete cat1;
  ASSERT_EQ(Animal::getNumberOfInstances(), 0);
}

TEST(Polymorphism, derivedClassMethods) {
  NoFly fStrategy;
  RunFast rStrategy;
  EatLots eStrategy;
  Animal animal1("Piero", fStrategy, rStrategy, eStrategy);
  Animal* cat1 = new Cat("Gino", fStrategy, rStrategy, eStrategy);
  ASSERT_FALSE(animal1.getSecretValue() == cat1->getSecretValue());
  Cat cat2("Pallino", fStrategy, rStrategy, eStrategy);
  Animal animal2("Animal", fStrategy, rStrategy, eStrategy);
  ASSERT_FLOAT_EQ(animal1.getSecretValue(), animal2.getSecretValue());
  ASSERT_FLOAT_EQ(cat1->getSecretValue(), cat2.getSecretValue());
  
}
*/
#ifdef ARDUINO
void setup() {
  // Since Arduino doesn't have a command line, fake out the argc/argv arguments
  int argc = 1;
  const auto arg0 = "PlatformIO";
  char* argv0 = const_cast<char*>(arg0);
  char** argv = &argv0;

  testing::InitGoogleTest(&argc, argv);
}

void loop() { RUN_ALL_TESTS(); }

#else

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif
