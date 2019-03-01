#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "interfaces.h"

class Animal : public IRunnable, public IFlyable, public IEatable {
  public:
    // Class attribute
    static int getNumberOfInstances();

    // Constructor and Destructor
    Animal(std::string name, IFlyable& flyStrategy, IRunnable& runStrategy, IEatable& eatStrategy);
    virtual ~Animal();

    void setName(std::string name);
    std::string getName();
    void setWeight(float weight);
    float getWeight();
    virtual float getSecretValue();
    // Strategy pattern
    int fly() override;
    int run() override;
    int eat() override;

  private:
    // Animal secret value
    static const float SECRET_VAL;

  protected:
    // Inheritable
    static int numberOfInstances;
    std::string name;
    float weight;
    // Strategies
    IFlyable& flyStrategy;
    IRunnable& runStrategy;
    IEatable& eatStrategy;
};

class Cat : public Animal {
  private:
    static const int catValue;
    // Animal secret value
    static const float SECRET_CAT_VAL;

  public:
    Cat(std::string name, IFlyable& flyStrategy, IRunnable& runStrategy, IEatable& eatStrategy);
    ~Cat();
    int getCatValue();
    float getSecretValue() override;
    int fly() override;
    int run() override;
    int eat() override;
};

#endif