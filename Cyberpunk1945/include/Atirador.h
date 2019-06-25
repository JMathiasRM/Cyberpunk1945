#pragma once
#include "Lista.h"
#include "Projetil.h"

namespace Obstaculos
{
	class Obstaculo;
}

using namespace Artefatos;

namespace Personagens {

	class Atirador:
		virtual public Entidade
	{
	protected:
		int acumulador;

		int tempoTiro;
		Vector2f tamanhoProjetil;
		Lista<Projetil> projeteis;

		int distancia_maxima;

	public:
		Atirador(int tempoTiro = 30, Vector2f tamanhoProjetil = Vector2f{ 10,10 });
		~Atirador();

		/// Move os projéteis da lista
		void moverBalas();

		/// Cria um projétil
		virtual void atirar(Vector2f posicao, int direcao);

		/// Verifica colisões entre os projéteis e o alvo
		void ataque(Personagem* alvo);
		/// Verifica colisões entre os projéteis e um obstáculo
		void colidirProjeteis(Obstaculos::Obstaculo* alvo);

		/// Desenha os projéteis
		void desenhar(float dT);
	};

}