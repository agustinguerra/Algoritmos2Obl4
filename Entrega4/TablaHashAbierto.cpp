#ifndef TABLAHASHABIERTO_CPP
#define TABLAHASHABIERTO_CPP

#include "TablaHashAbierto.h"
#include "IteradorHashAbierto.h"

/* CONSTRUCTORAS */

//PRE: -
//POS: Construye el hash
template <class C, class V>
TablaHashAbierto<C, V>::TablaHashAbierto(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C> comp) {
	int cub = cubetas;
	int primerPrimo = sigPrimo(150000);
	this->tamano = primerPrimo;
	this->comparador = comp;
	this->pFunc = fHash;
	this->ocupados = 0;
	this->largo = 0;
	Comparador<Tupla<C, V>> compTupF =  Comparador<Tupla<C, V>>(new ComparadorTupla<C,V>(comp));
	this->elComparador = compTupF;
	Array<Puntero<ListaOrdImp<Tupla<C, V>>>> arr (primerPrimo);
	this->laTabla = arr;
	for (int i = 0; i < primerPrimo; i++) {
		this->laTabla[i] = nullptr;
	}
}

//PRE: T(c) no está definida y la tabla no está llena
//POS: Define T(c) = v
template <class C, class V>
void TablaHashAbierto<C, V>::Agregar(const C& c, const V& v) {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	if (laTabla[lugar] == nullptr) {
		ocupados = ocupados + 1;
		laTabla[lugar] = new ListaOrdImp<Tupla<C, V>>(elComparador);
		laTabla[lugar]->InsertarOrdenado(Tupla<C, V>(c, v));
	}
	else {
		laTabla[lugar]->InsertarOrdenado(Tupla<C, V>(c, v));
	}
	largo = largo + 1;
}

//PRE: T(c) está definida
//POS: Borra la asociación ligada a 'c'
template <class C, class V>
void TablaHashAbierto<C, V>::Borrar(const C& c) {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	Tupla<C, V> tupla(c,V());
	this->laTabla[lugar]->Eliminar(tupla);
	largo = largo - 1;
	if (this->laTabla[lugar] == nullptr) {
		ocupados = ocupados - 1;
	}
}

//PRE: - 
//POS: Borra todas las asociaciones
template <class C, class V>
void TablaHashAbierto<C, V>::BorrarTodos() {
	int tam = this->tamano;
	for (int i = 0; i < tamano; i++) {
		this->laTabla[i] = nullptr;
	}
	this->ocupados = 0;
	this->largo = 0;
}

/* PREDICADOS */

//PRE: - 
//POS: Retorna true si está vacía, false sino.
template <class C, class V>
bool TablaHashAbierto<C, V>::EstaVacia() const {
	if (this->largo == 0) {
		return true;
	}
	else {
		return false;
	}
}

//PRE: - 
//POS: Retorna true si está llena, false sino.
template <class C, class V>
bool TablaHashAbierto<C, V>::EstaLlena() const {
	return ((ocupados * 100) / tamano) > 70;
}

//PRE: - 
//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
template <class C, class V>
bool TablaHashAbierto<C, V>::EstaDefinida(const C& c) const {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	bool pert = false;
	if (this->laTabla[lugar] != nullptr) {
		Tupla<C, V> tupp(c, V());
		pert = this->laTabla[lugar]->Pertenece(tupp);
	}
	else {
		return false;
	}
	return pert;
}

/* SELECTORAS */

//Pre: n mayor que 1
//Pos: devuelve true si el numero dado es primo
template <class C, class V>
bool TablaHashAbierto<C, V>::esPrimo(int n)
{
	int i, raiz;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	raiz = (int)sqrt(n);

	for (i = 5; i <= raiz; i += 6)
	{
		if (n%i == 0)
			return false;
	}

	for (i = 7; i <= raiz; i += 6)
	{
		if (n%i == 0)
			return false;
	}

	return true;
}


//Pre: -
//Pos: Devuelve el siguiente numero primo
template <class C, class V>
int TablaHashAbierto<C, V>::sigPrimo(int num) {
	int i = num + 1;
	while (1) {
		if (esPrimo(i)) {
			break;
		}
		i = i + 1;
	}
	return i;
}

//PRE: -
//POS: devuelve la lista de una cubeta dada
template <class C,class V>
Puntero<ListaOrdImp<Tupla<C,V>>> TablaHashAbierto<C, V>::devuelvoLista(const C& c) {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	return laTabla[lugar];
}


//PRE: T(c) está definida
//POS: Retorna 'v', tal que T(c) = v
template <class C, class V>
const V& TablaHashAbierto<C, V>::Obtener(const C& c) const {
	nat clave = this->pFunc->CodigoDeHash(c);
	int lugar = clave;
	lugar = lugar % this->tamano;
	Tupla<C, V> tupp(c,V());
	int ubicacion = this->laTabla[lugar]->indexOf(tupp);
	//Tupla<C, V> tup = this->laTabla[lugar]->Obtener(ubicacion);
	//return tup.ObtenerDato2();
	return  this->laTabla[lugar]->Obtener(ubicacion).Dato2;
}

//PRE: -
//POS: Retorna el largo de la tabla
template <class C, class V>
nat TablaHashAbierto<C, V>::Largo() const {
	return this->largo;
}

//PRE: -
//POS: Devuelve un clon de la tabla, no comparten memoria
template <class C, class V>
Puntero<Tabla<C, V>> TablaHashAbierto<C, V>::Clonar() const {
	return nullptr;
}
//PRE: -
//POS: Devuelve el iterador
template <class C, class V>
Iterador<Tupla<C,V>> TablaHashAbierto<C, V>::ObtenerIterador() const {
	int aux = 0;
	Array<Tupla<C, V>> ret = Array <Tupla<C, V>>(this->largo);
	Iterador<Puntero<ListaOrdImp<Tupla<C, V>>>> it = this->laTabla.ObtenerIterador();
	while (it.HayElemento()) {
		Puntero<ListaOrdImp<Tupla<C, V>>> lista = it.ElementoActual();
		if (lista != NULL) {
			Iterador<Tupla<C, V>> itLista = lista->ObtenerIterador();
			while (itLista.HayElemento()) {
				ret[aux] = itLista.ElementoActual();
				aux++;
				itLista.Avanzar();
			}
		}
		it.Avanzar();
	}
	return ret.ObtenerIterador();


	//Puntero<ListaOrdImp<Tupla<C,V>>> lista = new ListaOrdImp<Tupla<C,V>>(elComparador);
	//for (int i = 0; i < tamano; i++) {
	//	if (laTabla[i]!=nullptr){
	//		Iterador<Tupla<C,V>> it = laTabla[i]->ObtenerIterador();
	//		while (it.HayElemento()) {
	//			lista->InsertarFinal(Tupla<C, V>(it.ElementoActual().Dato1, it.ElementoActual().Dato2));
	//			it.Avanzar();
	//		}
	//	}
	//}
 //	return new IteradorHashAbierto<Tupla<C,V>>(lista,tamano,0);
	//return nullptr;
}

#endif