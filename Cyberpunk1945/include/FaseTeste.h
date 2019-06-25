#pragma once

#include "Fase.h"

#define CAMINHO_FUNDO "Imagens\\fases\\faseTeste1-1.png"

class FaseTeste :
	public Fase
{
public:
	FaseTeste();
	~FaseTeste();

	void carregarObstaculos();

	void executar();
};

