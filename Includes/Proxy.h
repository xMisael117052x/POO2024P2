#pragma once
#include "Prerequisites.h"

// Interfaz del sujeto
// Define las operaciones que tanto el Proxy como el SujetoReal deben implementar.
class Sujeto {
public:
    // M�todo virtual puro que debe ser implementado por las clases derivadas.
    virtual void operacion() = 0;
};

// Sujeto real (Clase concreta)
// Implementa la interfaz Sujeto, proporcionando la funcionalidad real que el Proxy controlar�.
class SujetoReal : public Sujeto {
public:
    // Implementaci�n concreta de la operaci�n definida en la interfaz Sujeto.
    void operacion() override {
        cout << "Operaci�n en el sujeto real." << endl;
    }
};

// Proxy
// Act�a como un sustituto del SujetoReal, controlando el acceso a este.
class Proxy : public Sujeto {
public:
    // Constructor del Proxy. Inicializa el puntero al SujetoReal con nullptr.
    Proxy() : m_sujetoReal(nullptr) {};

    // Sobreescritura del m�todo operacion. Controla el acceso al SujetoReal.
    void operacion() override {
        // Si m_sujetoReal no ha sido creado a�n, lo crea.
        if (m_sujetoReal == nullptr) {
            m_sujetoReal = new SujetoReal();
            cout << "Se cre� el objeto SujetoReal." << endl;
        }
        // Mensaje indicando que la operaci�n se est� llevando a cabo a trav�s del proxy.
        cout << "Operaci�n en el Proxy. Redirigiendo a sujeto real." << endl;
        // Redirige la llamada al m�todo operacion del SujetoReal.
        m_sujetoReal->operacion();
    }

private:
    // Puntero al SujetoReal. Se usa para acceder al SujetoReal cuando sea necesario.
    SujetoReal* m_sujetoReal;
};