#include "Jogo.h"
#include "Animador.h"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<unsigned int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(6);

	Animador anim("..\\Imagens\\Personagens\\Player1.png", 6, 3, v);
	Jogo jogo;
	jogo.main();

	return 0;
}