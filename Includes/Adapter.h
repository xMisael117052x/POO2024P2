#pragma once
#include "Prerequisites.h";

// Define una clase base para una interfaz antigua.
class InterfazVieja {
public:
	// M�todo antiguo que muestra un mensaje cuando se llama.
	virtual void metodoViejo() {
		cout << "Metodo viejo llamado" << endl;
	}
};

// Define una clase base para una interfaz nueva.
class InterfazNueva {
public:
	// M�todo nuevo que muestra un mensaje cuando se llama.
	virtual void metodoNuevo() {
		cout << "Metodo nuevo llamado" << endl;
	}
};

// Define una clase adaptadora que permite usar la interfaz vieja como si fuera la nueva.
class Adapter : public InterfazNueva {
public:
	// Constructor que toma un puntero a la interfaz vieja.
	Adapter(InterfazVieja* vieja) : m_interfazVieja(vieja) {}

	// Implementaci�n del m�todo nuevo que adapta la llamada al m�todo viejo.
	virtual void metodoNuevo() override {
		// Muestra un mensaje indicando que el adaptador est� siendo usado.
		cout << "Adaptador llamado al metodo nuevo" << endl;
		// Llama al m�todo viejo en lugar del nuevo, adaptando la interfaz.
		m_interfazVieja->metodoViejo();
	}

private:
	// Guarda un puntero a la interfaz vieja para poder usar su m�todo.
	InterfazVieja* m_interfazVieja;
};