#pragma once
#include "Prerequisites.h"

/* The Adapter pattern allows two different interfaces to work together.
It converts the interface of a class into another interface. */

// Deprecated for the old interface
class InterfazVieja {
public:
  virtual void OldMethod() {
    cout << "Old method called." << endl;
  }
};

// Target for a new interface
class InterfazNueva {
public:
  virtual void NewMethod() {
    cout << "New method called." << endl;
  }
};

// Implements the new interface by inheriting the old interface to adapt it
class Adapter : public InterfazNueva {
public:
  Adapter(InterfazVieja* _old) : m_oldInterface(_old) {}

  void NewMethod() override {
    cout << "Adapter calling the new method." << endl;
    m_oldInterface->OldMethod();
  }

public:
  InterfazVieja* m_oldInterface;
};
