#include "Soldado.h"

using namespace Personagens;
using namespace Inimigos;

Soldado::Soldado(Vector2i posicao):
	Entidade(CAMINHO_SOLDADO, Vector2f(100, 100), Vector2f(posicao), vector<float>{0.5, 0.5, 0.5}, Vector2u(3, 2), vector<unsigned int>{2, 2, 2}, Vector2u(14, 31), Vector2f(5, 0))
{
	velocidade.x = VELOC_SOLDADO;
	vidas = 1;

	buffer_som_morte.loadFromFile("src/som/Efeitos_Sonoros/soldado_morte.wav");
	som_morte.setBuffer(buffer_som_morte);
}


Soldado::~Soldado()
{
}