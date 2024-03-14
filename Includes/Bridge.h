#pragma once
#include "Prerequisites.h"

// Clase base para la implementaci�n. Define una interfaz para las operaciones concretas.
class Implementacion {
public:
	// M�todo virtual puro que las implementaciones concretas deben definir.
	virtual void operacion() = 0;
};

// Implementaci�n concreta A de la clase base de implementaci�n.
class ImplementacionConcretaA : public Implementacion {
public:
	// Sobrescribe el m�todo operacion para realizar una acci�n espec�fica.
	void operacion() override {
		cout << "Operacion en Implementacion A" << endl;
	}
};

// Implementaci�n concreta B, otra variante de la clase base de implementaci�n.
class ImplementacionConcretaB : public Implementacion {
public:
	// Sobrescribe el m�todo operacion para realizar otra acci�n espec�fica.
	void operacion() override {
		cout << "Operacion en Implementacion B" << endl;
	}
};

// Clase base Abstraccion. Define la interfaz de abstracci�n que mantiene una referencia a un objeto de tipo Implementacion.
class Abstraccion {
public:
	// Constructor que toma un puntero a Implementacion para establecer la implementaci�n concreta.
	Abstraccion(Implementacion* imp) : m_implementacion(imp) {};

	// M�todo virtual puro que las abstracciones refinadas deben implementar.
	virtual void operacion() = 0;

protected:
	// Puntero a la implementaci�n. Permite a las abstracciones refinadas llamar operaciones de implementaci�n.
	Implementacion* m_implementacion;
};

// AbstraccionRefinada hereda de Abstraccion y representa una abstracci�n refinada con operaciones adicionales o modificadas.
class AbstraccionRefinada : public Abstraccion {
public:
	// Constructor que inicializa la clase base Abstraccion con una implementaci�n concreta.
	AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}

	// Sobrescribe el m�todo operacion para delegar la llamada a la implementaci�n concreta.
	void operacion() override {
		m_implementacion->operacion();
	}
};
