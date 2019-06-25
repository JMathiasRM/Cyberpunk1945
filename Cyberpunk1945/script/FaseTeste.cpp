#include "FaseTeste.h"


FaseTeste::FaseTeste()
{
	//Entidade(CAMINHO_FUNDO,)
	carregarObstaculos();

}


FaseTeste::~FaseTeste()
{
}

void FaseTeste::carregarObstaculos()
{
	/*
	int x = 0;
	int y = 500;
	for (int i = 0; i < 5; i++) {
		listaEntidades.pushObstaculo(Bloco::criarBloco(Vector2i(x, y)));
		x += 64;
	}
	*/
}

void FaseTeste::executar()
{
	Event e;
	Clock timer_frames;

	bool sair = false;
	while (!sair)
	{
		GerenciadorGrafico::Instancia()->limparJanela();

		// Eventos
		while (GerenciadorGrafico::Instancia()->janelaPollEvent(e)) {
			if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Q))
				sair = true;
		}

		// Coisas

		// Importante que sejam a ÚLTIMA coisa a ser feita antes de terminar o loop
		//listaEntidades.desenharEntidades(timer_frames.restart().asSeconds());
		GerenciadorGrafico::Instancia()->atualizarJanela();
	}
}
