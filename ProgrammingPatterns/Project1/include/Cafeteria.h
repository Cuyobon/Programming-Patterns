#pragma once
#include "Prerequisites.h"

// Class Cafeteria representing the object to be decorated
class Cafeteria {
public:
  // Method to prepare basic coffee
  void prepararCafe() {
    cout << "Coffee prepared" << endl;
  }
};

// Abstract class Condiment that defines the interface for condiments
class Condiment {
public:
  virtual void decorate() = 0; // Pure virtual method to decorate
};

// Class Milk, a condiment responsible for decorating with milk
class Leche : public Condiment {
public:
  Leche(Cafeteria* _cafeteria)
    : m_milk(_cafeteria) {}

  // Method to decorate with milk
  void decorate() override {
    m_milk->prepararCafe(); // Prepares coffee using the base cafeteria
    cout << "Milk added" << endl; // Adds milk to the coffee
  }

private:
  Cafeteria* m_milk; // Pointer to Cafeteria object
};

// Class Sugar, a condiment responsible for decorating with sugar
class Azucar : public Condiment {
public:
  Azucar(Cafeteria* _cafeteria)
    : m_sugar(_cafeteria) {}

  // Method to decorate with sugar
  void decorate() override {
    m_sugar->prepararCafe(); // Prepares coffee using the base cafeteria
    cout << "Sugar added" << endl; // Adds sugar to the coffee
  }

private:
  Cafeteria* m_sugar; // Pointer to Cafeteria object
};
