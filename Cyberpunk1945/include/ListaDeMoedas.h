#pragma once

#include "Lista.h"
#include "Moeda.h"

using namespace Artefatos;

namespace Listagem
{
	class ListaDeMoedas
	{
	private:
		Lista<Moeda> listaMoedas;
	public:
		ListaDeMoedas();
		~ListaDeMoedas();

		void pushLista(Moeda* obstaculo) { listaMoedas.pushLista(obstaculo); };
		void popLista(Moeda* obstaculo) { listaMoedas.popLista(obstaculo); };

		bool vazia() { return listaMoedas.vazia(); };

		void zerarIterador() { listaMoedas.zerarIterador(); };
		bool moverIterador() { return listaMoedas.moverIterador(); };

		Moeda* getObjeto() { return listaMoedas.getObjeto(); };
	};
}