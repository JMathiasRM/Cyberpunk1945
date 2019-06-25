#pragma once

#include "Lista.h"
#include "Entidade.h"

class ListaDeEntidades
{
private:
	Lista<Entidade> listaEntidades;
public:
	ListaDeEntidades();
	~ListaDeEntidades();

	void pushEntidade(Entidade* entidade) { listaEntidades.pushLista(entidade); };
	void popEntidade(Entidade* entidade) { listaEntidades.popLista(entidade); };

	/// Atribui uma lista ao atributo local
	void setLista(Lista<Entidade>&& lista) { listaEntidades = lista; };

	/// Executa cada entidade
	void executar();

	/// Move cada entidade
	void moverEntidades();

	/// Desenha cada entidade
	void desenharEntidades(float dT);
};