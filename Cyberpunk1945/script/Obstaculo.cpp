#include "Obstaculo.h"

#include "Mina.h"
#include "Armadilha.h"
#include "Arame.h"

using namespace Obstaculos;
using namespace Visual;

Obstaculo::Obstaculo(Vector2f posicao_inicial, Vector2f tamanho):
	Entidade(posicao_inicial, tamanho)
{
	
}

Obstaculo::Obstaculo(const char* endereco_textura, Vector2f tamanho, Vector2f posicao_inicial, const vector<float>& tempo_por_frame,
					Vector2u LinhasxColunas, const vector<unsigned int>& frames_por_animacao, Vector2u tamanho_hitbox, Vector2f dif_hitbox_e_sprite):
	Entidade(endereco_textura, tamanho, posicao_inicial, tempo_por_frame, LinhasxColunas, frames_por_animacao, tamanho_hitbox, dif_hitbox_e_sprite)
{
}


Obstaculo::~Obstaculo()
{
}

Obstaculo* Obstaculo::obstaculoAleatorio(Vector2f posicao)
{
	int r = rand() % 3;
	switch (r) {
	case 0:
		return new Mina(Vector2f(posicao.x, posicao.y + CORRECAO_MINA));
	case 1:
		return new Armadilha(Vector2f(posicao.x, posicao.y + CORRECAO_ARMADILHA));
	case 2:
		return new Arame(Vector2f(posicao.x, posicao.y + CORRECAO_ARAME));
	}

	return NULL;
}
