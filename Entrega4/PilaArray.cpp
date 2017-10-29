#ifndef PILAARRAY_CPP
#define PILAARRAY_CPP

#include "PilaArray.h"
#include "IteradorPilaArray.h"
//PRE: -
//POS: Construye la pila
template <class T>
PilaArray<T>::PilaArray() {

}
//PRE: -
//POS: Construye la pila
template <class T>
PilaArray<T>::PilaArray(int t) {
	arrayDePila = Array<T> (t);
	tamano = t;
	posicion = -1;
}

// Coloca el elemento e en el tope
//Precondicion: La pila no esta llena
//Poscondicion: Se insterta el elemento en la pila
template <class T>
void PilaArray<T>::Push(const T& e) {
	posicion = posicion + 1;
	arrayDePila[posicion] = e;
}

//Precondicion: el array no es vacio
//Poscondicion: Devuelve el array clonado
template <class T>
Array<T> PilaArray<T>::ClonarArray(const Array<T>& original) const {
	Array<T> devolver(tamano);
	Array<T>::Copiar(original, devolver, 0);
	return devolver;
}

// Retorna el tope de la pila
//Precondicion: la pila no es vacia
//Poscondicion: devuelve el elemento en el tope de la pila
template <class T>
const T& PilaArray<T>::Top() const {
	return arrayDePila[posicion];
}

// Borra el tope de la pila
//Precondicion: la pila no es vacia
//Poscondicion: borra el elemento en el tope de la pila
template <class T>
void PilaArray<T>::Pop() {
	posicion = posicion - 1;
}

// PREDICADOS

// Retorna true si y solo si la lista esta llena
//PRE: -
//Poscondicion: devuelve true si la pila esta llena
template <class T>
bool PilaArray<T>::EstaLlena() const {
	if (tamano == posicion + 1) {
		return true;
	}
	else {
		return false;
	}
}

// Retorna true si y solo si la lista esta vacia
// PRE: -
//Poscondicion: devuelve true si la pila esta vacia
template <class T>
bool PilaArray<T>::EstaVacia() const {
	if (posicion == -1) {
		return true;
	}
	else {
		return false;
	}
}

//Retorna un clon de la pila que no comparte memoria con ella
//Precondicion: la pila no es vacia
//Poscondicion: devuelve un clon de la pila que no comparte memoria con ella
template <class T>
Puntero<Pila<T>> PilaArray<T>::Clon() const {
	Array<T> devolver(tamano);
	Array<T>::Copiar(arrayDePila, devolver, 0);
	Puntero<PilaArray<T>> pilaDevolver = new PilaArray();
	pilaDevolver->arrayDePila = devolver;
	pilaDevolver->tamano = tamano;
	pilaDevolver->posicion = posicion;
	return pilaDevolver;
}

//Retorna el iterador para recorrer la pila
//PRE: -
//Poscondicion: devuelve el iterador de la pila
template <class T>
Iterador<T> PilaArray<T>::ObtenerIterador() const {
	return new IteradorPilaArray<T>(ClonarArray(this->arrayDePila),tamano,posicion);
}

#endif