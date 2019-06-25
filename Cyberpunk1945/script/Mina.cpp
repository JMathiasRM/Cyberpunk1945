#include "Mina.h"

using namespace Obstaculos;
using namespace Visual;

Mina::Mina(Vector2f posicao_inicial, Vector2f tamanho):
	Obstaculo(CAMINHO_MINA, tamanho, posicao_inicial, vector<float>{0.125f, 0.1f}, Vector2u(2, 5), vector<unsigned int>{2, 5}, Vector2u(9,4), Vector2f(12,28))
{
	buffer_som_explosao.loadFromFile("src/som/Efeitos_Sonoros/mina_ativada.wav");
	som_explosao.setBuffer(buffer_som_explosao);
}

Mina::~Mina()
{
}

void Mina::executar()
{
}

void Mina::colisaoEspecial(Jogador* alvo, int lado)
{
	som_explosao.play();
	alvo->dano();
	alvo->pular(ALTURA_DE_PULO/2);
	imagem.setAnimacao(Mina::EXPLOSAO);
	morrer();
}
