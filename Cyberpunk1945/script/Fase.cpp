#include "Fase.h"
#include "Fase1.h"
#include "Fase2.h"

using namespace Fases;

Fase::Fase(const char* caminho_fundo, const char* caminho_plataformas, Vector2u tamanho_fase):
	Entidade(caminho_fundo, Vector2f(1066,600)),
	plataformas(GerenciadorGrafico::carregaTextura(caminho_plataformas), Vector2f(tamanho_fase)),
	camera({0,0}, { 1066,600 }),
	pausado(false),
	ganhou(false)
{
	timer_frames.restart();
}


Fase::~Fase()
{

}

void Fase::setJogador(Jogador* jogador1, Jogador* jogador2)
{
	this->jogador1 = jogador1;
	this->jogador2 = jogador2;

	this->jogador1->restaurar();

	if (jogador2)
		this->jogador2->restaurar();

	colisor.setJogadores(jogador1, jogador2);

	listaEntidades.pushEntidade(this->jogador1);
	if (this->jogador2)
		listaEntidades.pushEntidade(this->jogador2);
}

void Fase::inserirEntidades()
{
	listaEntidades.setLista(colisor.getListaCompleta());
}

void Fase::criarInimigo(Inimigo* inimigo)
{
	colisor.pushInimigo(inimigo);
	listaEntidades.pushEntidade(inimigo);
}

Fase* Fase::construirFase(int n)
{
	switch (n) {
	case 1:
		return static_cast<Fase*>(new Fase1);
	case 2:
		return static_cast<Fase*>(new Fase2);
	}
	return NULL;
}

void Fase::desenharFundo()
{
	imagem.setPosicao(Vector2f(camera.getCenter().x - (camera.getSize().x / 2), camera.getCenter().y - (camera.getSize().y / 2)));

	GerenciadorGrafico::Instancia()->desenhar(imagem.getSpriteAtual());
	GerenciadorGrafico::Instancia()->desenhar(plataformas.getSpriteAtual());
}

void Fase::desenharVidaPersonagens()
{
	if (jogador1->estaViva()) {
		jogador1->setPosicaoVida(Vector2f(camera.getCenter().x - (camera.getSize().x / 2), camera.getCenter().y - (camera.getSize().y / 2)));
		jogador1->setPosicaoPontuacao(
			Vector2f(camera.getCenter().x - (camera.getSize().x / 2) + 250, camera.getCenter().y - (camera.getSize().y / 2) + 90)
		);
		jogador1->desenharVida();
	}
	if (jogador2 && jogador2->estaViva()) {
		jogador2->setPosicaoVida(Vector2f(camera.getCenter().x - (camera.getSize().x / 2), camera.getCenter().y - (camera.getSize().y / 2)));
		jogador2->setPosicaoPontuacao(
			Vector2f(camera.getCenter().x - (camera.getSize().x / 2) + 780, camera.getCenter().y - (camera.getSize().y / 2) + 90)
		);
		jogador2->desenharVida();
	}
}

void Fase::checarEventos(Event& e)
{
	while (GerenciadorGrafico::Instancia()->janelaPollEvent(e)) {
		switch (e.type)
		{
		case Event::Closed:
			rodando = false;
			break;

		case Event::KeyPressed:

			if (!pausado) {
				if (e.key.code == Keyboard::W) {
					jogador1->setAnimacao(Jogador::PULANDO);
					jogador1->pular();
				}

				if (e.key.code == Keyboard::I && jogador2) {
					jogador2->setAnimacao(Jogador::PULANDO);
					jogador2->pular();
				}

				if (e.key.code == Keyboard::C) {
					jogador1->atirar();
				}

				if (e.key.code == Keyboard::N && jogador2) {

					jogador2->atirar();

				}
			}
			if (e.key.code == Keyboard::Escape) {
				if (timer_de_pausa.getElapsedTime().asMilliseconds() > 50) {
					timer_de_pausa.restart();
					pausado = !pausado;
				}
			}

			break;

		case Event::KeyReleased:
			
			switch (e.key.code)
			{
			case Keyboard::A:
			case Keyboard::D:
				jogador1->setVelocX(0);
				jogador1->setAnimacao(Jogador::PARADO);
				break;

			case Keyboard::J:
			case Keyboard::L:
				if (jogador2) {
					jogador2->setVelocX(0);
					jogador2->setAnimacao(Jogador::PARADO);
				}
				break;
			}
			break;
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			jogador1->setAnimacao(Jogador::MOVENDO, false);
			jogador1->setVelocX(-VELOCX_JOGADOR);
			jogador1->estaParaDireita(false);
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			jogador1->setAnimacao(Jogador::MOVENDO, false);
			jogador1->setVelocX(VELOCX_JOGADOR);
			jogador1->estaParaDireita(true);
		}

		if (Keyboard::isKeyPressed(Keyboard::J) && jogador2) {
			jogador2->setAnimacao(Jogador::MOVENDO, false);
			jogador2->setVelocX(-VELOCX_JOGADOR);
			jogador2->estaParaDireita(false);
		}

		if (Keyboard::isKeyPressed(Keyboard::L) && jogador2) {
			jogador2->setAnimacao(Jogador::MOVENDO, false);
			jogador2->setVelocX(VELOCX_JOGADOR);
			jogador2->estaParaDireita(true);
		}
	}
}

void Fase::pausa()
{
	while (pausado)
	{
		Event e;
		checarEventos(e);
		dT_frames = timer_frames.restart().asSeconds();
	}
}	

void Fase::ajustarCamera()
{
	Vector2f media;
	if (jogador1->estaViva()) {
		if (jogador2) {
			if (jogador2->estaViva()) {
				media = Vector2f(
					(jogador1->getPosicao().x + jogador2->getPosicao().x) / 2,
					(jogador1->getPosicao().y + jogador2->getPosicao().y) / 2);
			}
			else
				media = jogador1->getPosicao();
		}
		else {
			media = jogador1->getPosicao();
		}
	}
	else if (jogador2 && jogador2->estaViva()) {
		media = jogador2->getPosicao();
	}
	else
		media = camera.getCenter();
	camera.setCenter(media);
	
	// Limita a câmera dentro da fase
	if (camera.getCenter().x - (camera.getSize().x / 2) < 0)
		camera.setCenter(camera.getSize().x / 2, camera.getCenter().y);
	if (camera.getCenter().x + (camera.getSize().x / 2) > plataformas.getSpriteAtual().getGlobalBounds().width)
		camera.setCenter(plataformas.getSpriteAtual().getGlobalBounds().width - (camera.getSize().x / 2), camera.getCenter().y);
	if (camera.getCenter().y - (camera.getSize().y / 2) < 0)
		camera.setCenter(camera.getCenter().x, camera.getSize().y / 2);
	if (camera.getCenter().y + (camera.getSize().y / 2) > plataformas.getSpriteAtual().getGlobalBounds().height)
		camera.setCenter(camera.getCenter().x, plataformas.getSpriteAtual().getGlobalBounds().height - (camera.getSize().y / 2));

	borda1->setPosicao(Vector2f(camera.getCenter().x - (camera.getSize().x / 2), 0));
	borda2->setPosicao(Vector2f(camera.getCenter().x + (camera.getSize().x / 2), 0));

	GerenciadorGrafico::Instancia()->getJanela()->setView(camera);
}
