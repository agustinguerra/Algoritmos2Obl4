#pragma once

#include "Pila.h"
#include "PilaArray.h"
#include "Iteracion.h"

template <class T>
class IteradorPilaArray : public Iteracion<T> {
public:
	~IteradorPilaArray() {}
	//Pre: -
	//Poscondicion: Devuelve un iterador a la PilaArray
	IteradorPilaArray(const Array<T>& iterable, int tamano, int posicion);
	//Pre: -
	//Poscondicion: Devuelve un iterador a la PilaArray
	IteradorPilaArray(const Array<T>& iterable);
	//Pre: -
	//Poscondicion: devuelve true si hay un elemento en la posicion actual del iterador, false en lo contrario.
	bool HayElemento() const override;
	//Precondicion: Hay un elemento en la posicion actual
	//Poscondicion: Devuelve el elemento actual
	const T& ElementoActual() const override;
	//Precondicion: Hay un elemento en la posicion actual
	//Poscondicion: avanza el iterador
	void Avanzar() override;
	//Pre: -
	//Poscondicion: reinicia al iterador a la posicion inicial
	void Reiniciar() override;
	//Pre: -
	//Poscondicion: clona el iterador
	Puntero<Iteracion<T>> Clonar() const  override;

private:
	Array<T> arrayPila;
	int tamano;
	int posicion;
	int inicio;
};

#include "IteradorPilaArray.cpp"