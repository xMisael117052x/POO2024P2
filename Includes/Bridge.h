#pragma once
#include "Prerequisites.h"

// Clase base para la implementación. Define una interfaz para las operaciones concretas.
class Implementacion {
public:
	// Método virtual puro que las implementaciones concretas deben definir.
	virtual void operacion() = 0;
};

// Implementación concreta A de la clase base de implementación.
class ImplementacionConcretaA : public Implementacion {
public:
	// Sobrescribe el método operacion para realizar una acción específica.
	void operacion() override {
		cout << "Operacion en Implementacion A" << endl;
	}
};

// Implementación concreta B, otra variante de la clase base de implementación.
class ImplementacionConcretaB : public Implementacion {
public:
	// Sobrescribe el método operacion para realizar otra acción específica.
	void operacion() override {
		cout << "Operacion en Implementacion B" << endl;
	}
};

// Clase base Abstraccion. Define la interfaz de abstracción que mantiene una referencia a un objeto de tipo Implementacion.
class Abstraccion {
public:
	// Constructor que toma un puntero a Implementacion para establecer la implementación concreta.
	Abstraccion(Implementacion* imp) : m_implementacion(imp) {};

	// Método virtual puro que las abstracciones refinadas deben implementar.
	virtual void operacion() = 0;

protected:
	// Puntero a la implementación. Permite a las abstracciones refinadas llamar operaciones de implementación.
	Implementacion* m_implementacion;
};

// AbstraccionRefinada hereda de Abstraccion y representa una abstracción refinada con operaciones adicionales o modificadas.
class AbstraccionRefinada : public Abstraccion {
public:
	// Constructor que inicializa la clase base Abstraccion con una implementación concreta.
	AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}

	// Sobrescribe el método operacion para delegar la llamada a la implementación concreta.
	void operacion() override {
		m_implementacion->operacion();
	}
};
