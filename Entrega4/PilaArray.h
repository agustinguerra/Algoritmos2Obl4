#pragma once

#include "Pila.h"
#include "Array.h"
#include "Puntero.h"
#include <iostream>


template <class T>
class PilaArray : public Pila<T> {
public:
	//PRE: -
	//POS: Destruye la pila
	~PilaArray() {};
	//PRE: -
	//POS: Construye la pila
	PilaArray();

	//PRE: -
	//POS: Construye la pila
	PilaArray(int t);

	// Coloca el elemento e en el tope
	//Precondicion: La pila no esta llena
	//Poscondicion: Se insterta el elemento en la pila
	void Push(const T& e) override;
	//Precondicion: el array no es vacio
	//Poscondicion: Devuelve el array clonado
	Array<T> ClonarArray(const Array<T>& original) const;

	// Retorna el tope de la pila
	//Precondicion: la pila no es vacia
	//Poscondicion: devuelve el elemento en el tope de la pila
	const T& Top() const override;

	// Borra el tope de la pila
	//Precondicion: la pila no es vacia
	//Poscondicion: borra el elemento en el tope de la pila
	void Pop() override;

	// PREDICADOS

	// Retorna true si y solo si la lista esta llena
	//PRE: -
	//Poscondicion: devuelve true si la pila esta llena
	bool EstaLlena() const override;

	// Retorna true si y solo si la lista esta vacia
	// PRE: -
	//Poscondicion: devuelve true si la pila esta vacia
	bool EstaVacia() const override;

	//Retorna un clon de la pila que no comparte memoria con ella
	//Precondicion: la pila no es vacia
	//Poscondicion: devuelve un clon de la pila que no comparte memoria con ella
	Puntero<Pila<T>> Clon() const override;

	//Retorna el iterador para recorrer la pila
	//PRE: -
	//Poscondicion: devuelve el iterador de la pila
	Iterador<T> ObtenerIterador() const override;

private:
	Array<T> arrayDePila;
	int tamano;
	int posicion;
};

#include "PilaArray.cpp"