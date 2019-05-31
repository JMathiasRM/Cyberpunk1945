#ifndef ANIMADOR_H__
#define ANIMADOR_H__

#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;
using namespace sf;

class Animador
{
private:

	Texture textura;
	Sprite** sprites;

	unsigned int N_ANIMACOES;
	vector<unsigned int> frames_por_animacao;

public:
	Animador(const char* IMG_PATH = "", unsigned int n_linhas = 0, unsigned int n_colunas = 0,
			const vector<unsigned int>& frames_por_animacao = vector<unsigned int>());
	~Animador();
};

#endif // ANIMADOR_H__