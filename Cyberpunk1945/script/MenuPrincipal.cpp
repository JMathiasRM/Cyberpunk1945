#include "MenuPrincipal.h"

using namespace Menus;

MenuPrincipal::MenuPrincipal(Menu* menu) :
	EstadoDeMenu(menu),

	fundo(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_FUNDO), Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize())),

	botao_jogar(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_BTN_JOGAR),
		Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 4.f,
			GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 16.f),
		{0}, Vector2u(2, 1), vector<unsigned int>{1, 1}),

	botao_sair(GerenciadorGrafico::carregaTextura(CAMINHO_MENU_BTN_SAIR),
		Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 4.f,
			GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 16.f),
		{0}, Vector2u(2, 1), vector<unsigned int>{1, 1}),

	titulo("navycadetexpand.ttf", static_cast<unsigned int>(GerenciadorGrafico::Instancia()->getJanela()->getSize().x / 15), Color::Red)
{
	// Posição dos botões na tela
	Vector2f janela = Vector2f(GerenciadorGrafico::Instancia()->getJanela()->getSize());
	botao_jogar.setDiferenca(Vector2f((botao_jogar.getSpriteAtual().getGlobalBounds().width - janela.x) / 2,
		-janela.y / 3));
	botao_sair.setDiferenca(Vector2f((botao_sair.getSpriteAtual().getGlobalBounds().width - janela.x) / 2,
		-2 * janela.y / 3));


	titulo.setTexto("cyberpunk 1945"); // Só para centralizar o texto direito
	titulo.setPosicao(Vector2f((janela.x - titulo.getTextoParaDesenho().getGlobalBounds().width+10) / 2, 50));
}

MenuPrincipal::~MenuPrincipal()
{
}

void Menus::MenuPrincipal::desenharFundo()
{
	GerenciadorGrafico::Instancia()->desenhar(fundo.getSpriteAtual());
}

void Menus::MenuPrincipal::desenharBotoes()
{
	botao_jogar.setPosicao(Vector2f(0, 0));
	botao_sair.setPosicao(Vector2f(0, 0));

	GerenciadorGrafico::Instancia()->desenhar(botao_jogar.getSpriteAtual());
	GerenciadorGrafico::Instancia()->desenhar(botao_sair.getSpriteAtual());
}

void Menus::MenuPrincipal::desenharTexto()
{
	if (timer_texto.getElapsedTime().asSeconds() < 1) {
		String texto;
		texto.insert(0, Texto::stringAleatoria(5));
		texto.insert(5, Texto::stringAleatoria(5));
		texto.insert(10, Texto::stringAleatoria(4));
		titulo.setTexto(texto);
	}
	else if (timer_texto.getElapsedTime().asSeconds() < 2) {
		String texto;
		texto.insert(0, "CYBER");
		texto.insert(5, Texto::stringAleatoria(5));
		texto.insert(10, Texto::stringAleatoria(4));
		titulo.setTexto(texto);
	}
	else if (timer_texto.getElapsedTime().asSeconds() < 3) {
		String texto;
		texto.insert(0, "CYBERPUNK ");
		texto.insert(10, Texto::stringAleatoria(4));
		titulo.setTexto(texto);
	}
	else {
		titulo.setTexto("CYBERPUNK 1945");
	}

	GerenciadorGrafico::Instancia()->desenhar(titulo.getTextoParaDesenho());
}

OpcaoDeMenu Menus::MenuPrincipal::checarEventos()
{
	Event e;

	while (GerenciadorGrafico::Instancia()->janelaPollEvent(e)) {
		if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Q)) {
			return SAIR;
		}
		if (botao_jogar.mouseDentro()) {
			botao_jogar.setAnimacao(SELECIONADO);
			if (e.type == Event::MouseButtonPressed) {
				return JOGAR;
			}
		}
		else {
			botao_jogar.setAnimacao(NORMAL);
		}
		if (botao_sair.mouseDentro()) {
			botao_sair.setAnimacao(SELECIONADO);
			if (e.type == Event::MouseButtonPressed) {
				return SAIR;
			}
		}
		else {
			botao_sair.setAnimacao(NORMAL);
		}
	}

	return NADA;
}

void Menus::MenuPrincipal::executar(OpcaoDeMenu& escolha)
{
	bool sair = false;
	while (!sair)
	{
		GerenciadorGrafico::Instancia()->limparJanela();

		// Eventos
		switch (checarEventos())
		{
		case SAIR:
			escolha = SAIR;
			sair = true;
			break;
		case JOGAR:
			sair = true;
			escolha = JOGAR;
			break;
		}

		desenharMenu();

		GerenciadorGrafico::Instancia()->atualizarJanela();
	}
}

void Menus::MenuPrincipal::desenharMenu()
{
	desenharFundo();
	desenharBotoes();
	desenharTexto();
}
