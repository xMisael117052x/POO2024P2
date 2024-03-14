#pragma once
#include "Prerequisites.h"


// Clase que representa un producto complejo
class BPProduct
{
public:
	void agregarParte(const string& _parte) {
		partes.push_back(_parte);
	}

	void mostrar() {
		for (auto& parte : partes) {
			cout << parte << "";
		}
		cout << endl;
	}

private: vector<string> partes;
};

// Clase abtracta del constructor (builder)
class Builder {
public:
	virtual void construirParteA() = 0;
	virtual void construirParteB() = 0;
	virtual BPProduct* obtenerProducto() = 0;
};

// Clase concreta del constructor (builder)

class BuilderConcreto : public Builder {
public:
	BuilderConcreto() : producto(new BPProduct()) {}

	void construirParteA() {
		producto->agregarParte("Parte A");
	}

	void construirParteB() {
		producto->agregarParte("Parte B");
	}

	BPProduct* obtenerProducto() {
		return producto;
	}

private:
	BPProduct* producto;
};

// clase Director
class Director {
public:
	Director(Builder* _builder) : builder(_builder) {}

	void construir() {
		builder->construirParteA();
		builder->construirParteB();
	}

private:
	Builder* builder;
};


// ACTIVIDAD

class Pizza {
public:
	void setMasa(const string& _masa) {
		masa = _masa;
	}

	void setSalsa(const string& _salsa) {
		salsa = _salsa;
	}

	void setQueso(const string& _queso) {
		queso = _queso;
	}

	void agregarIngrediente(const string& _ingrediente) {
		ingredientes.push_back(_ingrediente);
	}
	void mostrar() const {
		cout << "Masa: " << masa << "\nSalsa: " << salsa << "\nIngredientes:";
		for (const auto& ingrediente : ingredientes) {
			cout << " " << ingrediente;
		}
		cout << endl;
	}
private:
	string masa;
	string salsa;
	string queso;
	vector<string> ingredientes;
};

// Clase abstracta ConstructorPizza
class ConstructorPizza {
public:
	virtual ~ConstructorPizza() {}
	virtual void construirMasa() = 0;
	virtual void construirSalsa() = 0;
	virtual void construirQueso() = 0;
	virtual void construirIngredientes() = 0;
	virtual Pizza* obtenerPizza() = 0;
};

// ConstructorPizzaHawaiana
class ConstructorPizzaHawaiana : public ConstructorPizza {
public:
	ConstructorPizzaHawaiana() : pizza(new Pizza()) {}
	void construirMasa() {
		pizza->setMasa("suave");
	}

	void construirSalsa() {
		pizza->setSalsa("dulce");
	}

	void construirQueso() {
		pizza->setQueso("mozzarella");
	}

	void construirIngredientes() {
		pizza->agregarIngrediente("piña");
		pizza->agregarIngrediente("jamón");
	}

	Pizza* obtenerPizza() {
		return pizza;
	}
private:
	Pizza* pizza;
};

// ConstructorPizzaVegetariana
class ConstructorPizzaVegetariana : public ConstructorPizza {
public:
	ConstructorPizzaVegetariana() : pizza(new Pizza()) {}
	void construirMasa() {
		pizza->setMasa("integral");
	}

	void construirSalsa() {
		pizza->setSalsa("tomate");
	}

	void construirQueso() {
		pizza->setQueso("mozzarella");
	}

	void construirIngredientes() {
		pizza->agregarIngrediente("pimiento");
		pizza->agregarIngrediente("aceitunas");
		pizza->agregarIngrediente("champiñones");
	}

	Pizza* obtenerPizza() {
		return pizza;
	}
private:
	Pizza* pizza;
};

// Director
class DirectorPizza {
public:
	void setConstructor(ConstructorPizza* _constructor) {
		constructor = _constructor;
	}

	Pizza* construirPizza() {
		constructor->construirMasa();
		constructor->construirSalsa();
		constructor->construirQueso();
		constructor->construirIngredientes();
		return constructor->obtenerPizza();
	}

private:
	ConstructorPizza* constructor;
};