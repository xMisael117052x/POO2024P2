#pragma once
#include "Prerequisites.h"

// Interfaz del sujeto
// Define las operaciones que tanto el Proxy como el SujetoReal deben implementar.
class Sujeto {
public:
    // Método virtual puro que debe ser implementado por las clases derivadas.
    virtual void operacion() = 0;
};

// Sujeto real (Clase concreta)
// Implementa la interfaz Sujeto, proporcionando la funcionalidad real que el Proxy controlará.
class SujetoReal : public Sujeto {
public:
    // Implementación concreta de la operación definida en la interfaz Sujeto.
    void operacion() override {
        cout << "Operación en el sujeto real." << endl;
    }
};

// Proxy
// Actúa como un sustituto del SujetoReal, controlando el acceso a este.
class Proxy : public Sujeto {
public:
    // Constructor del Proxy. Inicializa el puntero al SujetoReal con nullptr.
    Proxy() : m_sujetoReal(nullptr) {};

    // Sobreescritura del método operacion. Controla el acceso al SujetoReal.
    void operacion() override {
        // Si m_sujetoReal no ha sido creado aún, lo crea.
        if (m_sujetoReal == nullptr) {
            m_sujetoReal = new SujetoReal();
            cout << "Se creó el objeto SujetoReal." << endl;
        }
        // Mensaje indicando que la operación se está llevando a cabo a través del proxy.
        cout << "Operación en el Proxy. Redirigiendo a sujeto real." << endl;
        // Redirige la llamada al método operacion del SujetoReal.
        m_sujetoReal->operacion();
    }

private:
    // Puntero al SujetoReal. Se usa para acceder al SujetoReal cuando sea necesario.
    SujetoReal* m_sujetoReal;
};