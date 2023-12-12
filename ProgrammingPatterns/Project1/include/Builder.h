#pragma once
#include "Prerequisites.h"

/*
  The Builder pattern is used to construct a complex object step by step
 * using different parts. It also allows creating different types of the same object.
 * All of this is done through a class called Director, which is responsible for
 * constructing the objects.
 */

class bProduct {
public:
	/*
		Brief: Function to add a part to the product.
	 */
	void agregarParte(const string& _parte) {
		m_partes.push_back(_parte);
	}

	/*
	 Brief: Function to print the parts of the product.
	 */
	void print() {
		cout << "Parts of the product: ";
		for (int i = 0; i < m_partes.size(); i++) {
			cout << m_partes[i] << " ";
		}
	}

private:
	vector<string> m_partes;
};

/*
 Brief: Abstract Builder class defining the interface for creating parts of the product.
 */
class Builder {
public:
	virtual void buildParteA() = 0;
	virtual void buildParteB() = 0;
	virtual bProduct* obtenerProducto() = 0;
};

/*
 Brief: Concrete Builder class implementing the Builder interface.
 It constructs and assembles the parts of the product.
 */
class BuilderConcreto : public Builder {
public:
	BuilderConcreto() {
		m_product = new bProduct();
	}

	void buildParteA() override {
		m_product->agregarParte("Part A");
	}

	void buildParteB() override {
		m_product->agregarParte("Part B");
	}

	bProduct* obtenerProducto() override {
		return m_product;
	}

private:
	bProduct* m_product;
};

/*
	Brief: Director class responsible for constructing the product using a Builder.
 */
class Director {
public:
	Director(Builder* _builder) : m_builder(_builder) {}

	/*
		Brief: Function to build the product by specifying the parts to the Builder.
	 */
	void build() {
		m_builder->buildParteA();
		m_builder->buildParteB();
	}

private:
	Builder* m_builder;
};
