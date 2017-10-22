#pragma once

#include "Grafo.h"
#include "ListaOrdImp.h"
#include "TablaHashAbierto.h"
#include "ColaPrioridadExtendidaImp.h"

template <class V, class A>
class GrafoImp : public Grafo<V,A>
{
public:
	~GrafoImp() {}
	// CONSTRUCTORAS

	GrafoImp(int mVertices, Puntero<FuncionHash<V>> funcH, const Comparador<V>& comp) ;

	void AgregarVertice(const V& v) override;
	void BorrarVertice(const V& v) override;
	void AgregarArco(const V& v1, const V& v2, const A& arco) override;
	void BorrarArco(const V& v1, const V& v2) override;

	// SELECTORAS y PREDICADOS

	
	const int GetPosVertice(const V& v) const;


	Iterador<V> Vertices() const override;
	Iterador<V> Adyacentes(const V& v) const override;
	Iterador<V> Incidentes(const V& v) const override;

	const A& ObtenerArco(const V& v1, const V& v2) const override;
	nat CantidadVertices() const override;
	nat CantidadArcos() const override;
	nat CantidadAdyacentes(const V& v) const override;
	nat CantidadIncidentes(const V& v) const override;

	bool ExisteVertice(const V& v) const override;
	bool ExisteArco(const V& v1, const V& v2) const override;
	bool EstaLleno() const override;
	bool EstaVacio() const override;

	void dfsUtil(int vO, Array<bool> visitados) const;
	bool HayCamino(const V& vO, const V& vD) const override;
	TipoConexo EsConexo() const override;
	Iterador<V> OrdenTopologico() const override;
	Iterador<Tupla<V, V>> ArbolCubrimientoMinimo(const FuncionCosto<V, A>& costo = FuncionCosto<V, A>::Default) const override;
	Iterador<Iterador<V>> ComponentesConexas() const override;

private:
	Array<Tupla<V,Puntero<ListaOrdImp<Tupla<V,A>>>>> listaAdy; //Lista de adyacencia, donde van las aristas
	Array<V> tablaArr; //Array de vertices
	Puntero<Tabla<V, int>> tablaHash; //Tabla hash que dice donde esta cada vertice
	Puntero<FuncionHash<V>> fHash;  //Funcion Hash
	int cantVertices;
	const Comparador<V> comp;
};

#include "GrafoImp.cpp"