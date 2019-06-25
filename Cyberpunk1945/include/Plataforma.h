#pragma once

#include "GerenciadorGrafico.h"
#include "Obstaculo.h"

namespace Obstaculos
{
	class Plataforma :
		public Obstaculo
	{
	public:
		Plataforma(Vector2f posicao_inicial = Vector2f(0, 0), Vector2f tamanho = { 0,0 });
		~Plataforma();

		void executar() {};

		void colisaoEspecial(Jogador* alvo, int lado) {};

		void setPosicao(Vector2f pos) { hitbox.setPosition(pos); };
	};
}