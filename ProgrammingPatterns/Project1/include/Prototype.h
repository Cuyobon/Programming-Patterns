#pragma once
#include "Prerequisites.h"

/*
The Prototype pattern is used to create new objects from an existing class that serves as a prototype.
It defines a method within the prototype that is used to clone the object and configure it when creating a new one,
thus avoiding the need to create subclasses for each type of object.
*/

// Class with logic for the prototype
class Prototype
{
public:
  virtual Prototype* clonar() = 0; // Instance of the class that will be cloned
  virtual void configurar(string _value) = 0; // Function to configure the prototype
  virtual void print() = 0; // Function to print the configured values
};

// Concrete prototype class
class ConcretePrototype : public Prototype {
public:
  Prototype* clonar() override {
    ConcretePrototype* copy = new ConcretePrototype();
    copy->configurar(m_value);
    return copy;
  }

  void configurar(string _value) override {
    m_value = _value;
  }

  void print() override {
    cout << "Value: " << m_value << endl;
  }

private:
  string m_value;
};
