#ifndef COLAPRIORIDADEXTENDIDAIMP_CPP
#define COLAPRIORIDADEXTENDIDAIMP_CPP

#include "ColaPrioridadExtendidaImp.h"

//PRE: Existen ambas posiciones
//POS: Swapea las dos posiciones
template <class T, class P>
void ColaPrioridadExtendidaImp<T, P>::swap(int i1, int i2) {
	Tupla<T, P> aux = heap[i1];
	heap[i1] = heap[i2];
	heap[i2] = aux;
}

// PRE: -
// POS: Crea la cola prioridad
template <class T, class P>
ColaPrioridadExtendidaImp<T, P>::ColaPrioridadExtendidaImp(Puntero<FuncionHash<T>> fHash, const Comparador<T>& compT, const Comparador<P>& compP) {
	this->funcH = fHash;
	this->compP = compP;
	this->compT = compT;
	this->largo = 0;
	Array<Tupla<T, P>> arr(150000);
	this->heap = arr;
}

// PRE: -
// POS: Inserta el elemento e con prioridad p
template <class T, class P>
void ColaPrioridadExtendidaImp<T, P>::InsertarConPrioridad(const T& e, const P& p) {
	Tupla<T, P> tuplaInsertar(e, p);
	int insertoAca= this->largo+1;
	this->heap[insertoAca] = tuplaInsertar;
	this->largo++;

	for (int i = insertoAca; i > 1; i /= 2) {
		if (this->compP.Comparar(heap[i].Dato2, heap[i/2].Dato2) == MENOR) {
			swap(i, i/2);
		}
		else {
			break;
		}
	}
}

// PRE: La cola de prioridad no está vacía
// POS: Retorna el elemento de mayor prioridad en la cola eliminándolo
template <class T, class P>
T ColaPrioridadExtendidaImp<T, P>::EliminarElementoMayorPrioridad() {
	T elemADevolver = heap[1].Dato1;
	swap(1, largo);
	largo--;
	for (int i = 1; compP.EsMayor(heap[i].Dato2, heap[i * 2].Dato2) && i <= largo/2 ; i = i * 2) {
		if (compP.Comparar(heap[i * 2].Dato2, heap[i].Dato2) == MENOR) {
			int posicionMinima = i * 2;
			if (compP.Comparar(heap[i * 2 + 1].Dato2, heap[i * 2].Dato2) == MENOR) {
				posicionMinima = i * 2 + 1;
			}

			swap(i, posicionMinima);
			
		}
		else {
			break;
		}
	}
	return elemADevolver;
}

// PRE: La cola no está vacía
// POS: Retorna el elemento de mayor prioridad en la cola sin eliminarlo
template <class T, class P>
const T& ColaPrioridadExtendidaImp<T, P>::ObtenerElementoMayorPrioridad() const {
	return heap[1].Dato1;
}

// PRE: El elemento e pertenece a la cola.
// POS: Retorna una tupla que contiene al elemento e y su prioridad.
template <class T, class P>
Tupla<T, P> ColaPrioridadExtendidaImp<T, P>::ObtenerElementoYPrioridad(const  T& e) {
	for (int i = 1; i < largo+1; i++) {
		if (compT.Comparar(heap[i].Dato1, e) == IGUALES) {
			return heap[i];
		}
	}
	return heap[1];
}

// PRE: -
// POS: Retorna el largo de la cola de prioridad
template <class T, class P>
nat ColaPrioridadExtendidaImp<T, P>::Largo() const {
	return largo;
}

// PRE: -
// POS: Retorna true si y solo si el elemento e pertenece a la cola.
template <class T, class P>
bool ColaPrioridadExtendidaImp<T, P>::Pertenece(const T& e) const {
	bool pert = false;
	for (int i = 1; i < largo + 1; i++) {
		if (compT.Comparar(heap[i].Dato1, e) == IGUALES) {
			pert = true;
			break;
		}
	}
	return pert;
}

//PRE: Hay elemento en la posicion
//POS: Devuelve la cp sin ese elemento
template <class T, class P>
void ColaPrioridadExtendidaImp<T, P>::eliminarEnPosicion(int pos) {
	T elemADevolver = heap[pos].Dato1;
	swap(pos, largo);
	largo--;
	for (int i = pos; i < largo / 2; i = i * 2) {
		if (compP.Comparar(heap[i * 2].Dato2, heap[i].Dato2) == MENOR || compP.Comparar(heap[i * 2 + 1].Dato2, heap[i].Dato2)) {
			if (compP.Comparar(heap[i * 2].Dato2, heap[i * 2 + 1].Dato2) == MENOR) {
				swap(i, i * 2);
			}
			else {
				swap(i, i * 2 + 1);
			}
		}
		else {
			break;
		}
	}
}


// PRE: El elemento e pertenece a la cola.
// POS: El elemento e tiene una nueva prioridad p.
template <class T, class P>
void ColaPrioridadExtendidaImp<T, P>::CambiarPrioridad(const T& e, const P& p) {
	int pos = 0;
	for (int i = 1; i < largo + 1; i++) {
		if (compT.Comparar(heap[i].Dato1, e) == IGUALES) {
			pos = i;
			break;
		}
		
	}
	Tupla<T, P> tupp = heap[pos];
	tupp.Dato2 = p;
	eliminarEnPosicion(pos);
	InsertarConPrioridad(tupp.Dato1, tupp.Dato2);	
}

// PRE: El elemento e pertenece a la cola.
// POS: El elemento e no pertenece a la cola.
template <class T, class P>
void ColaPrioridadExtendidaImp<T, P>::EliminarElemento(T& e) {
	for (int i = 1; i < largo + 1; i++) {
		if (compT.Comparar(heap[i].Dato1, e) == IGUALES) {
			eliminarEnPosicion(i);
			break;
		}
	}
}

// PRE: -
// POS: Retorna true si y solo si la cola esta vacia
template <class T, class P>
bool ColaPrioridadExtendidaImp<T, P>::EstaVacia() const {
	if (largo == 0) {
		return true;
	}
	else {
		return false;
	}
	
}

// PRE: -
// POS: Retorna true si y solo si la cola esta llena
template <class T, class P>
bool ColaPrioridadExtendidaImp<T, P>::EstaLlena() const {
	return false;
}

// PRE: -
// POS: La cola esta vacía
template <class T, class P>
void ColaPrioridadExtendidaImp<T, P>::Vaciar() {
	largo = 0;
}

// PRE: -
// POS: Retorna un clon de la cola que no comparte memoria con ella
template <class T, class P>
Puntero<ColaPrioridadExtendida<T, P>> ColaPrioridadExtendidaImp<T, P>::Clon() const {
	Puntero<ColaPrioridadExtendida<T, P>> p;
	p = nullptr;
	return p;
}

//Retorna el iterador para recorrer la PQ
template <class T, class P>
Iterador<Tupla<T,P>> ColaPrioridadExtendidaImp<T, P>::ObtenerIterador() const {
	int aux = 0;
	Array<Tupla<T, P>> ret = Array <Tupla<T, P>>((this->largo));
	for (int i = 0; i < largo; i++) {
		ret[aux] = Tupla<T, P>(heap[i+1].Dato1, heap[i+1].Dato2);
		aux++;
	}
	return ret.ObtenerIterador();
}

#endif