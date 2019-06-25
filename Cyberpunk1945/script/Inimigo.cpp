#include "Inimigo.h"

#include "Soldado.h"
#include "Carro.h"
#include "Tanque.h"

#include "Colisor.h"

using namespace Personagens;
using namespace Inimigos;

Inimigo::Inimigo(const char* endereco_textura, Vector2f tamanho, Vector2f posicao_inicial, const vector<float>& tempo_por_frame,
				Vector2u LinhasxColunas, const vector<unsigned int>& frames_por_animacao,
				Vector2u tamanho_hitbox, Vector2f dif_hitbox_e_sprite):
	Atirador(60),
	Entidade(endereco_textura, tamanho, posicao_inicial, tempo_por_frame, LinhasxColunas, frames_por_animacao, tamanho_hitbox, dif_hitbox_e_sprite)
{
}


Inimigo::~Inimigo()
{
}

Inimigo* Inimigo::inimigoAleatorio(Vector2f(posicao))
{
	int r = rand() % 3;
	switch (r) {
	case 0:
		return new Soldado(Vector2i(posicao.x, posicao.y + CORRECAO_SOLDADO));
	case 1:
		return new Carro(Vector2i(posicao.x, posicao.y + CORRECAO_CARRO));
	case 2:
		return new Tanque(Vector2i(posicao.x, posicao.y + CORRECAO_TANQUE));
	}

	return NULL;
}

void Inimigo::colisaoEspecial(Personagem* alvo, int direcao)
{
	alvo->dano();
	alvo->pular(ALTURA_DE_PULO * 0.3);
	switch (direcao) {
	case DIR_DIREITA:
		alvo->setVelocX(fabs(velocidade.x) * 2);
		break;
	case DIR_ESQUERDA:
		alvo->setVelocX(fabs(velocidade.x) * -2);
		break;
	}
}


void Inimigo::executar()
{
	velocidade.y += GRAVIDADE;

	if (velocidade.x < 0)
		paraDireita = false;
	else
		paraDireita = true;

	if (vidas <= 0 && !em_animacao_de_morte) {
		som_morte.play();
		morrer();
		imagem.setAnimacao(MORRENDO);
	}

	if (++acumulador >= tempoTiro && vidas > 0) {
		acumulador = 0;
		atirar(Vector2f(hitbox.getPosition().x + hitbox.getSize().x, hitbox.getPosition().y + hitbox.getSize().y / 2), paraDireita ? 1 : -1);
	}

	moverBalas();
}