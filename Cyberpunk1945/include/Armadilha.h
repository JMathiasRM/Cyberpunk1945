#pragma once

#include "Obstaculo.h"

///MUDADO agr tem essas macros em todos os obstaculos
#define CORRECAO_ARMADILHA -20
#define TAMANHO_ARMADILHA Vector2f(100,100)

namespace Obstaculos
{
	class Armadilha :
		public Obstaculo
	{
	private:
		SoundBuffer buffer_som_ativada;
		Sound som_ativada;

	public:
		enum TipoDeAnimacao {
			NORMAL,
			ATIVADO
		};
	public:
		Armadilha(Vector2f posicao_inicial = Vector2f(0, 0), Vector2f tamanho = TAMANHO_ARMADILHA);
		~Armadilha();

		void executar();

		void colisaoEspecial(Jogador* alvo, int lado);
	};
}