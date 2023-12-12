#include "Prerequisites.h"

// Base interface for Mueble
class Mueble {
public:
  virtual void descripcion() = 0; // Method to describe the furniture
  virtual void color() = 0;       // Method to get the color of the furniture
};

// Concrete class representing a Silla
class Silla : public Mueble {
public:
  void descripcion() override {
    cout << "A splendid furniture from the factory" << endl;
  }

  void color() override {
    cout << "In furniture factory color" << endl;
  }
};

// Concrete class representing a Mesa
class Mesa : public Mueble {
public:
  void descripcion() override {
    cout << "A splendid table from the factory" << endl;
  }

  void color() override {
    cout << "In table factory color" << endl;
  }
};

// Interface for furniture factories
class FactoryMuebles {
public:
  virtual Silla* crearSilla() = 0; // Method to create a chair
  virtual Mesa* crearMesa() = 0;   // Method to create a table
};

// Implementation of the rustic furniture factory
class FactoryMueblesRusticos : public FactoryMuebles {
public:
  Silla* crearSilla() override {
    return new Silla(); // Creates a rustic chair
  }

  Mesa* crearMesa() override {
    return new Mesa(); // Creates a rustic table
  }
};

// Implementation of the modern furniture factory
class FactoryMueblesModernos : public FactoryMuebles {
public:
  Silla* crearSilla() override {
    return new Silla(); // Creates a modern chair
  }

  Mesa* crearMesa() override {
    return new Mesa(); // Creates a modern table
  }
};
