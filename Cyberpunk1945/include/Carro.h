#pragma once

#include "Inimigo.h"

#define CORRECAO_CARRO -70
#define VELOC_CARRO 1

namespace Personagens
{
	namespace Inimigos
	{
		class Carro :
			public Inimigo
		{
		public:
			Carro(Vector2i posicao = { 0,0 });
			~Carro();
		};
	}
}