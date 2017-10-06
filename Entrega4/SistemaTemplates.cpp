#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"

template <class V, class A>
Tupla<TipoRetorno, Puntero<Grafo<V, A>>> Sistema::CrearGrafo(nat maxVertices, Puntero<FuncionHash<V>> funcionHash, const Comparador<V>& comp)
{
	return Tupla<TipoRetorno, Puntero<Grafo<V, A>>>(NO_IMPLEMENTADA, nullptr);
}


#endif