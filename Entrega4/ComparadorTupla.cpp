#ifndef COMPARADORTUPLA_CPP
#define COMPARADORTUPLA_CPP

#include "ComparadorTupla.h"

//Pre: -
//Pos:  Devuelve el CompRetorno
template <class C, class V>
CompRetorno ComparadorTupla<C, V>:: Comparar(const Tupla<C, V>& t1, const Tupla<C, V>& t2) const {
	if (comparador.Comparar(t1.ObtenerDato1(), t2.ObtenerDato1()) == MAYOR) {
		return MAYOR;
	}
	if (comparador.Comparar(t1.ObtenerDato1(), t2.ObtenerDato1()) == MENOR) {
		return MENOR;
	}
	if (comparador.Comparar(t1.ObtenerDato1(), t2.ObtenerDato1()) == IGUALES) {
		return IGUALES;
	}
	if (comparador.Comparar(t1.ObtenerDato1(), t2.ObtenerDato1()) == DISTINTOS) {
		return DISTINTOS;
	}
	return DISTINTOS;
}

#endif