#include "Atirador.h"
#include "Colisor.h"

using namespace Personagens;
using namespace Inimigos;
using namespace Obstaculos;

Personagens::Atirador::Atirador(int tempoTiro, Vector2f tamanhoProjetil):
	tempoTiro(tempoTiro),
	tamanhoProjetil(tamanhoProjetil),
	acumulador(0),
	distancia_maxima(500)
{

}

Personagens::Atirador::~Atirador()
{

}

void Personagens::Atirador::moverBalas()
{
	projeteis.zerarIterador();
	if (!projeteis.vazia())
	{
		do {
			projeteis.getObjeto()->mover();
			if (abs(projeteis.getObjeto()->getDistancia()) >= distancia_maxima)
				projeteis.popLista(projeteis.getObjeto());
		} while (projeteis.moverIterador());
	}
	
}

void Personagens::Atirador::atirar(Vector2f posicao, int direcao)
{
	projeteis.pushLista(new Projetil(posicao, tamanhoProjetil, direcao));
}

void Personagens::Atirador::ataque(Personagem* alvo)
{
	if (!projeteis.vazia()) {
		projeteis.zerarIterador();
		do {
			if (Colisor::colisaoGenerica(alvo, projeteis.getObjeto())) {
				alvo->dano();
				projeteis.popLista(projeteis.getObjeto());
			}
		} while (projeteis.moverIterador());
	}
}

void Personagens::Atirador::colidirProjeteis(Obstaculo* alvo)
{
	if (!projeteis.vazia()) {
		projeteis.zerarIterador();
		do {
			if (Colisor::colisaoGenerica(alvo, projeteis.getObjeto())) {
				projeteis.popLista(projeteis.getObjeto());
			}
		} while (projeteis.moverIterador());
	}
}

void Personagens::Atirador::desenhar(float dT)
{
	Entidade::desenhar(dT);
	if (!projeteis.vazia())
	{
		do {
			projeteis.getObjeto()->desenhar();
		} while (projeteis.moverIterador());
	}
}