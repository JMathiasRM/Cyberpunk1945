#pragma once
#include "Inimigo.h"

#define CORRECAO_SOLDADO -99

#define VELOC_SOLDADO 2

namespace Personagens {
	namespace Inimigos
	{
		class Soldado :
			public Inimigo
		{
		public:
			Soldado(Vector2i posicao = { 0,0 });
			~Soldado();
		};
	}
}