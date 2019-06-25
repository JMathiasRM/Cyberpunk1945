#pragma once

#include "Menu.h"
#include "Fase.h"
#include "Jogador.h"

using namespace sf;
using namespace Menus;
using namespace Fases;
using namespace Personagens;

class Jogo
{
private:
	Menu menu;

	Fase* fase;

	Jogador jogador1;
	Jogador jogador2;

public:
	Jogo();
	~Jogo();
	void executar();
};