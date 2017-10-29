#ifndef COSTOS_CPP
#define COSTOS_CPP


#include "Costos.h"

#define MAX 9999999

Costos::Costos()
{
	omnibus = MAX;
	avion = MAX;
	costo = MAX;
	tiempo = MAX;
	paradas = MAX;
	ciudades = MAX;
}

Costos::Costos(int avion, int omnibus, int costo, int tiempo, int paradas,int ciudades)
{
	this->avion = avion;
	this->omnibus = omnibus;
	this->ciudades = ciudades;
	this->costo = costo;
	this->tiempo = tiempo;
	this->paradas = paradas;
}

Costos Costos::Cero()
{
	return Costos(0, 0, 0, 0, 0, 0);
}

Costos Costos::Maximo()
{
	return Costos(MAX, MAX, MAX, MAX, MAX,MAX);
}

Costos Costos::operator+(const Costos& c) const {
		Costos total(avion + c.avion, omnibus + c.omnibus, costo + c.costo, tiempo + c.tiempo, paradas + c.paradas,ciudades+1);
		return total;
}

#endif