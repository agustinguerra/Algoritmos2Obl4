#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include "GrafoImp.h"

template <class V, class A>
Tupla<TipoRetorno, Puntero<Grafo<V, A>>> Sistema::CrearGrafo(nat maxVertices, Puntero<FuncionHash<V>> funcionHash, const Comparador<V>& comp)
{
	//return Tupla<TipoRetorno, Puntero<Grafo<V, A>>>(NO_IMPLEMENTADA, nullptr);

	Puntero <Grafo<V, A>> response = new GrafoImp<V, A>(maxVertices, funcionHash, comp);
	return Tupla<TipoRetorno, Puntero<Grafo<V, A>>>(OK, response);
}


#endif