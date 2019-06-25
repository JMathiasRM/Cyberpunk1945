#pragma once

#include "Inimigo.h"

#define CORRECAO_TANQUE -70
#define VELOC_TANQUE 1

namespace Personagens
{
	namespace Inimigos
	{
		class Tanque :
			public Inimigo
		{
		public:
			Tanque(Vector2i posicao = { 0,0 });
			~Tanque();
		};
	}
}