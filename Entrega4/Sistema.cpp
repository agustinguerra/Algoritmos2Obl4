#ifndef SISTEMA_CPP
#define SISTEMA_CPP

#include "Sistema.h"

Sistema::Sistema(nat MAX_CIUDADES)
{
}
Sistema::~Sistema()
{
}
TipoRetorno Sistema::AltaCiudad(const Cadena &ciudadNombre)
{
	return NO_IMPLEMENTADA;
}
TipoRetorno Sistema::AltaConexion(const Cadena &ciudadOrigen, const Cadena &ciudadDestino, const TipoTransporte &tipo, const nat &costo, const nat &tiempo, const nat &nroParadas)
{
	return NO_IMPLEMENTADA;
}
Tupla<TipoRetorno, Iterador<Cadena>> Sistema::CaminoMasBarato(const Cadena &ciudadOrigen, const Cadena &ciudadDestino)
{
	return Tupla<TipoRetorno, Iterador<Cadena>>(NO_IMPLEMENTADA, nullptr);
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