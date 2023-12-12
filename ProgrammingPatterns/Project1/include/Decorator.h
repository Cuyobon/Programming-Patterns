#pragma once
#include "Prerequisites.h"

/*
 * The Decorator pattern can dynamically add functionalities to existing objects.
 * It acts as an alternative to inheritance, allowing the addition of new functionalities
 * to individual objects.
 */

 // Base Interface - Component
class Component {
public:
  virtual void operacion() = 0;
};

// Concrete Class
class ConcreteComponent : public Component {
public:
  /*
    Brief: Implementation of the operation for the concrete component.
   */
  void operacion() override {
    cout << "Operation of the concrete component" << endl;
  }
};

// Base Decorator
class Decorator : public Component {
public:
  /*
    Brief: Constructor for the decorator class.
   */
  Decorator(Component* _component) :
    m_component(_component) {}

  void operacion() override {
    m_component->operacion();
  }

private:
  Component* m_component;
};

// Concrete Decorator A
class ConcreteDecoratorA : public Decorator {
public:
  /*
    Brief: Constructor for Concrete Decorator A.
   */
  ConcreteDecoratorA(Component* _component) :
    Decorator(_component) {}

  void operacion() override {
    Decorator::operacion();
    cout << "Operation of Decorator A" << endl;
  }
};

// Another Concrete Decorator B
class ConcreteDecoratorB : public Decorator {
public:
  /*
    Brief: Constructor for Concrete Decorator B.
   */
  ConcreteDecoratorB(Component* _component) :
    Decorator(_component) {}

  void operacion() override {
    Decorator::operacion();
    cout << "Operation of Decorator B" << endl;
  }
};
