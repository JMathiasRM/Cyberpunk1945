#include "Menu.h"

using namespace Menus;

Menu::Menu(EstadoDeMenu* estado_inicial) :
	estado_atual(estado_inicial)
{
	musica_menu.openFromFile("src/som/Musica/menu.wav");
	musica_menu.setLoop(true);
	musica_menu.setVolume(50);
}

Menu::~Menu()
{
}

void Menu::executar(OpcaoDeMenu& escolha)
{
	estado_atual->executar(escolha);
}