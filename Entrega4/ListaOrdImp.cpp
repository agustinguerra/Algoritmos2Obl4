#ifndef LISTAORDIMP_CPP
#define LISTAORDIMP_CPP

#include "ListaOrdImp.h"
#include "IteradorListaOrdImp.h"


//PRE: -
//POS: Crea la lista ordenada
template <class T>
ListaOrdImp<T>::ListaOrdImp() {
	this->lista = nullptr;
	this->largo = 0;
}


//PRE: -
//POS: Crea la lista ordenada
template <class T>
ListaOrdImp<T>::ListaOrdImp(const Comparador<T>& comp) {
	this->lista = nullptr;
	this->comparador = comp;
	this->largo = 0;
}


// PRE: Está ordenada
// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
template<class T>
void ListaOrdImp<T>::insLista(const T& e, Puntero<NodoLista<T>>& l) {
	if (l == NULL) {
		Puntero<NodoLista<T> > nodo = new NodoLista<T>(e);
		nodo->siguiente = NULL;
		l = nodo;
	}
	else if (comparador.Comparar(l->dato, e) == MAYOR) {
		Puntero<NodoLista<T> > nodo = new NodoLista<T>(l->dato);
		nodo->siguiente = l->siguiente;
		l->siguiente = nodo;
		l->dato = e;
	}
	else if ((comparador.Comparar(l->dato, e) == IGUALES)) {
		insLista(e, l->siguiente);
	}
	else if (comparador.Comparar(l->dato, e) == MENOR) {
		insLista(e, l->siguiente);
	}
}


// PRE: Está ordenada
// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
template <class T>
void ListaOrdImp<T>::InsertarOrdenado(const T& e) {
	insLista(e, this->lista);
	this->largo = this->largo + 1;
}

// PRE: 
// POS: Inserta el elemento al principio
template <class T>
void ListaOrdImp<T>::InsertarPrincipio(const T& e) {
	this->largo = this->largo + 1;
	if (this->lista != NULL) {
		Puntero<NodoLista<T>> nodo = new NodoLista<T>(e);
		nodo->siguiente = this->lista;
		this->lista = nodo;
	}
	else {
		Puntero<NodoLista<T>> nodo = new NodoLista<T>(e);
		nodo->siguiente = NULL;
		this->lista = nodo;
	}
}

// PRE: 
// POS: Inserta el elemento al final
template <class T>
void ListaOrdImp<T>::InsertarFinal(const T& e) {
	Puntero<NodoLista<T>> nodo = new NodoLista<T>(e);
	nodo->siguiente = nullptr;
	Puntero<NodoLista<T>> aux = this->lista;
	if (aux == nullptr) {
		this->lista = nodo;
	}
	else {
		while (aux->siguiente != nullptr) {
			aux = aux->siguiente;
		}
		aux->siguiente = nodo;
	}

	this->largo = this->largo + 1;
}

// PRE: La lista no está vacía
// POS: Retorna el primer elemento de la lista
template <class T>
const T& ListaOrdImp<T>::Cabeza() const {
	return this->lista->dato;
}

// PRE: -
// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acción.
template <class T>
void ListaOrdImp<T>::Eliminar(const T& e) {
	Puntero<NodoLista<T>> aux = this->lista;
	if ((aux != NULL) && !(this->comparador.Comparar(aux->dato, e) == IGUALES)) {
		while ((aux->siguiente != NULL) && (this->comparador.Comparar(aux->siguiente->dato, e) == MENOR)) {
			aux = aux->siguiente;
		}
		if (this->comparador.Comparar(aux->siguiente->dato, e) == IGUALES) {
			Puntero<NodoLista<T>> aux2 = aux->siguiente;
			aux->siguiente = aux2->siguiente;
			aux2 = NULL;
			this->largo = this->largo - 1;
		}
	}
	else if (aux != NULL) {
		this->largo = this->largo - 1;
		this->lista = this->lista->siguiente;
		aux = NULL;
	}
}

// PRE: -
// POS: Retorna el largo de la lista
template <class T>
nat ListaOrdImp<T>::Largo() const {
	return this->largo;
}

// PRE: La lista tiene un elemento en la posición n. 
// POS: Retorna el elemento que está en esa posición de la lista. El primer elemento empieza en 0.
template <class T>
const T& ListaOrdImp<T>::Obtener(const nat n) const {
	Puntero<NodoLista<T>> aux = this->lista;
	int nn = n;
	for (int i = 0; i < nn; i++) {
		aux = aux->siguiente;
	}
	return aux->dato;
}
// PRE: -
// POS: Retorna true si y solo si el elemento e pertenece a la lista.
template <class T>
bool ListaOrdImp<T>::Pertenece(const T& e) const {
	Puntero<NodoLista<T>> aux = this->lista;
	while (aux != NULL) {
		if (comparador.Comparar(aux->dato, e) == IGUALES) {
			break;
		}
	}
	if (aux == NULL) {
		return false;
	}
	else {
		return true;
	}
}

// PRE: -
// POS: Retorna true si y solo si la lista esta vacia
template <class T>
bool ListaOrdImp<T>::EstaVacia() const {
	if (this->lista == NULL) {
		return true;
	}
	else {
		return false;
	}
}

// PRE: -
// POS: Retorna un clon de la lista que no comparte memoria con ella
template <class T>
Puntero<ListaOrd<T>> ListaOrdImp<T>::Clon() const {
	Puntero<ListaOrd<T> > ret = new ListaOrdImp<T>(this->comparador);
	Iterador<T> it = this->ObtenerIterador();
	while (it.HayElemento()){
		ret->InsertarOrdenado(it.ElementoActual());
		it.Avanzar();
	}
	return ret;
}

//PRE -
//POS: Devuelve el iterador de la lista
template <class T>
Iterador<T> ListaOrdImp<T>::ObtenerIterador() const {
	return new IteradorListaOrdImp<T>(this->lista);
}

template <class T>
int ListaOrdImp<T>::indexOf(const T& e) {
	Puntero<NodoLista<T>> aux = this->lista;
	int contador = 0;
	while (aux != NULL) {
		if (comparador.Comparar(e, this->lista->dato) == IGUALES) {
			return contador;
		}
		contador = contador + 1;
	}
	return -1;
}

#endif