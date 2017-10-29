#pragma once

template <class V, class Costos>
class DijkstraAux
{
public:
	DijkstraAux(const V &vengoDe, const Costos &arco);
	DijkstraAux();
	bool esConocido;
	Costos costoA;
	V vengoDe;
};

#include "DijkstraAux.cpp"