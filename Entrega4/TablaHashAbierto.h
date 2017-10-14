#pragma once

#include "Tupla.h"
#include "Tabla.h"
#include "Array.h"
#include "ListaOrdImp.h"
#include "FuncionHash.h"
#include "ComparadorTupla.h"

template <class C, class V>
class TablaHashAbierto : public Tabla<C, V>{
public:
	~TablaHashAbierto() { }

	/* CONSTRUCTORAS */


	//PRE: -
	//POS: Construye el hash
	TablaHashAbierto(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C> comp);

	//PRE: T(c) no está definida y la tabla no está llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v) override;

	//PRE: T(c) está definida
	//POS: Borra la asociación ligada a 'c'
	void Borrar(const C& c) override;

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos() override;

	/* PREDICADOS */

	//Pre: -
	//Pos: Devuelve el siguiente numero primo
	int sigPrimo(int num);

	//PRE: - 
	//POS: Retorna true si está vacía, false sino.
	bool EstaVacia() const override;

	//PRE: - 
	//POS: Retorna true si está llena, false sino.
	bool EstaLlena() const override;

	//PRE: - 
	//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
	bool EstaDefinida(const C& c) const override;

	//Pre: n mayor que 1
	//Pos: devuelve true si el numero dado es primo
	bool esPrimo(int n);

	/* SELECTORAS */
	//PRE: -
	//POS: devuelve la lista de una cubeta dada
	Puntero<ListaOrdImp<Tupla<C, V>>> devuelvoLista(const C& c);

	//PRE: T(c) está definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const override;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const override;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const override;

	//PRE: -
	//POS: Devuelve el iterador
	Iterador<Tupla<C,V>> ObtenerIterador() const override;

private:
	Array<Puntero<ListaOrdImp<Tupla<C, V>>>> laTabla;
	Puntero<FuncionHash<C>> pFunc;
	int tamano;
	int ocupados;
	int largo;
	Comparador<C> comparador;
	Comparador<Tupla<C, V>> elComparador;
};

#include "TablaHashAbierto.cpp"