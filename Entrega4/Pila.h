#ifndef PILA_H
#define PILA_H

#include "Iterable.h"
#include "Puntero.h"

typedef unsigned int nat;

template <class T>
class Pila abstract : public Iterable<T>
{
public:
	virtual ~Pila(){}

	// Coloca el elemento e en el tope
	virtual void Push(const T& e) abstract;

	// Retorna el tope de la pila
	virtual const T& Top() const abstract;

	// Borra el tope de la pila
	virtual void Pop() abstract;	
	
	// PREDICADOS

	// Retorna true si y solo si la lista esta llena
	virtual bool EstaLlena() const abstract;

	// Retorna true si y solo si la lista esta vacia
	virtual bool EstaVacia() const abstract;
	
	//Retorna un clon de la pila que no comparte memoria con ella
	virtual Puntero<Pila<T>> Clon() const abstract;
};


#endif