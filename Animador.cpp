#include "Animador.h"

Animador::Animador(const char* IMG_PATH, unsigned int n_linhas, unsigned int n_colunas, const vector<unsigned int>& frames_por_animacao):
	frames_por_animacao(frames_por_animacao)
{
	if(IMG_PATH != "" && frames_por_animacao.size() > 0)
	{
		Image img;
		img.loadFromFile(IMG_PATH);
		img.createMaskFromColor(Color::Black);
		img.createMaskFromColor(Color::White);

		textura.loadFromImage(img);
		N_ANIMACOES = n_linhas;

		// Sprites
		sprites = new Sprite*[N_ANIMACOES];
		for (unsigned int i = 0; i < N_ANIMACOES; i++) {
			sprites[i] = new Sprite[this->frames_por_animacao.at(i)];
		}

		Vector2u clip_tamanho(textura.getSize().x / n_colunas, textura.getSize().y / n_linhas);
		IntRect clip(0, 0, clip_tamanho.x, clip_tamanho.y);

		for (unsigned int linha = 0; linha < N_ANIMACOES; linha++) {
			for (unsigned int frame = 0; frame < this->frames_por_animacao.at(linha); frame++) {
				sprites[linha][frame].setTexture(textura);
				sprites[linha][frame].setTextureRect(clip);
				sprites[linha][frame].setScale(5, 5);
				clip.left += clip_tamanho.x;
			}
			clip.left = 0;
			clip.top += clip_tamanho.y;
		}
	}

	RenderWindow window(VideoMode(800, 600), "a");

	while(1)
	for (unsigned int linha = 0; linha < N_ANIMACOES; linha++) {
		for (unsigned int frame = 0; frame < this->frames_por_animacao[linha]; frame++) {
			window.clear();
			window.draw(sprites[linha][frame]);
			window.display();

			Time t = seconds(1);
			sleep(t);
		}
	}
}


Animador::~Animador()
{
}
