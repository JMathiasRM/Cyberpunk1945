#pragma once

#include "Lista.h"
#include "Obstaculo.h"

using namespace Obstaculos;

namespace Listagem
{
	class ListaDeObstaculos
	{
	private:
		Lista<Obstaculo> listaObstaculos;
	public:
		ListaDeObstaculos();
		~ListaDeObstaculos();

		void pushLista(Obstaculo* obstaculo) { listaObstaculos.pushLista(obstaculo); };
		void popLista(Obstaculo* obstaculo) { listaObstaculos.popLista(obstaculo); };

		bool vazia() { return listaObstaculos.vazia(); };

		void zerarIterador() { listaObstaculos.zerarIterador(); };
		bool moverIterador() { return listaObstaculos.moverIterador(); };

		Obstaculo* getObjeto() { return listaObstaculos.getObjeto(); };
	};
}