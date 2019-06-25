#pragma once

#include "GerenciadorGrafico.h"
#include <vector>

using namespace std;
using namespace sf;

namespace Visual
{
	class Imagem
	{
	private:

		Texture* textura;
		Sprite** sprites;

		unsigned int N_ANIMACOES;
		vector<unsigned int> frames_por_animacao;
		int TIPO_DE_ANIMACAO;

		vector<float> dT_por_frame;
		float dT_acumulado;
		unsigned int frame_atual;

		Vector2f razao;

		Vector2f diferenca_textura_e_hitbox;

		int largura_hitbox;

		///MUDADO add essa flag
		bool em_animacao_de_morte;

	public:
		Imagem(Texture* nTextura = NULL, Vector2f tamanho = Vector2f(0, 0),
			const vector<float>& tempo_por_frame = { 0 }, Vector2u LinhasxColunas = Vector2u(1, 1),
			const vector<unsigned int>& frames_por_animacao = { 1 },
			Vector2f dif_hitbox_e_sprite = Vector2f(0, 0));
		~Imagem();

		/// Seta qual linha da matriz de sprites será desenhada
		void setAnimacao(int tipo, bool resetar_frame_atual = true) { TIPO_DE_ANIMACAO = tipo; if (resetar_frame_atual)frame_atual = 0; };

		/// Controla a passagem de um frame para o outro usando tempo real
		bool atualizarAnimacao(float dT = 0);

		/// Verifica se a imagem está vazia
		bool vazio();

		/// Verifica se o mouse está dentro da imagem
		bool mouseDentro();

		/// Retorna a sprite atual
		Sprite getSpriteAtual() const { return sprites[TIPO_DE_ANIMACAO][frame_atual]; };
		/// Retorna a razão entre o tamanho da sprite na tela e na imagem usada como fonte
		Vector2f getRazao() const { return razao; };

		/// Muda a diferença entre a posição da textura e da hitbox
		void setDiferenca(Vector2f diferenca) { diferenca_textura_e_hitbox = diferenca; };
		/// Muda a posição da sprite
		void setPosicao(Vector2f posicao_hitbox) { sprites[TIPO_DE_ANIMACAO][frame_atual].setPosition(posicao_hitbox - diferenca_textura_e_hitbox); };

		/// Seta se está em animação de morte
		void setAnimacaoDeMorte(bool esta_ou_nao) { em_animacao_de_morte = esta_ou_nao; };

		/// Seta a largura da hitbox
		void setLarguraHitbox(int l) { largura_hitbox = l; };

		/// Inverte a sprite
		void inverterSprite();

		void operator= (const Imagem& novaImagem);
	};
}