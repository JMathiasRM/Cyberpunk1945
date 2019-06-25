#pragma once

#include "Obstaculo.h"

#define CORRECAO_MINA -13
#define TAMANHO_MINA Vector2f(100,100)

namespace Obstaculos
{
	class Mina :
		public Obstaculo
	{
	private:
		SoundBuffer buffer_som_explosao;
		Sound som_explosao;

	public:
		enum TipoDeAnimacao {
			NORMAL,
			EXPLOSAO
		};
	public:
		Mina(Vector2f posicao_inicial = Vector2f(0, 0), Vector2f tamanho = TAMANHO_MINA);
		~Mina();

		void executar();

		void colisaoEspecial(Jogador* alvo, int lado);
	};
}