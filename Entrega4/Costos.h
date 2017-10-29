#pragma once

class Costos
{
public:

	Costos();

	Costos(int avion, int omnibus, int costo, int tiempo, int paradas,int ciudades);

	static Costos Cero();

	static Costos Maximo();

	Costos operator+(const Costos& c) const;

	int paradas;
	int avion;
	int omnibus;
	int tiempo;
	int ciudades;
	int costo;
};
