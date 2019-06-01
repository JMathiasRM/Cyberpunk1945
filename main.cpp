#include "Jogo.h"
#include "Animador.h"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<unsigned int> v{2,2,2,2,2,3};

	Animador anim("..\\Imagens\\Personagens\\Player1.png", 6, 3, v, Vector2f(300, 300));
	Jogo jogo;
	jogo.main();

	return 0;
}