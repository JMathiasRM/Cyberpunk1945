#pragma once
#include "Entidade.h"
#include "Personagem.h"

#define VELOC_PROJETIL 12

using namespace Personagens;

namespace Artefatos
{
	class Projetil :
		public Entidade
	{
	protected:
		Vector2f velocidade;

		int discancia_percorrida;

	public:
		Projetil(Vector2f posicao = Vector2f{ 0,0 }, Vector2f tamanho = Vector2f{ 10,10 }, int direcao = 0);
		~Projetil();

		void executar();
		void mover();

		int getDistancia() { return discancia_percorrida; };

		void colisaoEspecial(Personagem* alvo, int direcao);
	};
}