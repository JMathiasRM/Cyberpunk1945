#pragma once

#include "Lista.h"
#include "Inimigo.h"

using namespace Inimigos;

namespace Listagem
{
	class ListaDeInimigos
	{
	private:
		Lista<Inimigo> listaInimigos;
	public:
		ListaDeInimigos();
		~ListaDeInimigos();

		void pushLista(Inimigo* obstaculo) { listaInimigos.pushLista(obstaculo); };
		void popLista(Inimigo* obstaculo) { listaInimigos.popLista(obstaculo); };

		bool vazia() { return listaInimigos.vazia(); };

		void zerarIterador() { listaInimigos.zerarIterador(); };
		bool moverIterador() { return listaInimigos.moverIterador(); };

		Inimigo* getObjeto() { return listaInimigos.getObjeto(); };
	};
}