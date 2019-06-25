#include "Lista.h"

using namespace Listagem;

template <class T>
inline Lista<T>::Lista():
	primeiro(NULL),
	ultimo(NULL),
	iterador(NULL),
	n_elementos(0)
{
}

template <class T>
inline void Lista<T>::pushLista(T* novo_obj)
{
	Elemento<T>* novoEl = new Elemento<T>(novo_obj);

	if (primeiro == NULL) {
		primeiro = novoEl;
		ultimo = novoEl;
		novoEl->anterior = NULL;
		novoEl->proximo = NULL;
		iterador = primeiro;
	}
	else {
		ultimo->proximo = novoEl;
		novoEl->anterior = ultimo;
		novoEl->proximo = NULL;
		ultimo = novoEl;
	}

	n_elementos++;
}

template <class T>
inline void Lista<T>::popLista(T* objeto) {

	if (primeiro == NULL || objeto == NULL)
		return;
	Elemento<T> *elemento = primeiro;

	while (elemento->proximo != NULL && elemento->objeto != objeto)
		elemento = elemento->proximo;


	if (elemento->objeto == objeto)
	{
		if (elemento == primeiro)
			primeiro = elemento->proximo;
		if (elemento == ultimo)
			ultimo = elemento->anterior;

		if(elemento->proximo != NULL)
			elemento->proximo->anterior = elemento->anterior;
		if (elemento->anterior != NULL)
			elemento->anterior->proximo = elemento->proximo;

		delete elemento;
		n_elementos--;
		zerarIterador();
	}
}

template<class T>
inline void Lista<T>::popPrimeiro()
{
	Elemento<T>* para_remover = primeiro;
	primeiro = primeiro->proximo;
	if(primeiro!=NULL)
		primeiro->anterior = NULL;
	delete para_remover;
	n_elementos--;
}

template<class T>
inline T* Lista<T>::getObjeto()
{
	return iterador->objeto;
}

template<class T>
inline bool Lista<T>::moverIterador()
{
	if (iterador == ultimo)
	{
		iterador = primeiro;
		return false;
	}

	iterador = iterador->proximo;
	return true;
}

template<class T>
inline void Lista<T>::zerarIterador()
{
	iterador = primeiro;
}

template<class T>
inline void Lista<T>::operator=(Lista<T>& nova_lista)
{
	while (!vazia())
		popPrimeiro();

	if (nova_lista.vazia())
		return;

	nova_lista.zerarIterador();
	do {
		pushLista(nova_lista.getObjeto());
	} while (nova_lista.moverIterador());
}

template <class T>
template <class TE>
inline Lista<T>::Elemento<TE>::Elemento(TE* novo_objeto)
{
	proximo = NULL;
	anterior = NULL;

	objeto = novo_objeto;
};

template <class T>
template <class TE>
inline Lista<T>::Elemento<TE>::~Elemento()
{
}
