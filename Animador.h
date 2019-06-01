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
		Constr�i o gerenciador gr�fico com valores padr�o ou passados como par�metro.
		@param IMG_PATH Caminho para a imagem usada como textura, relativo � pasta do projeto
		@param n_linhas N�mero de linhas na folha de sprites
		@param n_colunas N�mero de colunas na folha de sprites
		@param frames_por_animacao Objeto vector armazenando o n�mero de frames que cada anima��o cont�m
		@param tamanho Tamanho (x,y) da imagem que ser� mostrada na tela
	*/
	Animador(const char* IMG_PATH = "", unsigned int n_linhas = 0, unsigned int n_colunas = 0,
			const vector<unsigned int>& frames_por_animacao = vector<unsigned int>(), Vector2f tamanho = Vector2f(0,0));
	/*
		Destr�i o objeto e libera a mem�ria alocada.
	*/
	~Animador();
	
	/*
		Atualiza qual anima��o o objeto est� executando.
		@param tipo Tipo de anima��o, correspondente � linha na matriz de sprites
	*/
	void setAnimacao(int tipo) { TIPO_DE_ANIMACAO = tipo; };

	/*
		Utiliza tempo real para controlar a renderiza��o de anima��es na tela.
		@param dT Tempo passado desde a �ltima atualiza��o do loop principal
	*/
	void atualizarAnimacao(float dT);
};

#endif // ANIMADOR_H__