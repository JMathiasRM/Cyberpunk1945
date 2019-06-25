#include "Tanque.h"

using namespace Personagens;
using namespace Inimigos;

Tanque::Tanque(Vector2i posicao):
	Entidade(CAMINHO_TANQUE, Vector2f(200, 100), Vector2f(posicao), vector<float>{0.125, 0.1, 0.125}, Vector2u(3, 6), vector<unsigned int>{2, 4, 6}, Vector2u(68, 32), Vector2f(9, 16))
{
	velocidade.x = VELOC_TANQUE;
	vidas = 3;

	buffer_som_morte.loadFromFile("src/som/Efeitos_Sonoros/tanque_morte.wav");
	som_morte.setBuffer(buffer_som_morte);
}


Tanque::~Tanque()
{
}