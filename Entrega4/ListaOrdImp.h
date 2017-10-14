#pragma once

#include "ListaOrd.h"
#include "Puntero.h"
#include "ComparadorTupla.h"
#include <iostream>

template <class T>
class NodoLista {
public:
	T dato;
	Puntero<NodoLista<T>> siguiente;
	NodoLista(const T&dato) : dato(dato), siguiente(nullptr) {  };
};

template <class T>
class ListaOrdImp : public ListaOrd<T> {
public:
	~ListaOrdImp() {};

	//PRE: -
	//POS: Construye la lista ordenada
	ListaOrdImp();

	//PRE: -
	//POS: Construye la lista ordenada
	ListaOrdImp(const Comparador<T>& comp);

	// PRE: Está ordenada
	// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
	void ListaOrdImp<T>::insLista(const T& e, Puntero<NodoLista<T>>& l);

	// PRE: Está ordenada
	// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
	void InsertarOrdenado(const T& e) override;

	// PRE: 
	// POS: Inserta el elemento al principio
	void InsertarPrincipio(const T& e);

	// PRE: 
	// POS: Inserta el elemento al final
	void ListaOrdImp<T>::InsertarFinal(const T& e);

	// PRE: La lista no está vacía
	// POS: Retorna el primer elemento de la lista
	const T& Cabeza() const override;

	// PRE: -
	// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acción.
	void Eliminar(const T& e) override;

	// PRE: -
	// POS: Retorna el largo de la lista
	nat Largo() const override;

	// PRE: La lista tiene un elemento en la posición n. 
	// POS: Retorna el elemento que está en esa posición de la lista. El primer elemento empieza en 0.
	const T& Obtener(const nat n) const override;

	// PRE: -
	// POS: Retorna true si y solo si el elemento e pertenece a la lista.
	bool Pertenece(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si la lista esta vacia
	bool EstaVacia() const override;

	// PRE: -
	// POS: Retorna un clon de la lista que no comparte memoria con ella
	Puntero<ListaOrd<T>> Clon() const override;

	//PRE -
	//POS: Devuelve el iterador de la lista
	Iterador<T> ObtenerIterador() const override;

	//PRE: -
	//POS: devuelve el indice del elemento
	int indexOf(const T& e);

private:
	Puntero<NodoLista<T>> lista;
	Comparador<T> comparador;
	int largo;
};

#include "ListaOrdImp.cpp"