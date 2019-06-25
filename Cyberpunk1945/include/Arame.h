#pragma once

#include "Obstaculo.h"

#define CORRECAO_ARAME -40
#define TAMANHO_ARAME Vector2f(80,40)

namespace Obstaculos
{
	class Arame :
		public Obstaculo
	{
	public:
		enum TipoDeAnimacao {
			NORMAL
		};
	public:
		Arame(Vector2f posicao_inicial = Vector2f(0, 0), Vector2f tamanho = TAMANHO_ARAME);
		~Arame();

		void executar();

		void colisaoEspecial(Jogador* alvo, int lado);
	};
}