#pragma once

#include "TablaHashAbierto.h"
#include "Iteracion.h"

template <class C,class V>
class IteradorHashAbierto : public Iteracion<Tupla<C,V>> {
public:
	//Poscondicion: destruye el iterador
	~IteradorHashAbierto() {}
	//Poscondicion: construye el iterador al hash abierto
	IteradorHashAbierto(const ListaOrdImp<Tupla<C,V>>& iterable, int lar,int pos);
	//Poscondicion: construye el iterador al hash abierto
	IteradorHashAbierto(const ListaOrdImp<Tupla<C, V>>& iterable);
	//Poscondicion: devuelve true si la hash abierto tiene algun elemento. False en el caso contrario
	bool HayElemento() const override;
	//Precondicion: La hash abierto no esta vacia
	//Poscondicion: devuelve el dato en la posicion actual
	const V& ElementoActual() const override;
	//Precondicion: La hash abierto no esta vacia
	//Poscondicion: avanza en la hash abierto
	void Avanzar() override;
	//Pre: -
	//Poscondicion: Reinicia el iterador a la posicion primera
	void Reiniciar() override;
	//Pre: -
	//Poscondicion: clona el iterador
	Puntero<Iteracion<Tupla<C,V>>> Clonar() const  override;


private:
	Puntero<ListaOrdImp<Tupla<C,V>>> inicio;
	Puntero<ListaOrdImp<Tupla<C, V>>> listaL;
	int largo;
	int posicionActual;
};


#include "IteradorHashAbierto.cpp"