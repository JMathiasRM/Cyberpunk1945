#include "SelecaoDeFase.h"

using namespace Menus;

SelecaoDeFase::SelecaoDeFase(Menu* menu):
	EstadoDeMenu(menu),

	fundo(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_FUNDO), Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize())),

	botao_fase1(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_BTN_FASE1),
	Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 4.f,
		GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 16.f),
	{ 0 }, Vector2u(2, 1), vector<unsigned int>{1, 1}),

	botao_fase2(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_BTN_FASE2),
		Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 4.f,
			GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 16.f),
		{ 0 }, Vector2u(2, 1), vector<unsigned int>{1, 1}),

	botao_doisJogadores(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_BTN_DOISJOGADORES),
		Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 4.f,
			GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 12.f),
			{ 0 }, Vector2u(2, 1), vector<unsigned int>{1, 1}
	)
{
	// Posição dos botões na tela
	Vector2f janela = Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize());

	botao_fase1.setDiferenca(Vector2f((botao_fase1.getSpriteAtual().getGlobalBounds().width - janela.x) / 4,
		-1 * janela.y / 3));
	botao_fase2.setDiferenca(Vector2f((botao_fase2.getSpriteAtual().getGlobalBounds().width - janela.x) / 4,
		-2 * janela.y / 3));
	botao_doisJogadores.setDiferenca(Vector2f(2 * (botao_doisJogadores.getSpriteAtual().getGlobalBounds().width - janela.x) / 3,
		-janela.y / 2));

}


SelecaoDeFase::~SelecaoDeFase()
{
}

void Menus::SelecaoDeFase::desenharFundo()
{
	GerenciadorGrafico::Instancia()->desenhar(fundo.getSpriteAtual());
}

void Menus::SelecaoDeFase::desenharBotoes()
{
	botao_fase1.setPosicao(Vector2f(0, 0));
	botao_fase2.setPosicao(Vector2f(0, 0));
	botao_doisJogadores.setPosicao(Vector2f(0, 0));

	GerenciadorGrafico::Instancia()->desenhar(botao_fase1.getSpriteAtual());
	GerenciadorGrafico::Instancia()->desenhar(botao_fase2.getSpriteAtual());
	GerenciadorGrafico::Instancia()->desenhar(botao_doisJogadores.getSpriteAtual());
}

OpcaoDeMenu Menus::SelecaoDeFase::checarEventos()
{
	Event e;

	while (GerenciadorGrafico::Instancia()->janelaPollEvent(e)) {
		if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Q)) {
			return SAIR;
		}
		if (botao_fase1.mouseDentro()) {
			botao_fase1.setAnimacao(SELECIONADO);
			if (e.type == Event::MouseButtonPressed) {
				return JOGAR1;
			}
		}
		else {
			botao_fase1.setAnimacao(NORMAL);
		}

		if (botao_fase2.mouseDentro()) {
			botao_fase2.setAnimacao(SELECIONADO);
			if (e.type == Event::MouseButtonPressed) {
				return JOGAR2;
			}
		}
		else {
			botao_fase2.setAnimacao(NORMAL);
		}

		if (botao_doisJogadores.mouseDentro()) {
			if (e.type == Event::MouseButtonPressed)
				doisJogadores = !doisJogadores;
		}
		if (doisJogadores)
			botao_doisJogadores.setAnimacao(SELECIONADO);
		else
			botao_doisJogadores.setAnimacao(NORMAL);
	}

	return NADA;
}

void Menus::SelecaoDeFase::executar(OpcaoDeMenu& escolha)
{
	bool sair = false;
	while (!sair)
	{
		GerenciadorGrafico::Instancia()->limparJanela();

		// Eventos
		switch (checarEventos())
		{
		case JOGAR1:
			sair = true;
			escolha = JOGAR1;
			break;
		case JOGAR2:
			sair = true;
			escolha = JOGAR2;
			break;
		}

		desenharMenu();

		GerenciadorGrafico::Instancia()->atualizarJanela();
	}
}

void Menus::SelecaoDeFase::desenharMenu()
{
	desenharFundo();
	desenharBotoes();
}
