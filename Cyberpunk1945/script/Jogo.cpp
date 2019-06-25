#include "Jogo.h"

Jogo::Jogo():
	jogador1(1, CAMINHO_JOGADOR1, Vector2f(100, 100), Vector2f(200,640), vector<float>{0.5, 0.25, 0, 0.3},
		Vector2u(4, 3), vector<unsigned int>{2, 2, 1, 3}, Vector2u(22, 30), Vector2f(6, 1)),
	jogador2(2, CAMINHO_JOGADOR2, Vector2f(100,100), Vector2f(200,640), vector<float>{0.5, 0.15, 0.2, 0.3},
		Vector2u(4, 4), vector<unsigned int>{2,4,2,4}, Vector2u(26,28), Vector2f(2,2)),
	menu(new MenuPrincipal(&menu))
{
	GerenciadorGrafico::Instancia(VideoMode::getFullscreenModes().at(0), "Cyberpunk 1945");
	GerenciadorGrafico::Instancia()->setFPS(30);
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	while (GerenciadorGrafico::Instancia()->janelaAberta())
	{
		View camera_menu = View(Vector2f(GerenciadorGrafico::Instancia()->getTamanho().x / 2, GerenciadorGrafico::Instancia()->getTamanho().y / 2),
								Vector2f(GerenciadorGrafico::Instancia()->getTamanho()));
		GerenciadorGrafico::Instancia()->getJanela()->setView(camera_menu);
		menu.tocarMusica();
		OpcaoDeMenu escolha;
		menu.executar(escolha);
		switch (escolha) {
		case JOGAR:
			// Abrir nível
			menu.setEstado(new SelecaoDeFase(&menu));
			menu.executar(escolha);
			menu.pararMusica();
			switch (escolha) {
			case JOGAR1:
				fase = Fase::construirFase(1);

				if (menu.doisJogadoresSelecionado())
					fase->setJogador(&jogador1, &jogador2);
				else
					fase->setJogador(&jogador1);

				if (fase != NULL)
					fase->executar();

				if (fase->vitoria()) {
					delete fase;
					fase = Fase::construirFase(2);

					if (menu.doisJogadoresSelecionado())
						fase->setJogador(&jogador1, &jogador2);
					else
						fase->setJogador(&jogador1);

					if (fase != NULL)
						fase->executar();
				}
				delete fase;
				break;

			case JOGAR2:
				fase = Fase::construirFase(2);

				if (menu.doisJogadoresSelecionado())
					fase->setJogador(&jogador1, &jogador2);
				else
					fase->setJogador(&jogador1);

				if (fase != NULL)
					fase->executar();
				delete fase;
				break;
			}

			break;
		case SAIR:
			GerenciadorGrafico::Instancia()->fecharJanela();
			break;
		}
		menu.pararMusica();
		menu.setEstado(new MenuPrincipal(&menu));
	}
}