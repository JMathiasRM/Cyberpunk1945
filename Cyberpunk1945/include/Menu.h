#pragma once

#include "Entidade.h"
#include "Texto.h"

// Estados de menu
#include "MenuPrincipal.h"
#include "SelecaoDeFase.h"

namespace Menus
{
	class Menu :
		public Entidade
	{
	private:
		EstadoDeMenu* estado_atual;

		Music musica_menu;

	public:
		Menu(EstadoDeMenu* estado_inicial = NULL);
		~Menu();

		OpcaoDeMenu checarEventos() { return estado_atual->checarEventos(); };

		void executar() {}
		void executar(OpcaoDeMenu& e);

		void desenharMenu() {estado_atual->desenharMenu();};

		void setEstado(EstadoDeMenu* estado_novo) { delete estado_atual; estado_atual = estado_novo; };

		bool doisJogadoresSelecionado() const { return estado_atual->doisJogadoresSelecionado(); };

		void tocarMusica() { musica_menu.play(); };
		void pararMusica() { musica_menu.stop(); };
	};
}