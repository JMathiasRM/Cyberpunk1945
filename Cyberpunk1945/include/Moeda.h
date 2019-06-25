#pragma once

#include "Entidade.h"

#define CORRECAO_MOEDA -75

namespace Artefatos
{
	class Moeda :
		public Entidade
	{
	private:
		bool coletada;

	public:
		Moeda(Vector2f posicao = { 0,0 });
		~Moeda();

		bool jaFoiColetada() { return coletada; };
		void foiColetada(bool sim_ou_nao) { coletada = sim_ou_nao; };

		void executar() {};
	};
}