#pragma once

#include "EstadoDeMenu.h"

namespace Menus
{
	class SelecaoDeFase :
		public EstadoDeMenu
	{
	private:
		Imagem fundo;

		Imagem botao_fase1;
		Imagem botao_fase2;

		Imagem botao_doisJogadores;

	public:
		SelecaoDeFase(Menu* menu = NULL);
		~SelecaoDeFase();	
		
		void desenharFundo();
		void desenharBotoes();

		OpcaoDeMenu checarEventos();

		void executar(OpcaoDeMenu& escolha);

		void desenharMenu();
	};
}