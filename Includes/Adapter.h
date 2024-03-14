#pragma once
#include "Prerequisites.h";

// Define una clase base para una interfaz antigua.
class InterfazVieja {
public:
	// Método antiguo que muestra un mensaje cuando se llama.
	virtual void metodoViejo() {
		cout << "Metodo viejo llamado" << endl;
	}
};

// Define una clase base para una interfaz nueva.
class InterfazNueva {
public:
	// Método nuevo que muestra un mensaje cuando se llama.
	virtual void metodoNuevo() {
		cout << "Metodo nuevo llamado" << endl;
	}
};

// Define una clase adaptadora que permite usar la interfaz vieja como si fuera la nueva.
class Adapter : public InterfazNueva {
public:
	// Constructor que toma un puntero a la interfaz vieja.
	Adapter(InterfazVieja* vieja) : m_interfazVieja(vieja) {}

	// Implementación del método nuevo que adapta la llamada al método viejo.
	virtual void metodoNuevo() override {
		// Muestra un mensaje indicando que el adaptador está siendo usado.
		cout << "Adaptador llamado al metodo nuevo" << endl;
		// Llama al método viejo en lugar del nuevo, adaptando la interfaz.
		m_interfazVieja->metodoViejo();
	}

private:
	// Guarda un puntero a la interfaz vieja para poder usar su método.
	InterfazVieja* m_interfazVieja;
};