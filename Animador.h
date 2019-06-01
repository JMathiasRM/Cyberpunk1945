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
	int TIPO_DE_ANIMACAO;

	float dT_por_frame;
	float dT_acumulado;
	unsigned int frame_atual;

	Vector2f razao;

	RenderWindow* janela_do_jogo;

public:
	/*
		Constrói o gerenciador gráfico com valores padrão ou passados como parâmetro.
		@param IMG_PATH Caminho para a imagem usada como textura, relativo à pasta do projeto
		@param n_linhas Número de linhas na folha de sprites
		@param n_colunas Número de colunas na folha de sprites
		@param frames_por_animacao Objeto vector armazenando o número de frames que cada animação contém
		@param tamanho Tamanho (x,y) da imagem que será mostrada na tela
	*/
	Animador(const char* IMG_PATH = "", unsigned int n_linhas = 0, unsigned int n_colunas = 0,
			const vector<unsigned int>& frames_por_animacao = vector<unsigned int>(), Vector2f tamanho = Vector2f(0,0));
	/*
		Destrói o objeto e libera a memória alocada.
	*/
	~Animador();
	
	/*
		Atualiza qual animação o objeto está executando.
		@param tipo Tipo de animação, correspondente à linha na matriz de sprites
	*/
	void setAnimacao(int tipo) { TIPO_DE_ANIMACAO = tipo; };

	/*
		Utiliza tempo real para controlar a renderização de animações na tela.
		@param dT Tempo passado desde a última atualização do loop principal
	*/
	void atualizarAnimacao(float dT);
};

#endif // ANIMADOR_H__