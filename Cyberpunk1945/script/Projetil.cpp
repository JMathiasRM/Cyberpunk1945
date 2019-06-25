#include "Projetil.h"

using namespace Personagens;
using namespace Artefatos;

Projetil::Projetil(Vector2f posicao, Vector2f tamanho, int direcao) :
	Entidade("src/imagens/projeteis/projetil.png", tamanho, Vector2f(posicao), vector<float>{0}, Vector2u(1, 1), vector<unsigned int>{1}, Vector2u(tamanho)),
	velocidade(Vector2f(direcao * VELOC_PROJETIL, 0.0f))
{

}

Projetil::~Projetil()
{
}

void Projetil::executar()
{

}

void Projetil::mover()
{
	hitbox.move(velocidade);
	discancia_percorrida += velocidade.x;
}

void Projetil::colisaoEspecial(Personagem* alvo, int direcao)
{
	alvo->dano();
	alvo->pular((int) (ALTURA_DE_PULO * 0.30) );
}
