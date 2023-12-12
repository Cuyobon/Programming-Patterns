#pragma once
#include "Prerequisites.h"

// In this case, the deprecated class is a circle
class Circulo {
public:
  virtual void dibujarCirculo() {
    cout << "A circle has been drawn." << endl;
  }
};

// In this case, the deprecated class is a square
class Cuadrado {
public:
  virtual void dibujarCuadrado() {
    cout << "A square has been drawn." << endl;
  }
};

// Class that acts as a new interface for circle and square
class Dibujable {
public:
  virtual void dibujar() {
    cout << "New method called." << endl;
  }
};

// Implements the Dibujable class by inheriting the Circle to be able to draw it
class CirculoAdapter : public Dibujable {
public:
  CirculoAdapter(Circulo* circulo) : m_Circulo(circulo) {}

  //brief Draws a circle using an adapter.
  void dibujar() override {
    cout << "Adapter called to draw a circle." << endl;
    m_Circulo->dibujarCirculo();
  }

public:
  Circulo* m_Circulo;
};

// Implements the Dibujable class by inheriting the Square to be able to draw it
class CuadradoAdapter : public Dibujable {
public:
  CuadradoAdapter(Cuadrado* cuadrado) : m_cuadrado(cuadrado) {}

  //Draws a square using an adapter.
   
  void dibujar() override {
    cout << "Adapter called to draw a square." << endl;
    m_cuadrado->dibujarCuadrado();
  }

public:
  Cuadrado* m_cuadrado;
};
