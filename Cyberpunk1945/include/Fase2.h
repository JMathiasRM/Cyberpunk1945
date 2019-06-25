#pragma once

#include "Fase.h"
#include "ChefaoFinal.h"

namespace Fases
{
	class Fase2 :
		public Fase
	{
	private:
		ChefaoFinal chefao;

		Music musica_boss;
	public:
		Fase2();
		~Fase2();

		void carregarObstaculos();
		void carregarInimigos();
		void carregarMoedas();

		void verificarVitoria();
		void verificarVitoriaChefao();

		void executar();

		/// Abre o loop da luta com o chefão
		void lutaFinal();
	};

}