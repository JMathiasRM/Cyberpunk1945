#include "Arame.h"
#include "Colisor.h"

using namespace Obstaculos;
using namespace Visual;

Arame::Arame(Vector2f posicao_inicial, Vector2f tamanho):
	Obstaculo(CAMINHO_ARAME, tamanho, posicao_inicial, vector<float>{ 0 }, Vector2u(1, 1), vector<unsigned int>{1}, Vector2u(64,32))
{
}

Arame::~Arame()
{
}

void Arame::executar()
{
}

void Arame::colisaoEspecial(Jogador* alvo, int lado)
{
	alvo->dano();
	if (lado == DIR_TOPO)
		alvo->pular(ALTURA_DE_PULO / 2);
}