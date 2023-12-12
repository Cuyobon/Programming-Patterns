#pragma once
#pragma once
#include "Prerequisites.h"

/*
  Brief: The Composite pattern is used to treat groups of objects in the same way
  as a single object. It is useful for managing resources more effectively.
 */

class Component2 {
public:
  virtual void operacion() = 0;
};

class Leaf : public Component2 {
  void operacion() override {
    cout << "Operation in leaf" << endl;
  }
};

class Composite : public Component2 {
public:
  /*
    Brief: Performs the operation in the composite. It displays the number of leafs it contains
   and then performs the operation on each leaf.
   */
  void operacion() override {
    cout << "Operation in composite. Contains: "
      << m_leafs.size() << " leafs." << endl;

    for (auto leaf : m_leafs) {
      leaf->operacion();
    }
  }

  /*
    Brief: Adds a leaf component to the composite.
   */
  void addLeaf(Component2* _leaf) {
    m_leafs.push_back(_leaf);
  }

public:
  vector<Component2*> m_leafs;
};
