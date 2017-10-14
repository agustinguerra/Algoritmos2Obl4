#pragma once

#include "Comparacion.h"
#include "Tupla.h"
template <class C,class V>
class ComparadorTupla : public Comparacion<Tupla<C,V>> {
public:
	const Comparador<C> comparador;
	//Pre: -
	//Pos: Crea el comparador
	ComparadorTupla(const Comparador<C>&c) : comparador(c) {  };
	//Pre: -
	//Pos:  Devuelve el CompRetorno
	CompRetorno Comparar(const Tupla<C, V>& t1, const Tupla<C, V>& t2)const override;
};

#include "ComparadorTupla.cpp"