#pragma once

/* The Singleton pattern is useful because it ensures that a class has only one instance
and provides a global point of access to that instance. It is useful when a single instance
is required for system-wide actions. */

class Singleton
{
public:
  Singleton() : m_value(0) {};

  static Singleton* getInstance() {
    if (m_instance != nullptr) // Check if m_instance is already initialized
    {
      return m_instance; // Return an existing Singleton
    }
    else {
      m_instance = new Singleton; // Return a newly created Singleton
    }
    return m_instance; // Return the created or existing Singleton
  }

  ~Singleton() = default;

  // Set the value of the m_value variable
  void setValue(int _v) {
    m_value = _v;
  }

  // Get the value of the m_value variable
  int getValue() {
    return m_value;
  }

private:
  static Singleton* m_instance;
  int m_value;
};
