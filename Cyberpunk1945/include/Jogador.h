#pragma once

#include "Personagem.h"
#include "Texto.h"
#include "Atirador.h"

namespace Personagens
{
	class Jogador :
		public Personagem,
		public Atirador
	{
	private:
		// Jogador 1 ou 2
		int id_jogador;

		int pontos;

		Imagem vida_imagem;
		Texto texto_pontuacao;

		bool knockback;

		SoundBuffer buffer_som_atirando;
		Sound som_atirando;

	public:
		enum TipoAnimacao {
			PARADO,
			MOVENDO,
			PULANDO,
			MORTE
		};
	public:
		Jogador(int qual_jogador = 0,
			
			// Parâmetros para construção de Personagem
			const char* endereco_textura = "", Vector2f tamanho = Vector2f(0, 0), Vector2f posicao_inicial = Vector2f(0, 0),
			const vector<float>& tempo_por_frame = {0}, Vector2u LinhasxColunas = Vector2u(1, 1), const vector<unsigned int>& frames_por_animacao = { 1 },
			Vector2u tamanho_hitbox = Vector2u(0, 0), Vector2f dif_hitbox_e_sprite = Vector2f(0, 0));
		~Jogador();

		void executar();
		
		/// Jogador cai
		void cair();
		/// Jogador perde vida
		void dano();

		/// Aumenta os pontos do jogador
		void aumentarPontuacao() { pontos++; };

		void setPosicaoVida(Vector2f pos) { vida_imagem.setPosicao(pos); };
		void setPosicaoPontuacao(Vector2f pos) { texto_pontuacao.setPosicao(pos); };
		void setPosicao(Vector2f pos) { imagem.setPosicao(pos); hitbox.setPosition(pos); };

		/// Restaura os atributos iniciais do jogador
		void restaurar();

		bool emKnockback() const { return knockback; };
		void setKnockback(bool knockback) { this->knockback = knockback; };

		/// Desenha o overlay de vida
		void desenharVida();

		/// Jogador atira
		void atirar();
	};
}