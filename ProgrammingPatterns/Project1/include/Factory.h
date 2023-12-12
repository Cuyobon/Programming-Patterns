#pragma once
#include "Prerequisites.h"

/* The Factory pattern is used for creating objects based on an interface to create them.
It helps separate the code that uses the object from the logic that creates it. */

/*
  Brief: This class is responsible for being the base object of the products that will be created
*/
class Product {
public:
  virtual void operacion() = 0;
};

/*
  Brief: This class is the base object used to create instances of each product using the "crearProducto()" function
*/
class Factory {
public:
  virtual Product* crearProducto() = 0;
};

/*
  Brief: This class is used to perform operations upon receiving the product
*/
class ConcreteProduct : public Product {
public:
  void operacion() override {
    cout << "An operation is performed here" << endl;
  }
};

/*
  Brief: Used for creating new products
*/
class ConcreteFactory : public Factory {
public:
  Product* crearProducto() override {
    return new ConcreteProduct();
  }
};

/*
  Brief: Class responsible for being the base object of the vehicles that will be created
*/
class Vehiculo {
public:
  virtual void descripcion() {
    cout << "Hello, I am a vehicle" << endl;
  }
};

/*
  Brief: This class is used to perform car operations upon receiving a vehicle
*/
class ConcreteCoche : public Vehiculo {
public:
  void descripcion() override {
    cout << "Hello, I am a car" << endl;
  }
};

/*
Brief: This class is used to perform bicycle operations upon receiving the product
*/
class ConcreteBicicleta : public Vehiculo {
public:
  void descripcion() override {
    cout << "Hello, I am a bicycle" << endl;
  }
};

/*
  Brief: This class is the base object used to create instances of each vehicle using the "crearVehiculo()" function
*/
class FactoryVehiculos {
public:
  virtual Vehiculo* crearVehiculo() = 0;
};

class ConcreteFactoryCoche : public FactoryVehiculos {
public:
  Vehiculo* crearVehiculo() override {
    return new ConcreteCoche();
  }
};

class ConcreteFactoryBicicleta : public FactoryVehiculos {
public:
  Vehiculo* crearVehiculo() override {
    return new ConcreteBicicleta();
  }
};
