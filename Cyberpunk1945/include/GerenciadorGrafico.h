#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#define CAMINHO_MENU_FUNDO "src/imagens/menu/fundo.png"
#define CAMINHO_MENU_BTN_JOGAR "src/imagens/menu/btn_jogar.png"
#define CAMINHO_MENU_BTN_SAIR "src/imagens/menu/btn_sair.png"
#define CAMINHO_MENU_BTN_FASE1 "src/imagens/menu/btn_fase1.png"
#define CAMINHO_MENU_BTN_FASE2 "src/imagens/menu/btn_fase2.png"
#define CAMINHO_MENU_BTN_DOISJOGADORES "src/imagens/menu/btn_doisjogadores.png"

#define CAMINHO_JOGADOR1 "src/imagens/personagens/jogador1.png"
#define CAMINHO_JOGADOR2 "src/imagens/personagens/jogador2.png"

#define CAMINHO_CARRO "src/imagens/personagens/carro.png"
#define CAMINHO_SOLDADO "src/imagens/personagens/soldado.png"
#define CAMINHO_TANQUE "src/imagens/personagens/tanque.png"

#define CAMINHO_MINA "src/imagens/obstaculos/mina_terrestre.png"
#define CAMINHO_ARAME "src/imagens/obstaculos/arame_farpado.png"
#define CAMINHO_ARMADILHA "src/imagens/obstaculos/armadilha.png"

using namespace sf;

namespace Visual
{
	class Imagem;
	/* classe Singleton */
	class GerenciadorGrafico
	{
	private:
		static GerenciadorGrafico* _instancia;
		RenderWindow janela;
		GerenciadorGrafico(VideoMode resolucao, String titulo);

	public:
		static GerenciadorGrafico* Instancia(VideoMode resolucao = VideoMode::getFullscreenModes().at(0), String titulo = "");
		~GerenciadorGrafico();

		/// Carrega uma textura a partir de uma imagem
		static Texture* carregaTextura(const char* caminho);

		/// Desenha um sf::Drawable
		void desenhar(Drawable&& objeto);

		/// Desenha um retângulo
		void desenhar(RectangleShape objeto);

		/// Limpa o buffer da janela
		void limparJanela();
		/// Mostra a janela na tela
		void atualizarJanela();

		/// Verifica se a janela está aberta
		bool janelaAberta() { return janela.isOpen(); };

		/// Retorna a posição do mouse
		Vector2i posicaoMouse() { return Mouse::getPosition(janela); };

		/// Verifica a fila de eventos
		bool janelaPollEvent(Event& e) { return janela.pollEvent(e); };

		/// Fecha a janela;
		void fecharJanela() { janela.close(); };

		/// Fixa a taxa máxima de FPS
		void setFPS(unsigned int fps) { janela.setFramerateLimit(fps); };

		/// Retorna a janela
		RenderWindow* getJanela() { return &janela; };

		/// Retorna o tamanho da janela
		Vector2u getTamanho() { return janela.getSize(); }
	};
}