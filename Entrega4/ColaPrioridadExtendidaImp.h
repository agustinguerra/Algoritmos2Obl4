#pragma once

#include "ColaPrioridadExtendida.h"
#include "Tupla.h"
#include "FuncionHash.h"
#include "Array.h"

template <class T, class P>
class ColaPrioridadExtendidaImp : public ColaPrioridadExtendida<T,P> {
public:
	~ColaPrioridadExtendidaImp() {}

	//PRE: Existen ambas posiciones
	//POS: Swapea las dos posiciones
	void swap(int i1, int i2);

	// PRE: -
	// POS: Crea la cola prioridad
	ColaPrioridadExtendidaImp(Puntero<FuncionHash<T>> fHash, const Comparador<T>& compT, const Comparador<P>& compP);

	// PRE: -
	// POS: Inserta el elemento e con prioridad p
	void InsertarConPrioridad(const T& e, const P& p) override;

	// PRE: La cola de prioridad no está vacía
	// POS: Retorna el elemento de mayor prioridad en la cola eliminándolo
	T EliminarElementoMayorPrioridad() override;

	// PRE: La cola no está vacía
	// POS: Retorna el elemento de mayor prioridad en la cola sin eliminarlo
	const T& ObtenerElementoMayorPrioridad() const override;

	// PRE: El elemento e pertenece a la cola.
	// POS: Retorna una tupla que contiene al elemento e y su prioridad.
	Tupla<T, P> ObtenerElementoYPrioridad(const  T& e) override;

	// PRE: -
	// POS: Retorna el largo de la cola de prioridad
	nat Largo() const override;

	// PRE: -
	// POS: Retorna true si y solo si el elemento e pertenece a la cola.
	bool Pertenece(const T& e) const override;

	//PRE: Hay elemento en la posicion
	//POS: Devuelve la cp sin ese elemento
	void eliminarEnPosicion(int pos);

	// PRE: El elemento e pertenece a la cola.
	// POS: El elemento e tiene una nueva prioridad p.
	void CambiarPrioridad(const T& e, const P& p) override;

	// PRE: El elemento e pertenece a la cola.
	// POS: El elemento e no pertenece a la cola.
	void EliminarElemento(T& e) override;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta vacia
	bool EstaVacia() const override;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta llena
	bool EstaLlena() const override;

	// PRE: -
	// POS: La cola esta vacía
	void Vaciar() override;

	// PRE: -
	// POS: Retorna un clon de la cola que no comparte memoria con ella
	Puntero<ColaPrioridadExtendida<T, P>> Clon() const override;

	//Retorna el iterador para recorrer la PQ
	Iterador<Tupla<T,P>> ObtenerIterador() const override;

private:
	Array<Tupla<T, P>> heap;
	int largo;
	Comparador<T> compT;
	Comparador<P> compP;
	Puntero<FuncionHash<T>> funcH;
};

#include "ColaPrioridadExtendidaImp.cpp"