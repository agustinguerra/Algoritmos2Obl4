#ifndef ITERADORLISTAORDIMP_CPP
#define ITERADORLISTAORDIMP_CPP

#include "ListaOrdImp.h"
#include "IteradorListaOrdImp.h"
#include "Puntero.h"
#include <iostream>
#include <assert.h>
#include <typeinfo.h>

//Pre: -
//Poscondicion: construye el iterador a la ListaOrdImp
template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp(const NodoLista<T>& iterable, int cantidadActual) {
	this->inicio = iterable;
	this->listaL = iterable;
	this->cantidadActual = cantidadActual;
}
//Pre: -
//Poscondicion: construye el iterador a la ListaOrdImp
template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp(const Puntero<NodoLista<T>>& iterable) {
	this->inicio = iterable;
	this->listaL = iterable;
}
//Pre: -
//Poscondicion: devuelve true si la ListaOrdImp tiene algun elemento. False en el caso contrario
template <class T>
bool IteradorListaOrdImp<T>::HayElemento() const {
	if (this->listaL == NULL) {
		return false;
	}
	else {
		return true;
	}
}
//Precondicion: La ListaOrdImp no esta vacia
//Poscondicion: devuelve el dato en la posicion actual
template <class T>
const T& IteradorListaOrdImp<T>::ElementoActual() const {
	return this->listaL->dato;
}
//Precondicion: La ListaOrdImp no esta vacia
//Poscondicion: avanza en la ListaOrdImp
template <class T>
void IteradorListaOrdImp<T>::Avanzar() {
	this->listaL = this->listaL->siguiente;
}
//Pre: -
//Poscondicion: Reinicia el iterador a la posicion primera
template <class T>
void IteradorListaOrdImp<T>::Reiniciar() {
	this->listaL = this->inicio;
}
//Pre: -
//Poscondicion: clona el iterador
template <class T>
Puntero<Iteracion<T>> IteradorListaOrdImp<T>::Clonar() const {
	Iteracion<T>* t = new IteradorListaOrdImp(*this);
	return Puntero<Iteracion<T>>(t);
}


#endif