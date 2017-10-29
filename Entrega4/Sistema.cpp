#ifndef SISTEMA_CPP
#define SISTEMA_CPP

#include "Costos.h"
#include "ComparacionCMB.h"
#include "Sistema.h"
#include "Dijkstra.h"

Costos calcular(Puntero<Grafo<Cadena, Tupla<TipoTransporte, int, int, int>>> grafo, Cadena origen, Cadena destino) {
	Tupla<TipoTransporte, int, int, int> arco = grafo->ObtenerArco(origen, destino);
	int avion;
	int omn;
	if (arco.Dato1 == 1) {
		avion = 1;
		omn = 0;
	}
	else {
		avion = 1;
		omn = 0;
	}
	return Costos(avion, omn, arco.Dato2, arco.Dato3, arco.Dato4, 1);
}

Sistema::Sistema(nat MAX_CIUDADES)
{
	this->max_ciudades = MAX_CIUDADES;
	funcHashCadena = new FuncionHashCadena();
	grafo = new GrafoImp<Cadena, Tupla<TipoTransporte, int, int, int>>(max_ciudades, funcHashCadena, Comparador<Cadena>::Default);

}
Sistema::~Sistema()
{
}
TipoRetorno Sistema::AltaCiudad(const Cadena &ciudadNombre)
{
	if (!grafo->ExisteVertice(ciudadNombre)) {
		grafo->AgregarVertice(ciudadNombre);
		return OK;
	}
	else {
		return ERROR;
	}
}
TipoRetorno Sistema::AltaConexion(const Cadena &ciudadOrigen, const Cadena &ciudadDestino, const TipoTransporte &tipo, const nat &costo, const nat &tiempo, const nat &nroParadas)
{
	if (!grafo->ExisteVertice(ciudadOrigen) || !grafo->ExisteVertice(ciudadDestino) || costo==0 || tiempo==0)
		return ERROR;
	grafo->AgregarArco(ciudadOrigen, ciudadDestino, Tupla<TipoTransporte, int, int, int>(tipo, costo, tiempo, nroParadas));
	return OK;
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMasBarato(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	if (!grafo->ExisteVertice(ciudadOrigen) || !grafo->ExisteVertice(ciudadDestino) || !grafo->HayCamino(ciudadOrigen, ciudadDestino)) {
		return Tupla<TipoRetorno, Iterador<Cadena>>(ERROR, nullptr);
	}

	Puntero<Comparacion<Costos>> compAr = new ComparacionCMB();
	Comparador<Costos> compara(compAr);
	Dijkstra<Cadena, Tupla<TipoTransporte, int, int, int>, Costos> dij(grafo, 
		compara, Comparador<Cadena>::Default, funcHashCadena, &calcular);
	return Tupla<TipoRetorno, Iterador<Cadena>>(OK,dij.doDijkstra(ciudadOrigen,ciudadDestino));
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMenorTiempo(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMenosCiudades(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMenosTrayectosOmnibus(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMenosTrayectosAvion(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMenosParadasIntermedias(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMasBaratoOminbus(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
}
#endif