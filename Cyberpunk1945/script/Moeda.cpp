#include "Moeda.h"

using namespace Artefatos;

Moeda::Moeda(Vector2f posicao):
	Entidade("src/imagens/moedas/moeda.png", Vector2f(50, 50), Vector2f(posicao.x, posicao.y + CORRECAO_MOEDA), vector<float>{0.1}, Vector2u(1, 4), vector<unsigned int>{4}, Vector2u(30,30)),
	coletada(false)
{
}


Moeda::~Moeda()
{
}
