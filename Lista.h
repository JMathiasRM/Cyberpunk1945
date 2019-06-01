#ifndef LISTA_H__
#define LISTA_H__

#include "Elemento.h"

template <class T>
class Lista
{
private:
	Elemento<T>* primeiro;
	Elemento<T>* ultimo;

	int n_elementos;

public:
	Lista()
	{
		primeiro = 0;
		ultimo = 0;

		n_elementos = 0;
	};
	~Lista() {};

	void pushLista(T* novo_obj)
	{
		Elemento<T>* novoEl = new Elemento<T>(novo_obj, n_elementos++);
		
		if (primeiro == 0) {
			primeiro = novoEl;
			ultimo = novoEl;
		}
		else {
			ultimo->proximo = novoEl;
			ultimo = novoEl;
		}
	}

	void popLista(int id_objeto) {

		if (primeiro == 0)
			return;

		Elemento<T> *i;
		for (i = primeiro; i->ID < id_objeto; i++);

		// Em caso de falha
		if (i->ID != id_objeto)
			return;

		for (Elemento<T> *j = i; j->proximo != 0; j++)
			j->ID--;

		// Caso 1: Lista com 1 elemento
		if (primeiro->proximo == 0) {
			primeiro = 0;
			ultimo = 0;
		}
		// Caso 2: Remover o primeiro elemento
		else if (i == primeiro) {
			primeiro = i->proximo;
		}
		// Caso 3: Remover o último
		else if (i == ultimo) {
			--i->proximo = 0;
			ultimo = i++;
		}
		// Caso 4: Remover um elemento qualquer no meio
		else {
			--i->proximo = ++i->proximo;
		}

		delete i;
		n_elementos--;
	}
};

#endif // LISTA_H__