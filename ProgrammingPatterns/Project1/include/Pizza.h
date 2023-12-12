#pragma once
#include "Prerequisites.h"

// Class representing a Pizza
class Pizza
{
public:
  // Function to add parts to the pizza
  void addParts(const string _part) {
    m_parts.push_back(_part);
  }

  // Function to print the parts of the pizza
  void print() {
    cout << "Pizza parts: ";
    for (int i = 0; i < m_parts.size(); i++)
    {
      cout << m_parts[i] << ", ";
    }
    cout << "" << endl;
  }

private:
  vector<string> m_parts; // Vector to store pizza parts
};

// Abstract class representing an Oven interface
class Oven
{
public:
  // Pure virtual function to build pizza dough mass
  virtual void buildMass() = 0;

  // Pure virtual function to add cheese to the pizza
  virtual void buildCheese() = 0;

  // Pure virtual function to add sauce to the pizza
  virtual void buildSauce() = 0;

  // Pure virtual function to add ingredients to the pizza
  virtual void buildIngredients() = 0;

  // Pure virtual function to get the final pizza product
  virtual Pizza* getProduct() = 0;
};

// Concrete class representing a Hawaiian Pizza built using the Oven interface
class HawaianPizza : public Oven {
public:
  // Constructor to initialize a Hawaiian Pizza object
  HawaianPizza() {
    m_product = new Pizza();
  }

  // Implementing the building of pizza dough mass
  void buildMass() override {
    m_product->addParts("Cheese crust dough");
  }

  // Implementing the addition of cheese
  void buildCheese() override {
    m_product->addParts("Melted cheese");
  }

  // Implementing the addition of sauce
  void buildSauce() override {
    m_product->addParts("Tomato sauce");
  }

  // Implementing the addition of pineapple as an ingredient
  void buildIngredients() override {
    m_product->addParts("Pineapple");
  }

  // Function to retrieve the final pizza product
  Pizza* getProduct() override {
    return m_product;
  }

private:
  Pizza* m_product; // Pizza object representing the final product
};

// Concrete class representing a Veggie Pizza built using the Oven interface
class VeggiePizza : public Oven {
public:
  // Constructor to initialize a Veggie Pizza object
  VeggiePizza() {
    m_product = new Pizza();
  }

  // Implementing the building of pizza dough mass
  void buildMass() override {
    m_product->addParts("Cheese crust dough");
  }

  // Implementing the addition of cheese
  void buildCheese() override {
    m_product->addParts("Melted cheese");
  }

  // Implementing the addition of sauce
  void buildSauce() override {
    m_product->addParts("Tomato sauce");
  }

  // Implementing the addition of vegetables as ingredients
  void buildIngredients() override {
    m_product->addParts("Vegetables");
  }

  // Function to retrieve the final pizza product
  Pizza* getProduct() override {
    return m_product;
  }

private:
  Pizza* m_product; // Pizza object representing the final product
};

// Class representing a Chef
class Chef {
public:
  // Constructor to initialize a Chef with a specific oven
  Chef(Oven* _oven) : m_builder(_oven) {}

  // Function to build a pizza using the assigned oven
  void build() {
    m_builder->buildMass();
    m_builder->buildCheese();
    m_builder->buildSauce();
    m_builder->buildIngredients();
  }

private:
  Oven* m_builder; // Oven object assigned to the Chef
};
