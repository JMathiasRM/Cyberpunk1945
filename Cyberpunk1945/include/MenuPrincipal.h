#pragma once

#include "EstadoDeMenu.h"

namespace Menus
{
	class MenuPrincipal :
		public EstadoDeMenu
	{
	private:
		Imagem fundo;

		Imagem botao_jogar;
		Imagem botao_sair;

		Clock timer_texto;
		Texto titulo;
		
	public:
		MenuPrincipal(Menu* menu = NULL);
		~MenuPrincipal();

		void desenharFundo();
		void desenharBotoes();
		void desenharTexto();

		OpcaoDeMenu checarEventos();

		void executar(OpcaoDeMenu& escolha);

		void desenharMenu();
	};
}