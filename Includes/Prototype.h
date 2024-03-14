#pragma once
#include "Prerequisites.h"


// Clase base para los prototipos
class Prototype
{
public:
	virtual Prototype* clonar() = 0;
	virtual void configurar(string _valor) = 0;
	virtual void mostrar() = 0;
};

// clase concreta
class PrototypeConcreto : public Prototype
{
public:
	Prototype* clonar() override
	{
		PrototypeConcreto* copia = new PrototypeConcreto();
		copia->configurar(valor);
		return copia;
	}

	void configurar(string _valor) override
	{
		valor = _valor;
	}

	void mostrar() override
	{
		cout << "Valor: " << valor << endl;
	}

private:
	string valor;
};



// Prototipo Base
class DocumentoPrototype {
public:
	virtual DocumentoPrototype* clonar() = 0;
	virtual void configurar(string _contenido) = 0;
	virtual void mostrar() = 0;
};

// Concreto de texto
class DocumentoConcreto : public DocumentoPrototype {

public:
	DocumentoPrototype* clonar() override {
		DocumentoConcreto* copia = new DocumentoConcreto();
		copia->configurar(contenido);
		return copia;
	}

	void configurar(string _contenido) override {
		contenido = _contenido;
	}

	void mostrar()  override {
		cout << "Contenido del documento de texto: " << contenido << endl;
	}

private:
	string contenido;
};

// Concreto de imagen
class ImagenConcreto : public DocumentoPrototype {

public:

	DocumentoPrototype* clonar() override {
		ImagenConcreto* copia = new ImagenConcreto();
		copia->configurar(contenido);
		return copia;
	}

	void configurar(string _contenido) override {
		contenido = _contenido;
	}

	void mostrar()  override {
		cout << "Contenido del documento de imagen: " << contenido << endl;
	}

private:
	string contenido;
};