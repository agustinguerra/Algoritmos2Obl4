#ifndef ITERADORHASHABIERTO_CPP
#define ITERADORHASHABIERTO_CPP

#include "IteradorHashAbierto.h"

//Poscondicion: construye el iterador al hash abierto
template <class C, class V>
IteradorHashAbierto<C, V>::IteradorHashAbierto(const ListaOrdImp<Tupla<C, V>>& iterable, int lar, int pos) {
	this->inicio = iterable;
	this->listaL = iterable;
	this->posicionActual = pos;
	this->largo = lar;
}
//Poscondicion: construye el iterador al hash abierto
template <class C, class V>
IteradorHashAbierto<C, V>::IteradorHashAbierto(const ListaOrdImp<Tupla<C, V>>& iterable) {
	this->inicio = iterable;
	this->listaL = iterable;
	this->posicionActual = 0;
	this->largo = 0;
}
//Poscondicion: devuelve true si la hash abierto tiene algun elemento. False en el caso contrario
template <class C, class V>
bool IteradorHashAbierto<C, V>::HayElemento() const {
	if (posicionActual == largo) {
		return false;
	}
	else {
		return true;
	}
}
//Precondicion: La hash abierto no esta vacia
//Poscondicion: devuelve el dato en la posicion actual
template <class C, class V>
const V& IteradorHashAbierto<C, V>::ElementoActual() const {
	return this->listaL->Obtener(posicionActual).Dato1;
}
//Precondicion: La hash abierto no esta vacia
//Poscondicion: avanza en la hash abierto
template <class C, class V>
void IteradorHashAbierto<C, V>::Avanzar() {
	this->posicionActual = this->posicionActual + 1;
}
//Pre: -
//Poscondicion: Reinicia el iterador a la posicion primera
template <class C, class V>
void IteradorHashAbierto<C, V>::Reiniciar() {
	this->posicionActual = 0;
}
//Pre: -
//Poscondicion: clona el iterador
template <class C, class V>
Puntero<Iteracion<Tupla<C,V>>> IteradorHashAbierto<C, V>::Clonar() const {
	return Puntero<Iteracion<T>>(new IteradorHashAbierto(this->inicio,this->largo,0));
}

#endif