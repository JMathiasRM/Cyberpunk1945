#include "Carro.h"

using namespace Personagens;
using namespace Inimigos;

Carro::Carro(Vector2i posicao):
	Entidade(CAMINHO_CARRO, Vector2f(200, 100), Vector2f(posicao), vector<float>{0.125f, 0.15f, 0.125f}, Vector2u(3, 6), vector<unsigned int>{2, 4, 6}, Vector2u(87, 33), Vector2f(5, 15))
{
	velocidade.x = VELOC_CARRO;
	vidas = 2;
	buffer_som_morte.loadFromFile("src/som/Efeitos_Sonoros/carro_morte.wav");
	som_morte.setBuffer(buffer_som_morte);
}


Carro::~Carro()
{
}