#pragma once
#include "Prerequisites.h"


class CCcomponent
{
public:
	virtual void operacion() = 0;
};

// Lead (Hojas)
class Leaf : public CCcomponent
{
public:
	void operacion() override {
		cout << "Operacion en la hoja." << endl;
	}
};

// Modo Compuesto (Contenedor)
class Compuesto : public CCcomponent {
public:
	void operacion() override {
		cout << "Operacion en el compuesto. Contiene" << leafs.size() << " hojas." << endl;

		for (CCcomponent* leaf : leafs) {
			leaf->operacion();
		}
	}

	void agregarLeaf(CCcomponent* _leaf) {
		leafs.push_back(_leaf);
	}
private:
	vector<CCcomponent*> leafs;
};


// ACTIVIDAD


// Interfaz 'Sistema' con el método 'mostrarInfo'
class Sistema {
public:
	virtual void mostrarInfo() = 0;
};

// Clase 'Archivo' que implementa 'Sistema'
class Archivo : public Sistema {
public:
	void mostrarInfo() override {
		cout << "Este es un rchivo." << endl;
	}
};

// Clase 'Carpeta' que implementa 'Sistema'
class Carpeta : public Sistema {
public:
	void mostrarInfo() override {
		cout << "Este es una carpeta." << endl;
	}
};

// Clase 'SistemaArchivo' que hereda de 'Archivo' y de 'Sistema'
class SistemaArchivo : public Archivo {
};

// Clase 'SistemaCarpeta' que hereda de 'Carpeta' y de 'Sistema'
class SistemaCarpeta : public Carpeta {

public:
	void agregarSistema(Sistema* _sistema) {
		archivos.push_back(_sistema);
	}

	void mostrarInfo() override {
		cout << "Este es una carpeta con " << archivos.size() << " archivos." << endl;

		for (Sistema* sistema : archivos) {
			sistema->mostrarInfo();
		}
	}

private:
	vector<Sistema*> archivos;
};