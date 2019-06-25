#include "Personagem.h"

using namespace Personagens;

Personagens::Personagem::Personagem(const char* endereco_textura, Vector2f tamanho, Vector2f posicao_inicial, const vector<float>& tempo_por_frame,
						Vector2u LinhasxColunas, const vector<unsigned int>& frames_por_animacao,
						Vector2u tamanho_hitbox, Vector2f dif_hitbox_e_sprite):
					Entidade(endereco_textura, tamanho, posicao_inicial, tempo_por_frame, LinhasxColunas, frames_por_animacao,
							tamanho_hitbox, dif_hitbox_e_sprite)
{

}


Personagens::Personagem::~Personagem()
{
}

void Personagens::Personagem::mover()
{
	hitbox.move(velocidade);
}

void Personagens::Personagem::pular(int alturaPulo)
{
	if (pulos > 0 && relogio_da_queda.getElapsedTime().asMilliseconds() > 100) {
		relogio_da_queda.restart();
		setVelocY(static_cast<float>(-sqrt(2 * GRAVIDADE * alturaPulo)));
		pulos--;
	}
}

void Personagens::Personagem::resetarPulos()
{
	pulos = QTPULOS;
}

void Personagens::Personagem::executar()
{
	velocidade.y += GRAVIDADE;

	if (velocidade.x < 0)
		paraDireita = false;
	else
		paraDireita = true;
}

void Personagens::Personagem::dano()
{
	vidas--;
}