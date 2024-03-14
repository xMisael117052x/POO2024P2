#pragma once
#include "Prerequisites.h";


// Interfaz base
class Componente {
public:
	virtual void operacion() = 0;
};

// Clase concreta
class ComponenteConcreto : public Componente {
public:
	void operacion() override {
		cout << "Operacion del componente concreto" << endl;
	}
};

// Decorador base
class Decorator : public Componente {
public:
	Decorator(Componente* componente) : m_componente(componente) {}

private:
	Componente* m_componente;
};

// Decorator concreto
class DecoratorConcretoA : public Decorator {
public:
	DecoratorConcretoA(Componente* componente) : Decorator(componente) {}

	void operacion() override {
		Decorator::operacion();
		cout << "Operacion del decorador A" << endl;
	}
};

// Otro Decorator concreto
class DecoratorConcretoB : public Decorator {
public:
	DecoratorConcretoB(Componente* componente) : Decorator(componente) {}

	void operacion() override {
		Decorator::operacion();
		cout << "Operacion del decorador B" << endl;
	}
};

// ACTIVIDAD

// Componente base
class Cafe {
public:
	virtual void prepararCafe() = 0;
};

// Componente concreto
class Cafeteria : public Cafe {
public:
	void prepararCafe() override {
		cout << "Café preparado" << endl;
	}
};

// Decorador base
class Condimento : public Cafe {
protected:
	Cafe* cafeDecorado;
public:
	Condimento(Cafe* cafe) : cafeDecorado(cafe) {}
	virtual void prepararCafe() override {
		cout << "Café preparado con condimento" << endl;
	}
};

// Decorador concreto para Leche
class Leche : public Condimento {
public:
	Leche(Cafe* cafe) : Condimento(cafe) {}
	virtual void prepararCafe() override {
		cout << "Café preparado con leche" << endl;
	}
};

// Decorador concreto para Azucar
class Azucar : public Condimento {
public:
	Azucar(Cafe* cafe) : Condimento(cafe) {}
	virtual void prepararCafe() override {
		cout << "Café preparado con azucar" << endl;
	}
};