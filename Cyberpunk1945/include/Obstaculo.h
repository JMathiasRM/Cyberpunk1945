#pragma once

#include "Entidade.h"
#include "Jogador.h"

using namespace Personagens;

namespace Obstaculos
{
	class Obstaculo :
		public Entidade
	{
	public:
		///MUDADO construtores: o primeiro � pra criar plataforma, o outro pra obstaculos que existem de verdade
		Obstaculo(Vector2f posicao_inicial, Vector2f tamanho);
		Obstaculo(
			// Par�metros para a constru��o da Entidade
			const char* endereco_textura = "", Vector2f tamanho = Vector2f(0, 0), Vector2f posicao_inicial = Vector2f(0, 0),
			const vector<float>& tempo_por_frame = { 0 }, Vector2u LinhasxColunas = Vector2u(1, 1), const vector<unsigned int>& frames_por_animacao = { 1 },
			Vector2u tamanho_hitbox = Vector2u(0, 0), Vector2f dif_hitbox_e_sprite = Vector2f(0, 0));
		virtual ~Obstaculo();

		virtual void executar() = 0;

		/// Faz certa a��o caracter�stica do obst�culo em caso de colis�o
		virtual void colisaoEspecial(Jogador* alvo, int lado) = 0;

		/// Gera um obst�culo aleat�rio
		static Obstaculo* obstaculoAleatorio(Vector2f posicao);
	};
}