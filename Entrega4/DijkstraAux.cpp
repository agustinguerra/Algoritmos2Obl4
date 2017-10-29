#ifndef DijkstraAux_cpp
#define DijkstraAux_cpp

#include "DijkstraAux.h"

template <class V, class Costos>
DijkstraAux<V,Costos>::DijkstraAux(const V& vengoDe, const Costos& arco)
{
	this->vengoDe = vengoDe;
	this->esConocido = false;
	this->costoA = arco;
}

template <class V, class Costos>
DijkstraAux<V,Costos>::DijkstraAux()
{
	this->vengoDe = V();
	this->costoA = Costos();
	this->esConocido = false;
}


#endif