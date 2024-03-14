#pragma once
#include "Prerequisites.h"

//Clase base que define el template
class Juego {
public:
	void jugar() {
		inicializar();
		comenzarJuego();
		terminarJuego();
	}
protected:
	virtual void inicializar() {
		cout << "Iniciando el juego..." << endl;
	}
	virtual void comenzarJuego() = 0;

	virtual void terminarJuego() {
		cout << "Terminando el juego!!!!" << endl;
	}
};

//SubClase Que implementa pasos especificos

class Ajedrez : public Juego {
protected:
	void comenzarJuego() override {
		cout << "Comenzar la partida de ajedrez" << endl;
	}
};
//SubClase Que implementa pasos especificos

class Monopoly : public Juego {
protected:
	void comenzarJuego() override {
		cout << "Comenzar la partida de Monopoly" << endl;
	}
};


// ACTIVIDAD

//Clase base del refrigerador
class Refrigerador {
public:
	void jugar() {
		inicializar();
		encender();
		apagar();
	}
protected:
	virtual void inicializar() {
		cout << "Inicializando Refrigerador" << endl;
	}
	virtual void encender() = 0;

	virtual void apagar() {
		cout << "Apagando refrigerador..." << endl;
	}
};

class RefrigeradorSamsung : public Refrigerador {
protected:
	void encender() override {
		cout << "Encendiendo Samsung Refrigereitor" << endl;
	}
};
class RefrigeradorLG : public Refrigerador {
protected:
	void encender() override {
		cout << "Encendiendo LG Refrigereitor" << endl;
	}
};