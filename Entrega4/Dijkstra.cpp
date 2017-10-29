#ifndef DIJKSTRA_CPP
#define DIJKSTRA_CPP
#include "Dijkstra.h"

template <class V, class A, class Costos>
Dijkstra<V, A, Costos>::Dijkstra(Puntero<Grafo<V, A>> gr, Comparador<Costos> compC, Comparador<V> cv, Puntero<FuncionHash<V>> funcionHash, Costos(*fCosto)(Puntero <Grafo<V, A>>, V, V)) {
		grafo = gr;
		getCosto = fCosto;
		compCostos = compC;
		funcHash = funcionHash;
		compV = cv;
}

template <class V, class A, class Costos>
void Dijkstra<V, A, Costos>::performAlg(V origen)
{
	Costos costo = Costos();
	Puntero<ColaPrioridadExtendidaImp<V, Costos>> cp = new ColaPrioridadExtendidaImp<V, Costos>(funcHash,compV,compCostos);
	cp->InsertarConPrioridad(origen, costo.Cero());

	while (!cp->EstaVacia())
	{
		V vertAcual = cp->EliminarElementoMayorPrioridad();
		
		Iterador<V> ady = grafo->Adyacentes(vertAcual);

		int posVActual = grafo->GetPosVertice(vertAcual);

		laTabla[posVActual].esConocido = true;

		while (ady.HayElemento())
		{
			V vEM = ady.ElementoActual();
			
			const int posvEM = grafo->GetPosVertice(vEM);
			
			ady.Avanzar();

			if (!laTabla[posvEM].esConocido) {
			
				int adyActual = grafo->GetPosVertice(vEM);

				int posVactual = grafo->GetPosVertice(vertAcual);
				
				Costos costoVertices = getCosto(grafo, vertAcual, vEM);

				if (compCostos.EsMayor(laTabla[adyActual].costoA, laTabla[posVActual].costoA + costoVertices))
				{
					laTabla[adyActual].costoA = laTabla[posVActual].costoA + costoVertices;
					laTabla[adyActual].vengoDe = vertAcual;
				}

				cp->InsertarConPrioridad(vEM, costoVertices);
			}
		}
	}
}

template <class V, class A, class Costos>
Iterador<V> Dijkstra<V, A, Costos>::doDijkstra(V origen, V destino)
{

	//Preparo la tabla para el dijkstra
	Costos costo = Costos();
	laTabla = Array<DijkstraAux<V, Costos>>(grafo->CantidadVertices());
	const int vertOrigen = grafo->GetPosVertice(origen);
	laTabla[vertOrigen].esConocido = true;
	laTabla[vertOrigen].costoA = costo.Cero();

	//Ejecuto el algoritmo, luego me encargo de manejar el resultado
	performAlg(origen);

	int posDestino = grafo->GetPosVertice(destino);

	Puntero<ListaOrdImp<V>> listaFinal = new ListaOrdImp<V>(compV);

	listaFinal->InsertarPrincipio(destino);

	int cantCiudades = 0;
	V vertVengo = laTabla[posDestino].vengoDe;

	while (compV.SonDistintos(origen, vertVengo))
	{
		vertVengo = laTabla[posDestino].vengoDe;
		listaFinal->InsertarPrincipio(vertVengo);
		posDestino = grafo->GetPosVertice(vertVengo);
		cantCiudades++;
	}

	if (cantCiudades == 0)
		listaFinal->InsertarPrincipio(origen);

	return listaFinal->ObtenerIterador();
}



#endif