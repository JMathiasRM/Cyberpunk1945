#pragma once
#include "Personagem.h"
#include "Atirador.h"

namespace Personagens {

	namespace Inimigos
	{
		class Inimigo :
			public Personagem,
			public Atirador
		{
		public:
			enum TipoAnimacao {
				ANDANDO,
				ATIRANDO,
				MORRENDO
			};
		public:
			Inimigo(
				// Par�metros referentes � constru��o de Personagem
				const char* endereco_textura = "", Vector2f tamanho = Vector2f(0, 0), Vector2f posicao_inicial = Vector2f(0, 0),
				const vector<float>& tempo_por_frame = { 0 }, Vector2u LinhasxColunas = Vector2u(1, 1), const vector<unsigned int>& frames_por_animacao = { 1 },
				Vector2u tamanho_hitbox = Vector2u(0, 0), Vector2f dif_hitbox_e_sprite = Vector2f(0, 0));
			virtual ~Inimigo();

			/// Gera um inimigo aleat�rio
			static Inimigo* inimigoAleatorio(Vector2f(posicao));

			/// Inverte a dire��o do moviemnto
			void mudarDirecao() { velocidade.x *= -1; }
			/// Verifica a colis�o espec�fica de cada inimigo com o alvo
			virtual void colisaoEspecial(Personagem* alvo, int direcao);

			void executar();
		};
	}
}