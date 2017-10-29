#ifndef ITERADORPILAARRAY_CPP
#define ITERADORPILAARRAY_CPP

#include "PilaArray.h"
#include "IteradorPilaArray.h"
#include "Puntero.h"
#include <iostream>
#include <assert.h>
#include <typeinfo.h>

//Pre: -
//Poscondicion: Devuelve un iterador a la PilaArray
template <class T>
IteradorPilaArray<T>::IteradorPilaArray(const Array<T>& iterable, int tamano, int posicion) {
	arrayPila = iterable;
	this->tamano = tamano;
	this->posicion = posicion;
	this->inicio = posicion;
}
//Pre: -
//Poscondicion: Devuelve un iterador a la PilaArray
template <class T>
IteradorPilaArray<T>::IteradorPilaArray(const Array<T>& iterable) {
	arrayPila = iterable;
}
//Pre: -
//Poscondicion: devuelve true si hay un elemento en la posicion actual del iterador, false en lo contrario.
template <class T>
bool IteradorPilaArray<T>::HayElemento() const {
	if (posicion < 0) {
		return false;
	}
	else {
		return true;
	}
}

//Precondicion: Hay un elemento en la posicion actual
//Poscondicion: Devuelve el elemento actual
template <class T>
const T& IteradorPilaArray<T>::ElementoActual() const {
	return arrayPila[posicion];
}

//Precondicion: Hay un elemento en la posicion actual
//Poscondicion: avanza el iterador
template <class T>
void IteradorPilaArray<T>::Avanzar() {
	posicion = posicion - 1;
}
//Pre: -
//Poscondicion: reinicia al iterador a la posicion inicial
template <class T>
void IteradorPilaArray<T>::Reiniciar() {
	this->posicion = this->inicio;
}
//Pre: -
//Poscondicion: clona el iterador
template <class T>
Puntero<Iteracion<T>> IteradorPilaArray<T>::Clonar() const {
	Iteracion<T>* t = new IteradorPilaArray(*this);
	return Puntero<Iteracion<T>>(t);
}



#endif