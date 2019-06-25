#pragma once
#pragma warning(disable: 4250)

#include "Entidade.h"
#include <iostream>

#define ALTURA_DE_PULO 200
#define GRAVIDADE 4

#define VELOCX_JOGADOR 10

#define QTPULOS 1

namespace Personagens
{
	class Personagem :
		virtual public Entidade
	{
	protected:
		Clock relogio_da_queda;
		float dT_queda;

		int pulos;
		int vidas;

		bool knockback;

		Vector2f velocidade;

	public:
		Personagem(const char* endereco_textura = "", Vector2f tamanho = Vector2f(0, 0), Vector2f posicao_inicial = Vector2f(0, 0),
			const vector<float>& tempo_por_frame = {0}, Vector2u LinhasxColunas = Vector2u(1, 1), const vector<unsigned int>& frames_por_animacao = { 1 },
			Vector2u tamanho_hitbox = Vector2u(0, 0), Vector2f dif_hitbox_e_sprite = Vector2f(0, 0));
		virtual ~Personagem();
		
		Vector2f getVeloc() { return velocidade; }

		void setVelocY(float veloc) { velocidade.y = veloc; };
		void setVelocX(float veloc) { if(!knockback || veloc == 0) velocidade.x = veloc; };

		void setAnimacao(int tipo_animacao, bool resetar_frame = true) { imagem.setAnimacao(tipo_animacao, resetar_frame); };

		/// Move o personagem
		void mover();
		/// O personagem pula
		void pular(int alturaPulo = ALTURA_DE_PULO);

		void resetarPulos();

		void resetarTimer() { relogio_da_queda.restart(); };

		virtual void executar();

		/// Tira vida do personagem
		virtual void dano();
	};
}
