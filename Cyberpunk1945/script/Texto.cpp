#include "Texto.h"

using namespace Visual;

Texto::Texto()
{
}

Texto::Texto(String caminho_da_fonte, unsigned int tamanho_da_fonte, Color cor)
{
	fonte.loadFromFile(caminho_da_fonte);
	texto.setFont(fonte);

	texto.setFillColor(cor);
	if (tamanho_da_fonte != 0)
		texto.setCharacterSize(tamanho_da_fonte);
}

Texto::~Texto()
{
}

String Texto::stringAleatoria(unsigned int n_chars)
{
	String s;

	for (unsigned int i = 0; i < n_chars; i++) {
		char c = (rand() % 89) + 33;
		s.insert(i, c);
	}

	return s;
}