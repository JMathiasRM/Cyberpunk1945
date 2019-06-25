#pragma once

#include "Imagem.h"
#include "Texto.h"

#ifndef NULL
#define NULL 0
#endif

using namespace Visual;

namespace Menus
{
	enum OpcaoDeMenu { NADA, JOGAR, JOGAR1, JOGAR2, SAIR };
	enum EstadoDeBotao { NORMAL, SELECIONADO };

	class Menu;

	class EstadoDeMenu
	{
	protected:
		Menu* menu_atual;

		bool doisJogadores;

	public:
		EstadoDeMenu(Menu* menu = NULL);
		virtual ~EstadoDeMenu();

		virtual void desenharFundo() = 0;
		virtual void desenharBotoes() = 0;
		virtual void desenharTexto() {};

		/// Verifica se dois jogadores foram escolhidos
		bool doisJogadoresSelecionado() const { return doisJogadores; };

		/// Verifica os eventos do menu
		virtual OpcaoDeMenu checarEventos() = 0;

		/// Loop do menu
		virtual void executar(OpcaoDeMenu& escolha) = 0;

		/// Desenha o fundo, botões e texto
		virtual void desenharMenu() = 0;
	};
}