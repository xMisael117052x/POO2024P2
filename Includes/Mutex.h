#pragma once

#include "Prerequisites.h"
#include <thread>
#include <mutex>

mutex mtx;

/*
Este patron bloquea el thread que lo ejecuta, hasta que el mutex se desbloquea.
para no corromper los datos, se debe bloquear el mutex antes de acceder a los datos compartidos.
*/
void Hilo(int id) {
	for (int i = 0; i < 5; i++) {
		mtx.lock();//Bloquear el thread
		std::cout << "Hilo: " << id << " esta trabajando." << endl;
		mtx.unlock();// Desbloquear el thread
	}
}


thread hilo1(Hilo, 1);
thread hilo2(Hilo, 2);
thread hilo3(Hilo, 3);


hilo1.join();
hilo2.join();
hilo3.join();

std::cout << "\n--- Ejecucion 1 entre hilos" << endl;
std::cout << "\n--- Ejecucion 2 entre hilos" << endl;
std::cout << "\n--- Ejecucion 3 entre hilos" << endl;

