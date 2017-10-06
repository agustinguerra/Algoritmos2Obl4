#ifndef GRAFO_H
#define GRAFO_H

#include "Iterable.h"
#include "FuncionHash.h"
#include "FuncionCosto.h"
#include "Tupla.h"
#include "Array.h"

enum TipoConexo 
{
	NO_CONEXO, DEBILMENTE_CONEXO, FUERTEMENTE_CONEXO
};

typedef unsigned int nat;

template <class V, class A>
class Grafo abstract 
{
public:
	virtual ~Grafo() {}
	// CONSTRUCTORAS

	virtual void AgregarVertice(const V& v) abstract;
	virtual void BorrarVertice(const V& v) abstract;
	virtual void AgregarArco(const V& v1, const V& v2, const A& arco) abstract;
	virtual void BorrarArco(const V& v1, const V& v2) abstract;

	// SELECTORAS y PREDICADOS

	virtual Iterador<V> Vertices() const abstract;
	virtual Iterador<V> Adyacentes(const V& v) const abstract;
	virtual Iterador<V> Incidentes(const V& v) const abstract;

	virtual const A& ObtenerArco(const V& v1, const V& v2) const abstract;
	virtual nat CantidadVertices() const abstract;
	virtual nat CantidadArcos() const abstract;
	virtual nat CantidadAdyacentes(const V& v) const abstract;
	virtual nat CantidadIncidentes(const V& v) const abstract;
	
	virtual bool ExisteVertice(const V& v) const abstract;
	virtual bool ExisteArco(const V& v1, const V& v2) const abstract;
	virtual bool EstaLleno() const abstract;
	virtual bool EstaVacio() const abstract;

	virtual bool HayCamino(const V& vO, const V& vD) const abstract;
	virtual	TipoConexo EsConexo() const abstract;
	virtual	Iterador<V> OrdenTopologico() const abstract;
	virtual Iterador<Tupla<V, V>> ArbolCubrimientoMinimo(const FuncionCosto<V, A>& costo = FuncionCosto<V, A>::Default) const abstract;
	virtual Iterador<Iterador<V>> ComponentesConexas() const abstract;
};

#endif