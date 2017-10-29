#pragma once

#include "GrafoImp.h"
#include "DijkstraAux.h"

template<class V, class A, class Costos>
class Dijkstra
{
public:
	Dijkstra(Puntero<Grafo<V, A>> gr, Comparador<Costos> compC, Comparador<V> cv, Puntero<FuncionHash<V>> funcionHash, Costos(*fCosto)(Puntero <Grafo<V, A>>, V, V));
	Iterador<V> doDijkstra(V origen, V destino);
	void performAlg(V origen);

private:
	
	Puntero <Grafo<V, A>> grafo;
	Array<DijkstraAux<V, Costos>> laTabla;
	Comparador<Costos> compCostos;
	Comparador<V> compV;

	Costos(*getCosto)(Puntero <Grafo<V, A>>, V, V);
	Puntero<FuncionHash<V>> funcHash;
};


#include "Dijkstra.cpp"