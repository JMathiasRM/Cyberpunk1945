#include "GerenciadorGrafico.h"
#include "Imagem.h"

using namespace Visual;

GerenciadorGrafico* GerenciadorGrafico::_instancia = NULL;

GerenciadorGrafico::GerenciadorGrafico(VideoMode resolucao, String titulo):
	janela(resolucao, titulo, Style::Fullscreen)
{
}

GerenciadorGrafico* GerenciadorGrafico::Instancia(VideoMode resolucao, String titulo)
{
	if(!_instancia)
		_instancia = new GerenciadorGrafico(resolucao, titulo);
	return _instancia;

}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::limparJanela()
{
	janela.clear();
}

void GerenciadorGrafico::desenhar(Drawable&& objeto)
{
	janela.draw(objeto);
}
void GerenciadorGrafico::desenhar(RectangleShape objeto)
{
	janela.draw(objeto);
}

void GerenciadorGrafico::atualizarJanela()
{
	janela.display();
}

Texture* GerenciadorGrafico::carregaTextura(const char* caminho)
{
	Image img;
	img.loadFromFile(caminho);
	img.createMaskFromColor(Color::Black);
	img.createMaskFromColor(Color::White);

	Texture* nTextura = new Texture;
	if (!nTextura->loadFromImage(img))
		return NULL;
	return nTextura;
}
