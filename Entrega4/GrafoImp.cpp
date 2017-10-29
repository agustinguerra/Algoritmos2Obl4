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

	for (int i = 0; i < cantVertices; i++) {
		if (this->listaAdy[i].Dato2 != nullptr) {
			Tupla<V, A>tup(v, A());
			this->listaAdy[i].Dato2->Eliminar(tup);
		}
	}

	cantVertices--;
}

template <class V, class A>
void GrafoImp<V, A>::AgregarArco(const V& v1, const V& v2, const A& arco) {
	int pos = tablaHash->Obtener(v1);
	if (this->listaAdy[pos].Dato2 == nullptr) {
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
	Array<V> ret(this->cantVertices + 1);
	for (int i = 0; i < this->cantVertices + 1; i++) {
		ret[i] = this->tablaArr[i];
	}
	return ret.ObtenerIterador();
}

template <class V, class A>
Iterador<V> GrafoImp<V, A>::Adyacentes(const V& v) const {
	int posVertice = this->GetPosVertice(v);
	if (this->listaAdy[posVertice].Dato2 != nullptr) {
		Iterador<Tupla<V, A>> it = this->listaAdy[posVertice].Dato2->ObtenerIterador();
		Puntero<ListaOrdImp<V>> l = new ListaOrdImp<V>(comp);
		while (it.HayElemento()) {
			l->InsertarOrdenado(it.ElementoActual().Dato1);
			it.Avanzar();
		}
		return l->ObtenerIterador();
	}
	Array<V> arr(0);
	return arr.ObtenerIterador();
}

template <class V, class A>
Iterador<V> GrafoImp<V, A>::Incidentes(const V& v) const {
	Puntero<ListaOrdImp<V>> l = new ListaOrdImp<V>(comp);
	for (int i = 0; i <= cantVertices; i++) {
		if (this->listaAdy[i].Dato2 != nullptr) {
			Tupla<V, A>tup(v, A());
			if (this->listaAdy[i].Dato2->Pertenece(tup)) {
				l->InsertarOrdenado(this->listaAdy[i].Dato1);
			}
		}
	}
	return l->ObtenerIterador();
}

template <class V, class A>
const A& GrafoImp<V, A>::ObtenerArco(const V& v1, const V& v2) const {
	int pos = this->GetPosVertice(v1);
	Tupla<V, A>tup(v2, A());
	int index = this->listaAdy[pos].Dato2->indexOf(tup);
	return this->listaAdy[pos].Dato2->Obtener(index).Dato2;
}

template <class V, class A>
nat GrafoImp<V, A>::CantidadVertices() const {
	return this->cantVertices+1;
}

template <class V, class A>
nat GrafoImp<V, A>::CantidadArcos() const {
	int contador = 0;
	for (int i = 0; i <= cantVertices; i++) {
		if (this->listaAdy[i].Dato2 != nullptr) {
			contador += this->listaAdy[i].Dato2->Largo();
		}
	}
	return contador;
}

template <class V, class A>
nat GrafoImp<V, A>::CantidadAdyacentes(const V& v) const {
	int contador = 0;
	Iterador<V> it = this->Adyacentes(v);
	while (it.HayElemento()) {
		contador++;
		it.Avanzar();
	}
	return contador;
}

template <class V, class A>
nat GrafoImp<V, A>::CantidadIncidentes(const V& v) const {
	int contador = 0;
	Iterador<V> it = this->Incidentes(v);
	while (it.HayElemento()) {
		contador++;
		it.Avanzar();
	}
	return contador;
}

template <class V, class A>
bool GrafoImp<V, A>::ExisteVertice(const V& v) const {
	bool bandera = false;
	for (int i = 0; i <= this->cantVertices; i++) {
		if (this->comp.SonIguales(this->tablaArr[i], v)) {
			bandera = true;
		}
	}
	return bandera;
}

template <class V, class A>
bool GrafoImp<V, A>::ExisteArco(const V& v1, const V& v2) const {
	bool bandera = false;
	int pos = this->GetPosVertice(v1);
	if (this->listaAdy[pos].Dato2 != nullptr) {
		Tupla<V, A>tup(v2, A());
		if (this->listaAdy[pos].Dato2->Pertenece(tup)) {
			bandera = true;
		}
	}
	return true;
}

template <class V, class A>
bool GrafoImp<V, A>::EstaLleno() const {
	if (this->tablaArr.ObtenerLargo() == this->cantVertices)
		return true;

	return false;
}

template <class V, class A>
bool GrafoImp<V, A>::EstaVacio() const {
	if (this->cantVertices == -1)
		return true;

	return false;
}

template <class V, class A>
void GrafoImp<V, A>::dfsUtil(const int vO, Array<bool> visitados) const{

	visitados[vO] = true;

	Iterador<V> ady = this->Adyacentes(this->tablaArr[vO]);

	while (ady.HayElemento()) {
		if (!visitados[this->GetPosVertice(ady.ElementoActual())]) {
			dfsUtil(this->GetPosVertice(ady.ElementoActual()), visitados);
		}
		ady.Avanzar();
	}
}

template <class V, class A>
bool GrafoImp<V, A>::HayCamino(const V& vO, const V& vD) const {

	Array<bool> visitados(this->cantVertices + 1, false);
	dfsUtil(this->GetPosVertice(vO), visitados);

	return visitados[this->GetPosVertice(vD)];
}

template <class V, class A>
TipoConexo GrafoImp<V, A>::EsConexo() const {

	Array<bool> visitados(this->cantVertices + 1, false);

	dfsUtil(0, visitados);

	bool noEsConexo = false;

	for (int i = 0; i < this->cantVertices+1; i++) {
		if (!visitados[i]) {
			noEsConexo = true;
		}
	}

	if (noEsConexo) {
		return TipoConexo::NO_CONEXO;
	}
	else {
		bool esFuertemente = true;
		for (int j = 0; j < this->cantVertices + 1; j++) {
			for (int k = 0; k < this->cantVertices + 1; k++) {
				if (!(this->HayCamino(tablaArr[j], tablaArr[k]))) {
					esFuertemente = false;
				}
			}
		}
		if (esFuertemente)
			return TipoConexo::FUERTEMENTE_CONEXO;
		else
			return TipoConexo::DEBILMENTE_CONEXO;
	}

	return TipoConexo::NO_CONEXO;
}

template <class V, class A>
void GrafoImp<V, A>::ordTopAux(Array<bool> visitados, int v, PilaArray<V> stack) const{

	visitados[v] = true;

	Iterador<V> ady = this->Adyacentes(this->tablaArr[v]);
	while (ady.HayElemento()) {
		if (!visitados[this->GetPosVertice(ady.ElementoActual())]) {
			ordTopAux(visitados, this->GetPosVertice(ady.ElementoActual()), stack);
		}
		ady.Avanzar();
	}
	stack.Push(this->tablaArr[v]);
}

template <class V, class A>
Iterador<V> GrafoImp<V, A>::OrdenTopologico() const {

	Array<bool> visitados(this->cantVertices + 1, false);
	PilaArray<V> stack = PilaArray<V>(1000);

	for (int i = 0; i <= this->cantVertices; i++) {
		if (!visitados[i]) {
			ordTopAux(visitados, i, stack);
		}
	}

	return stack.ObtenerIterador();
}

template <class V, class A>
void GrafoImp<V, A>::fixComponentes(Array<int> compConex, int v1, int v2) const{
	for (int i = 0; i < this->cantVertices + 1; i++) {
		if (compConex[i] == v2) {
			compConex[i] = compConex[v1];
		}
	}
}

template <class V, class A>
Iterador<Tupla<V, V>> GrafoImp<V, A>::ArbolCubrimientoMinimo(const FuncionCosto<V, A>& costo = FuncionCosto<V, A>::Default) const {
	Comparador<Tupla<V, V>> compTupF = Comparador<Tupla<V, V>>(new ComparadorTupla<V, V>(comp));
	Puntero<ColaPrioridadExtendidaImp<Tupla<V,V>, int>> cp = new ColaPrioridadExtendidaImp<Tupla<V,V>, int>(nullptr, compTupF, Comparador<int>::Default);
	
	for (int i = 0; i < this->cantVertices + 1; i++) {
		if (this->listaAdy[i].Dato2 != nullptr) {
			Iterador<Tupla<V, A>> it = this->listaAdy[i].Dato2->ObtenerIterador();
			while (it.HayElemento()) {
				Tupla<V, V> tup(this->tablaArr[i], it.ElementoActual().Dato1);
				int cost = costo(this->tablaArr[i], it.ElementoActual().Dato1, it.ElementoActual().Dato2);
				cp->InsertarConPrioridad(tup,cost);
				it.Avanzar();
			}
		}
	}

	Array<int> compConex(this->cantVertices + 1,-1);
	Array<bool> visitados(this->cantVertices + 1, false);
	int cantidad = 0;

	for (int t = 0; t < this->cantVertices + 1; t++) {
		compConex[t] = t;
	}

	Puntero<ListaOrdImp<Tupla<V, V>>> lista = new ListaOrdImp<Tupla<V, V>>(compTupF);
		
	while (cantidad<this->cantVertices+1 && !cp->EstaVacia()) {
		Tupla<V, V> tup = cp->ObtenerElementoMayorPrioridad();
		cp->EliminarElementoMayorPrioridad();

		if (compConex[this->GetPosVertice(tup.Dato1)] != compConex[this->GetPosVertice(tup.Dato2)] && !visitados[this->GetPosVertice(tup.Dato2)]) {
			cantidad++;
			visitados[this->GetPosVertice(tup.Dato2)] = true;
			lista->InsertarPrincipio(tup);
			fixComponentes(compConex, this->GetPosVertice(tup.Dato1), this->GetPosVertice(tup.Dato2));
		}
	}

	return lista->ObtenerIterador();
}

template <class V, class A>
Iterador<Iterador<V>> GrafoImp<V, A>::ComponentesConexas() const {

	Array<int> compConex(this->cantVertices + 1, -1);
	Array<bool> visitados(this->cantVertices + 1, false);
	int cantidad = 0;

	for (int t = 0; t < this->cantVertices + 1; t++) {
		compConex[t] = t;
	}

	int  cant = 0;

	for (int origen = 0; origen < this->cantVertices+1; origen++)
		for (int destino = origen + 1; destino < this->cantVertices + 1; destino++)
			if (HayCamino(tablaArr[origen], tablaArr[destino]))
				fixComponentes(compConex, origen, destino);

	Puntero<ListaOrdImp<Iterador<V>>> listaFinal = new ListaOrdImp<Iterador<V>>(Comparador<Iterador<V>>::Default);

	for (int i = 0; i < this->cantVertices + 1; i++) {
		Puntero<ListaOrdImp<V>> ll = new ListaOrdImp<V>(comp);
		for (int j = i; j < this->cantVertices + 1; j++) {
			if (compConex[j] == i)
				ll->InsertarFinal(tablaArr[j]);
		}
		if (ll->Largo() > 0)
			listaFinal->InsertarFinal(ll->ObtenerIterador());
	}
	return listaFinal->ObtenerIterador();
}

#endif