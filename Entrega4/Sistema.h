#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cadena.h"
#include "Tupla.h"
#include "Grafo.h"
#include "FuncionHash.h"
#include "Comparador.h"
#include "TipoRetorno.h"

enum TipoTransporte
{
	OMNIBUS, AVION
};
class Sistema
{
public:
	Sistema(nat MAX_CIUDADES);
	~Sistema();
	template <class V, class A>
	Tupla<TipoRetorno, Puntero<Grafo<V, A>>> CrearGrafo(nat maxVertices, Puntero<FuncionHash<V>>, const Comparador<V>& comp);
	
	// Ejercicio 2: Grafo Ciudades

	TipoRetorno AltaCiudad(const Cadena &ciudadNombre);
	TipoRetorno AltaConexion(const Cadena &ciudadOrigen, const Cadena &ciudadDestino, const TipoTransporte &tipo, const nat &costo, const nat &tiempo, const nat &nroParadas);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMasBarato(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMenorTiempo(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMenosCiudades(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMenosTrayectosOmnibus(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMenosTrayectosAvion(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMenosParadasIntermedias(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
	Tupla<TipoRetorno, Iterador<Cadena>> CaminoMasBaratoOminbus(const Cadena &ciudadOrigen, const Cadena &ciudadDestino);
private:
	
};

#include "SistemaTemplates.cpp"

#endif
