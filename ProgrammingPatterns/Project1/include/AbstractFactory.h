#pragma once
#include "Prerequisites.h"

/* Similar to Factory, but this pattern allows for greater abstraction as it defines an interface
to create families of related objects. */

class ProductA {
public:
  virtual void operationA() = 0;
};

class ProductB {
public:
  virtual void operationB() = 0;
};

class AbstractFactory {
public:
  // Abstract methods to create ProductA and ProductB instances
  virtual ProductA* crearProductoA() = 0;
  virtual ProductB* crearProductoB() = 0;
};

class ProductA1 : public ProductA {
public:
  void operationA() override {
    cout << "Operation A in ProductA1" << endl;
  }
};

class ProductB1 : public ProductB {
public:
  void operationB() override {
    cout << "Operation B in ProductB1" << endl;
  }
};

class ConcreteAbsFactory : public AbstractFactory {
public:
  // Concrete implementation of creating ProductA1 and ProductB1 instances
  ProductA* crearProductoA() override {
    return new ProductA1();
  }
  ProductB* crearProductoB() override {
    return new ProductB1();
  }
};
