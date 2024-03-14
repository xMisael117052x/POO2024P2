#pragma once
#include "Prerequisites.h"


// manejador Base (Handle)
class Manejador {
public:
	Manejador(Manejador* siguiente) : m_siguienteManejador(siguiente) {}

	virtual void manejarSolicitud(int solicitud) {
		if (m_siguienteManejador != nullptr) {
			m_siguienteManejador->manejarSolicitud(solicitud);
		}
	}
private:
	Manejador* m_siguienteManejador;
};

// manejador concreto A
class manejadorConcretoA : public Manejador {
public:
	manejadorConcretoA(Manejador* siguiente) :Manejador(siguiente) {}

	void manejarSolicitud(int solicitud) override {
		if (solicitud <= 10) {
			cout << "Manejador A ejecuta la solicitud." << endl;
		}
		else {
			Manejador::manejarSolicitud(solicitud);
		}
	}
};

// manejador concreto B
class manejadorConcretoB : public Manejador {
public:
	manejadorConcretoB(Manejador* siguiente) :Manejador(siguiente) {}

	void manejarSolicitud(int solicitud) override {
		if (solicitud <= 20) {
			cout << "Manejador B ejecuta la solicitud." << endl;
		}
		else {
			Manejador::manejarSolicitud(solicitud);
		}
	}
};

// manejador concreto C
class manejadorConcretoC : public Manejador {
public:
	manejadorConcretoC(Manejador* siguiente) :Manejador(siguiente) {}

	void manejarSolicitud(int solicitud) override {
		cout << "Manejador C ejecuta la solicitud" << endl;
	}
};


// ACTIVIDAD

class Solicitud {
public:
	Solicitud(Solicitud* siguiente) : m_monto(siguiente) {}

	virtual void getMonto(int solicitud) {
		if (m_monto != nullptr) {
			m_monto->getMonto(solicitud);
		}
	};
private:
	Solicitud* m_monto;
};

class manejadorDirectivo : public Solicitud {
public:
	manejadorDirectivo(Solicitud* siguiente) :Solicitud(siguiente) {}

	void getMonto(int solicitud) override {
		cout << "El Directo Creativo esta revisando y confirmando el monto de " << solicitud << endl;
		if (solicitud < 1000) {
			cout << "El Directo Creativo La ha aceptado " << solicitud << endl;
		}
		else {
			cout << "El Directo Creativo esta revisando y confirmando el monto de " << solicitud << endl;
			Solicitud::getMonto(solicitud);
		}
	}
};

class manejadorGerente : public Solicitud {
public:
	manejadorGerente(Solicitud* siguiente) :Solicitud(siguiente) {}

	void getMonto(int solicitud) override {
		cout << "El Gerente en turno esta revisando y confirmando el monto de " << solicitud << endl;
		if (solicitud < 5000) {
			cout << "El Gerente en turno la ha acepto:  " << solicitud << endl;
		}
		else {
			cout << "El Gerente en turno lo ha rechazado, pasa al siguiente nivel" << endl;
			Solicitud::getMonto(solicitud);
		}
	}
};

class manejadorDirectorGeneral : public Solicitud {
public:
	manejadorDirectorGeneral(Solicitud* siguiente) :Solicitud(siguiente) {}

	void getMonto(int solicitud) override {
		cout << "El Gerente General esta revisando y confirmando el monto de " << solicitud << endl;
	}
};