//Programming Patterns
#include "Prerequisites.h"
#include "Singleton.h"
#include "RegistroActividad.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "FactoryMueble.h"
#include "Builder.h"
#include "Pizza.h"
#include "Adapter.h"
#include "Circulo.h"
#include "Prototype.h"
#include "Decorator.h"
#include "Cafeteria.h"
#include "Composite.h"

Singleton* Singleton::m_instance = nullptr;
RegistroActividad* RegistroActividad::m_instance = nullptr;

int main() {
  //Singleton
  cout << "SINGLETON" << endl;
  Singleton* SingleMan = Singleton::getInstance();
  SingleMan->setValue(27);

  Singleton* SingleMan2 = Singleton::getInstance();
  std::cout << "Value: " << SingleMan2->getValue() << std::endl;

  //Singleton Register
  cout << "SINGLETON REGISTER" << endl;
  RegistroActividad* Registro = RegistroActividad::getInstance();
  RegistroActividad* Registro2 = RegistroActividad::getInstance();

  Registro->addActivity("Primer actividad");
  Registro->addActivity("Segunda actividad");
  Registro->addActivity("Tercea actividad");

  Registro2->showActivities();

  //Factory
  cout << "FACTORY" << endl;
  Factory* factory = new ConcreteFactory();
  Product* product = factory->crearProducto();
  product->operacion();
  cout << "" << endl;

  delete factory;
  delete product;

  //Factory Practice
  cout << "VEHICULOS FACTORY PRACTICE" << endl;
  FactoryVehiculos* factoryV = new ConcreteFactoryCoche();
  Vehiculo* vehiculo = factoryV->crearVehiculo();
  vehiculo->descripcion();
  cout << "" << endl;

  delete factoryV;
  delete vehiculo;

  //Abstract Factory
  cout << "ABSTRACT FACTORY" << endl;
  AbstractFactory* AFactory = new ConcreteAbsFactory();

  ProductA* productA = AFactory->crearProductoA();
  ProductB* productB = AFactory->crearProductoB();
  productA->operationA();
  productB->operationB();
  cout << "" << endl;

  delete AFactory;
  delete productA;
  delete productB;

  //Abstract Factory Practice
   FactoryMueblesRusticos* fabrica = new FactoryMueblesRusticos;

   Silla* sillaRustica = fabrica->crearSilla();
   Mesa* mesaRustica = fabrica->crearMesa();

   sillaRustica->descripcion();
   sillaRustica->color();
   mesaRustica->descripcion();
   mesaRustica->color();
   cout << "" << endl;

   delete fabrica;
   delete sillaRustica;
   delete mesaRustica;

  //Builder
  cout << "BUILDER" << endl;
  Builder* constructor = new BuilderConcreto();

  Director director(constructor);
  director.build();

  bProduct* producto = constructor->obtenerProducto();
  producto->print();
  cout << "" << endl;

  delete constructor;
  delete producto;

  //Prototype
  cout << "PROTORYPE" << endl;
  Prototype* prototype = new ConcretePrototype();
  prototype->configurar("Ejemplo");

  Prototype* copia = prototype->clonar();

  prototype->print();
  copia->print();
  cout << "" << endl;

  delete prototype;
  delete copia;

  //Adapter
  cout << "ADAPTER" << endl;
  InterfazVieja* objViejo = new InterfazVieja();
  InterfazNueva* objNuevo = new Adapter(objViejo);

  objNuevo->NewMethod();
  cout << "" << endl;

  delete objViejo;
  delete objNuevo;

  //Circulo Adapter
  cout << "CIRCLE ADAPTER PRACTICE" << endl;
  Circulo* circle = new Circulo();
  Cuadrado* square = new Cuadrado();
  Dibujable* AdCircle = new CirculoAdapter(circle);
  Dibujable* AdSquare = new CuadradoAdapter(square);

  AdCircle->dibujar();
  AdSquare->dibujar();
  cout << "" << endl;

  delete circle;
  delete square;
  delete AdCircle;

  //Decorator
  cout << "DECORATOR" << endl;
  ConcreteComponent* objeto = new ConcreteComponent();
  ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(objeto);
  ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);

  objeto->operacion();
  decoratorA->operacion();
  decoratorB->operacion();
  cout << "" << endl;

  delete objeto;
  delete decoratorA;
  delete decoratorB;

  //Cafeteria Decorator
  cout << "CAFETERIA DECORADOR PRACTICE" << endl;
  Cafeteria* cafeteria = new Cafeteria();

  Leche* cafeLeche = new Leche(cafeteria);
  Azucar* cafeAzucar = new Azucar(cafeteria);

  cafeteria->prepararCafe();

  cafeLeche->decorate();
  cafeAzucar->decorate();
  cout << "" << endl;

  delete cafeteria;
  delete cafeLeche;
  delete cafeAzucar;
  return 0;

  //Composite
  cout << "COMPOSITE" << endl;
  Leaf* hoja1 = new Leaf();
  Leaf* hoja2 = new Leaf();
  Composite* composite = new Composite();

  composite->addLeaf(hoja1);
  composite->addLeaf(hoja2);
  composite->operacion();
  cout << "" << endl;

  delete hoja1;
  delete hoja2;
  delete composite;
}