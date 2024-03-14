#pragma once
#include "Builder.h"
#include "FactoryMethods.h"
#include "Prototype.h"
#include "Composite.h"
#include "Bridge.h"
#include "Template.h"
#include "ChainsOfResponsability.h"
#include "Proxy.h"
#include "Adapter.h"
#include "Decorator.h"
#include "Singleton.h"

int main() {

	// Singleton
	Singleton* s1 = Singleton::getInstancia();
	s1->setValue(42);

	Singleton* s2 = Singleton::getInstancia();
	cout << "Datos en Singleton 2: " << s2->getValue() << endl;
	cout << "Datos de la instancia: " << Singleton::getInstancia()->getValue() << endl;


	RegistroActividad* a1 = RegistroActividad::getInstancia2();
	a1->setLog("Buenos dias, bienvenido al mundo espacial");
	RegistroActividad* a2 = RegistroActividad::getInstancia2();
	RegistroActividad* a3 = RegistroActividad::getInstancia2();
	a3->setLog("Padrisimo");

	cout << "Ingresando al mundo virtual..." << endl;
	for (const auto& chats : a2->getLog()) {
		cout << chats << endl;
	}

	// Factory Method
	FMFabrica* fabrica = new FMFabricaConcreta();
	FMProducto* producto = fabrica->crearProducto();

	vector <FMProducto*> productos;
	producto->operacion();


	// Factory Method 2
	FMProducto* chettos = fabrica->crearProducto2();
	chettos->registrar("Torciditos", 10.0f, 10.0f);
	chettos->operacion();

	delete fabrica;
	delete producto;
	delete chettos;

	// ACTIVIDAD Factory
	FMFabricaVehiculos* fabricaCoches = new FMFabricaCoches();
	FMVehiculo* coche = fabricaCoches->crearVehiculo();
	coche->descripcion();
	delete coche;
	delete fabricaCoches;

	FMFabricaVehiculos* fabricaBicicletas = new FMFabricaBicicletas();
	FMVehiculo* bicicleta = fabricaBicicletas->crearVehiculo();
	bicicleta->descripcion();
	delete bicicleta;
	delete fabricaBicicletas;


	// Builder
	Builder* builder = new BuilderConcreto();
	Director director(builder);

	director.construir();

	BPProduct* product = builder->obtenerProducto();
	product->mostrar();

	delete builder;
	delete product;

	// ACTIVIDAD Builder
	DirectorPizza directorPizza;
	ConstructorPizzaHawaiana constructorHawaiana;
	ConstructorPizzaVegetariana constructorVegetariana;

	directorPizza.setConstructor(&constructorHawaiana);
	Pizza* pizzaHawaiana = directorPizza.construirPizza();
	pizzaHawaiana->mostrar();

	directorPizza.setConstructor(&constructorVegetariana);
	Pizza* pizzaVegetariana = directorPizza.construirPizza();
	pizzaVegetariana->mostrar();

	// Eliminar
	delete pizzaHawaiana;
	delete pizzaVegetariana;



	// Prototype
	Prototype* prototipo = new PrototypeConcreto();
	prototipo->configurar("Ejemplo");

	Prototype* copia = prototipo->clonar();
	copia->mostrar();
	prototipo->mostrar();

	delete prototipo;
	delete copia;

	// ACTIVIDAD Prototype
	DocumentoPrototype* prototipoDocumento = new DocumentoConcreto();
	prototipoDocumento->configurar("Documento de ejemplo");

	DocumentoPrototype* copiaDocumento = prototipoDocumento->clonar();
	copiaDocumento->mostrar();
	prototipoDocumento->mostrar();

	delete prototipoDocumento;
	delete copiaDocumento;

	DocumentoPrototype* prototipoDocumento = new ImagenConcreto();
	prototipoDocumento->configurar("Imagen de ejemplo");

	DocumentoPrototype* copiaDocumento = prototipoDocumento->clonar();
	copiaDocumento->mostrar();
	prototipoDocumento->mostrar();

	delete prototipoDocumento;
	delete copiaDocumento;


	// ChainsOfResponsability
	manejadorConcretoC handleC(nullptr);
	manejadorConcretoB handleB(&handleC);
	manejadorConcretoA handleA(&handleB);

	handleA.manejarSolicitud(50);
	handleA.manejarSolicitud(5);
	handleA.manejarSolicitud(15);
	handleA.manejarSolicitud(19);
	handleA.manejarSolicitud(3);


	// ACTIVIDAD ChainsOfResponsability
	manejadorDirectorGeneral directorGeneral(nullptr);
	manejadorGerente gerente(&directorGeneral);
	manejadorDirectivo directivo(&gerente);
	directivo.getMonto(800);
	directivo.getMonto(3500);
	directivo.getMonto(10000);


	// Template
	Juego* juego1 = new Ajedrez();
	Juego* juego2 = new Monopoly();

	juego1->jugar();
	juego2->jugar();

	delete juego1;
	delete juego2;


	// ACTIVIDAD Template
	Refrigerador* refri1 = new RefrigeradorSamsung;
	Refrigerador* refri2 = new RefrigeradorLG;
	refri1->jugar();
	refri2->jugar();
	delete refri1;
	delete refri2;


	// Composite
	Leaf* leaf1 = new Leaf();
	Leaf* leaf2 = new Leaf();

	Compuesto* compuesto = new Compuesto();
	compuesto->agregarLeaf(leaf1);
	compuesto->agregarLeaf(leaf2);

	compuesto->operacion();

	delete leaf1;
	delete leaf2;
	delete compuesto;


	// ACTIVIDAD Composite
	SistemaArchivo* archivo1 = new SistemaArchivo();
	SistemaArchivo* archivo2 = new SistemaArchivo();
	SistemaCarpeta* carpeta = new SistemaCarpeta();

	carpeta->agregarSistema(archivo1);
	carpeta->agregarSistema(archivo2);

	carpeta->mostrarInfo();

	delete archivo1;
	delete archivo2;
	delete carpeta;


	// Bridge
	ImplementacionConcretaA impA;
	ImplementacionConcretaB impB;

	AbstraccionRefinada ARA(&impA);
	AbstraccionRefinada ARB(&impB);

	ARA.operacion();
	ARB.operacion();


	// Proxy
	Proxy proxy;
	proxy.operacion();
	proxy.operacion();


	// Adapter
	InterfazVieja* objetoViejo = new InterfazVieja();
	InterfazNueva* objetoNuevo = new Adapter(objetoViejo);

	objetoNuevo->metodoNuevo();

	delete objetoViejo;
	delete objetoNuevo;


	// Decorator

	// Por cada que pasa se agrega una "decoracion"
	ComponenteConcreto* obj = new ComponenteConcreto();
	DecoratorConcretoA* DecoratorA = new DecoratorConcretoA(obj);
	DecoratorConcretoB* DecoratorB = new DecoratorConcretoB(DecoratorA);

	obj->operacion();
	DecoratorA->operacion();
	DecoratorB->operacion();

	delete obj;
	delete DecoratorA;
	delete DecoratorB;


	// ACTIVIDAD Decorator
	Cafeteria* cafeteria = new Cafeteria();
	Leche* cafeConLeche = new Leche(cafeteria);
	Azucar* cafeConAzucar = new Azucar(cafeteria);

	cafeteria->prepararCafe();
	cafeConLeche->prepararCafe();
	cafeConAzucar->prepararCafe();

	delete cafeteria;
	delete cafeConLeche;
	delete cafeConAzucar;

	return 0;
}