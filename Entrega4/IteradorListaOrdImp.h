#pragma once

#include "ListaOrd.h"
#include "Iterador.h"
#include "ListaOrdImp.h"

template <class T>
class IteradorListaOrdImp : public Iteracion<T> {
public:
	//Poscondicion: destruye la IteradorListaOrdImp
	~IteradorListaOrdImp() {}
	//Poscondicion: construye el iterador a la ListaOrdImp
	IteradorListaOrdImp(const NodoLista<T>& iterable, int cantidadActual);
	//Poscondicion: construye el iterador a la ListaOrdImp
	IteradorListaOrdImp(const Puntero<NodoLista<T>>& iterable);
	//Poscondicion: devuelve true si la ListaOrdImp tiene algun elemento. False en el caso contrario
	bool HayElemento() const override;
	//Precondicion: La ListaOrdImp no esta vacia
	//Poscondicion: devuelve el dato en la posicion actual
	const T& ElementoActual() const override;
	//Precondicion: La ListaOrdImp no esta vacia
	//Poscondicion: avanza en la ListaOrdImp
	void Avanzar() override;
	//Pre: -
	//Poscondicion: Reinicia el iterador a la posicion primera
	void Reiniciar() override;
	//Pre: -
	//Poscondicion: clona el iterador
	Puntero<Iteracion<T>> Clonar() const  override;


private:
	Puntero<NodoLista<T>> inicio;
	Puntero<NodoLista<T>> listaL;
	int cantidadActual;
};


#include "IteradorListaOrdImp.cpp"