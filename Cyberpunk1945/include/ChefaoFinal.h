#pragma once

#include "Inimigo.h"

namespace Fases
{
	class Fase;
}

namespace Personagens
{
	namespace Inimigos
	{
		class ChefaoFinal :
			public Inimigo
		{
		private:
			Clock timer_de_ataque;
			float tempo_por_ataque;

			bool atacando;

			Fases::Fase* fase;

		public:
			enum TipoAnimacao {
				NORMAL_VIDACHEIA,
				ATACANDO_VIDACHEIA,

				NORMAL_MEIAVIDA,
				ATACANDO_MEIAVIDA,

				NORMAL_VIDABAIXA,
				ATACANDO_VIDABAIXA,

				MORRENDO
			};
		public:
			ChefaoFinal(Fases::Fase* fase_onde_esta = NULL,
				// Parâmetros referentes à construção de Inimigo
				const char* endereco_textura = "", Vector2f tamanho = Vector2f(0, 0), Vector2f posicao_inicial = Vector2f(0, 0),
				const vector<float>& tempo_por_frame = { 0 }, Vector2u LinhasxColunas = Vector2u(1, 1), const vector<unsigned int>& frames_por_animacao = { 1 },
				Vector2u tamanho_hitbox = Vector2u(0, 0), Vector2f dif_hitbox_e_sprite = Vector2f(0, 0));
			~ChefaoFinal();

			void executar();

			void ataque1();
			void ataque2();
			void ataque3();
		};
	}
}