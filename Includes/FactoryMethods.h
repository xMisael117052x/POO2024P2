#pragma once
#include "Prerequisites.h"


// Clase de productos
class FMProducto {
public:
	virtual void operacion() = 0;
	virtual void registrar(string _nombre, float _peso, float _precio);
};

// Clase base para la fabrica
class FMFabrica {
public:
	virtual FMProducto* crearProducto() = 0;
	virtual FMProducto* crearProducto2() = 0;
};

// Clase concreta del producto
class FMProductoConcreto : public FMProducto {
public:
	void registrar(string _nombre, float _peso, float _precio) override {
	}

	void operacion() override {
		cout << "Operacion en producto concreto" << endl;
	}
};

class FMChettos : public FMProducto {
public:
	string nombre;
	float peso;
	float precio;
public:
	void registrar(string _nombre, float _peso, float _precio) {
		nombre = _nombre;
		peso = _peso;
		precio = _precio;
	}

	void operacion() override {
		cout << "Nombre: " << nombre << ", peso:" << peso << ", precio: $" << precio << endl;
	}
};

// Clase concreta de la fabrica
class FMFabricaConcreta : public FMFabrica {
public:
	FMProducto* crearProducto() override {
		return new FMProductoConcreto();
	}

	FMProducto* crearProducto2() override {
		return new FMChettos();
	}
};

// ACTIVIDAD

// Clase de vehiculos
class FMVehiculo {
public:
	virtual void descripcion() = 0;
};

// Clase base para la fabrica
class FMFabricaVehiculos {
public:
	virtual FMVehiculo* crearVehiculo() = 0;
};

// Clase 'FMCoche' que hereda de 'FMVehiculo'
class FMCoche : public FMVehiculo {
public:
	void descripcion() override {
		cout << "Soy un coche" << endl;
	}
};

// Clase 'FMBicicleta' que hereda de 'FMVehiculo'
class FMBicicleta : public FMVehiculo {
public:
	void descripcion() override {
		cout << "Soy una bicicleta" << endl;
	}
};

// Clase 'FMFabricaCoches' que hereda de 'FMFabricaVehiculos'
class FMFabricaCoches : public FMFabricaVehiculos {
public:
	FMVehiculo* crearVehiculo() override {
		return new FMCoche();
	}
};

// Clase 'FMFabricaBicicletas' que hereda de 'FMFabricaVehiculos'
class FMFabricaBicicletas : public FMFabricaVehiculos {
public:
	FMVehiculo* crearVehiculo() override {
		return new FMBicicleta();
	}
};