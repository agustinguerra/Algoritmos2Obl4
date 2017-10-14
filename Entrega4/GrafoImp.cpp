#ifndef GRAFOIMP_CPP
#define GRAFOIMP_CPP

#include "GrafoImp.h"

// CONSTRUCTORAS
template <class V, class A>
GrafoImp<V, A>::GrafoImp(int mVertices, Puntero<FuncionHash<V>> funcH, const Comparador<V>& comp) : comp(comp)
{
	cantVertices = -1;
	listaAdy = Array<Tupla<V, Puntero<ListaOrdImp<Tupla<V,A>>>>>(mVertices);
	tablaHash = new TablaHashAbierto<V, int>( mVertices * 4,funcH, comp);
	tablaArr = Array<V>(mVertices, V());
	fHash = funcH;
}

template <class V, class A>
void GrafoImp<V, A>::AgregarVertice(const V& v) {
	cantVertices++;
	tablaHash->Agregar(v, cantVertices);
	Puntero<ListaOrdImp<Tupla<V,A>>> listaVacia = nullptr;
	Tupla<V, Puntero<ListaOrdImp<Tupla<V,A>>>>tup(v, listaVacia);
	listaAdy[cantVertices] = tup;
	tablaArr[cantVertices]=v;
}

template<class T>
void BorrarDeArray(Array<T> &arrayToDelete, int desde, int hasta)
{
	for (int i = desde; i < hasta; i++)
		arrayToDelete[i] = arrayToDelete[i + 1];
}

template <class V, class A>
const int GrafoImp<V, A>::GetPosVertice(const V& v) const
{
	return tablaHash->Obtener(v);
}

template <class V, class A>
void GrafoImp<V, A>::BorrarVertice(const V& v) {
	
	int posDelVertice = this->GetPosVertice(v);

	BorrarDeArray(tablaArr, posDelVertice, cantVertices);

	BorrarDeArray(listaAdy, posDelVertice, cantVertices);

	tablaHash->Borrar(v);

	cantVertices--;

	for (int i = 0; i < cantVertices; i++) {
		if (this->listaAdy[i].Dato2 != nullptr) {
			Tupla<V, A>tup(v, A());
			this->listaAdy[i].Dato2->Eliminar(tup);
		}
	}
}

template <class V, class A>
void GrafoImp<V, A>::AgregarArco(const V& v1, const V& v2, const A& arco) {
	int pos = tablaHash->Obtener(v1);
	if (this->listaAdy[pos].Dato2 != nullptr) {
		Tupla<V, A>tup(v2, arco);
		//Puntero<ComparadorTupla<A, V>> puntero = new ComparadorTupla<A, V>(comp);
		//Comparador<Tupla<A, V>> compTupF (puntero);

		Comparador<Tupla<V, A>> compTupF = Comparador<Tupla<V, A>>(new ComparadorTupla<V, A>(comp));
		this->listaAdy[pos].Dato2 = new ListaOrdImp<Tupla<V,A>>(compTupF);
		this->listaAdy[pos].Dato2->InsertarPrincipio(tup);
	}
	else {
		Tupla<V, A>tup(v2, arco);
		this->listaAdy[pos].Dato2->InsertarOrdenado(tup);
	}
}

template <class V, class A>
void GrafoImp<V, A>::BorrarArco(const V& v1, const V& v2) {
	int posVertice = this->GetPosVertice(v1);
	Tupla<V, A>tup(v2, A());
	this->listaAdy[posVertice].Dato2->Eliminar(tup);
}

// SELECTORAS y PREDICADOS
template <class V, class A>
Iterador<V> GrafoImp<V, A>::Vertices() const {
	return this->tablaArr.ObtenerIterador();
}

template <class V, class A>
Iterador<V> GrafoImp<V, A>::Adyacentes(const V& v) const {
	int posVertice = this->GetPosVertice(v);
	Iterador<Tupla<V, A>> it = this->listaAdy[posVertice].Dato2->ObtenerIterador();
	Puntero<ListaOrdImp<V>> l = new ListaOrdImp<V>(comp);
	while (it.HayElemento()) {
		l->InsertarOrdenado(it.ElementoActual().Dato1);
		it.Avanzar();
	}
	return l->ObtenerIterador();
}

template <class V, class A>
Iterador<V> GrafoImp<V, A>::Incidentes(const V& v) const {
	Array<V> paraIterar(1000000);
	for (int i = 0; i <= cantVertices; i++) {
	
	}
}

template <class V, class A>
const A& GrafoImp<V, A>::ObtenerArco(const V& v1, const V& v2) const {}

template <class V, class A>
nat GrafoImp<V, A>::CantidadVertices() const {}

template <class V, class A>
nat GrafoImp<V, A>::CantidadArcos() const {}

template <class V, class A>
nat GrafoImp<V, A>::CantidadAdyacentes(const V& v) const {}

template <class V, class A>
nat GrafoImp<V, A>::CantidadIncidentes(const V& v) const {}

template <class V, class A>
bool GrafoImp<V, A>::ExisteVertice(const V& v) const {}

template <class V, class A>
bool GrafoImp<V, A>::ExisteArco(const V& v1, const V& v2) const {}

template <class V, class A>
bool GrafoImp<V, A>::EstaLleno() const {}

template <class V, class A>
bool GrafoImp<V, A>::EstaVacio() const {}

template <class V, class A>
bool GrafoImp<V, A>::HayCamino(const V& vO, const V& vD) const {}

template <class V, class A>
TipoConexo GrafoImp<V, A>::EsConexo() const {}

template <class V, class A>
Iterador<V> GrafoImp<V, A>::OrdenTopologico() const {}

template <class V, class A>
Iterador<Tupla<V, V>> GrafoImp<V, A>::ArbolCubrimientoMinimo(const FuncionCosto<V, A>& costo = FuncionCosto<V, A>::Default) const {}

template <class V, class A>
Iterador<Iterador<V>> GrafoImp<V, A>::ComponentesConexas() const {}

#endif