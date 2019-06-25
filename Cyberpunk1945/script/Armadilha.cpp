#include "Armadilha.h"
#include "Colisor.h"

using namespace Obstaculos;
using namespace Visual;

Armadilha::Armadilha(Vector2f posicao_inicial, Vector2f tamanho) :
	Obstaculo(CAMINHO_ARMADILHA, tamanho, posicao_inicial, vector<float>{ 1, 0.1 }, Vector2u(2, 2), vector<unsigned int>{1, 2}, Vector2u(32,6), Vector2f(0,10))
{
	buffer_som_ativada.loadFromFile("src/som/Efeitos_Sonoros/armadilha_ativada.wav");
	som_ativada.setBuffer(buffer_som_ativada);
}

Armadilha::~Armadilha()
{
}

void Armadilha::executar()
{
}

void Armadilha::colisaoEspecial(Jogador* alvo, int lado)
{
	if (lado == DIR_TOPO) {
		som_ativada.play();
		imagem.setAnimacao(Armadilha::ATIVADO);
		alvo->dano();
		alvo->pular(ALTURA_DE_PULO/2);
	}
}
