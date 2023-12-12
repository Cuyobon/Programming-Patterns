#pragma once
#include "Prerequisites.h"

// Class Pizza representing a pizza with its ingredients
class
  Pizza {
public:

  void agregarMasa(const string& _ingredientes) {
    m_ingredientes.push_back(_ingredientes);
  }

  void agregarSalsa(const string& _ingredientes) {
    m_ingredientes.push_back(_ingredientes);
  }

  void agregarQueso(const string& _ingredientes) {
    m_ingredientes.push_back(_ingredientes);
  }

  void agregarComplemento(const string& _ingredientes) {
    m_ingredientes.push_back(_ingredientes);
  }

  // Method to print the ingredients of the pizza
  void print() {
    cout << "Partes de la pizza: " << endl;
    for (int i = 0; i < m_ingredientes.size(); i++) {
      cout << m_ingredientes[i] << " ";
    }
    cout << endl;
  }

private:
  vector<string> m_ingredientes; 
};

// Class ConstructorPizza defining methods to construct pizzas
class
  ConstructorPizza {
public:
  // Pure virtual methods to build different parts of the pizza
  virtual void crearMasa() = 0;
  virtual void crearSalsa() = 0;
  virtual void crearQueso() = 0;
  virtual void crearComplemento() = 0;
  virtual Pizza* obtenerPizzaVegetariana() = 0;
  virtual Pizza* obtenerPizzaHawaiana() = 0;

  virtual ~ConstructorPizza() {}
};

// Class ConcretePizzaConstructor implementing pizza construction methods
class
  ConstructorPizzaConcreto :
  public ConstructorPizza {
public:
  ConstructorPizzaConcreto() {
    m_pizzaHawaina = new Pizza();
    m_pizzaVegetariana = new Pizza();
  }

  // Implementation of methods for constructing the Hawaiian pizza
  void crearMasa() override {
    m_pizzaHawaina->agregarMasa("Masa h");
  }

  void crearSalsa() override {
    m_pizzaHawaina->agregarSalsa("Salsa h");
  }

  void crearQueso() override {
    m_pizzaHawaina->agregarQueso("Queso h");
  }

  void crearComplemento() override {
    m_pizzaHawaina->agregarComplemento("Pina");
    m_pizzaHawaina->agregarComplemento("Jamon");
  }

  // Method to obtain a created Hawaiian pizza
  Pizza* obtenerPizzaHawaiana() override {
    return m_pizzaHawaina;
  }

  // Implementation of methods for constructing the Vegetarian pizza
  /*void crearMasa() override {
    m_pizzaVegetariana->agregarMasa("Masa v");
  }

  void crearSalsa() override {
    m_pizzaVegetariana->agregarSalsa("Salsa v");
  }

  void crearQueso() override {
    m_pizzaVegetariana->agregarQueso("Queso v");
  }

  void crearComplemento() override {
    m_pizzaVegetariana->agregarComplemento("Onions");
    m_pizzaVegetariana->agregarComplemento("Lechuga");
  }

  Pizza* obtenerPizzaVegetariana() override {
    return m_pizzaVegetariana;
  }*/

private:
  Pizza* m_pizzaHawaina;
  Pizza* m_pizzaVegetariana;
};

// Director class using a ConstructorPizza to build pizzas
class
  Pizzeria {
public:
  Pizzeria(ConstructorPizza* _pizza) :m_constructorPizza(_pizza) {}

  // Method to build a pizza using the provided ConstructorPizza
  void Construir() {
    m_constructorPizza->crearMasa();
    m_constructorPizza->crearSalsa();
    m_constructorPizza->crearQueso();
    m_constructorPizza->crearComplemento();
  }

private:
  ConstructorPizza* m_constructorPizza;
};