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

		/// Move os proj�teis da lista
		void moverBalas();

		/// Cria um proj�til
		virtual void atirar(Vector2f posicao, int direcao);

		/// Verifica colis�es entre os proj�teis e o alvo
		void ataque(Personagem* alvo);
		/// Verifica colis�es entre os proj�teis e um obst�culo
		void colidirProjeteis(Obstaculos::Obstaculo* alvo);

		/// Desenha os proj�teis
		void desenhar(float dT);
	};

}