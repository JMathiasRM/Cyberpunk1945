#pragma once

#include "ListaDeEntidades.h"
#include "Jogador.h"
#include "Soldado.h"
#include "Carro.h"
#include "Tanque.h"
#include "Plataforma.h"
#include "Mina.h"
#include "Arame.h"
#include "Armadilha.h"
#include "Colisor.h"

using namespace Personagens;
using namespace Visual;
using namespace Obstaculos;
using namespace Inimigos;
using namespace Artefatos;

namespace Fases
{
	class Fase :
		public Entidade
	{
	protected:
		ListaDeEntidades listaEntidades;
		Jogador* jogador1;
		Jogador* jogador2;

		Colisor colisor;

		bool rodando;

		bool pausado;

		Imagem plataformas;

		View camera;

		Plataforma* borda1;
		Plataforma* borda2;

		Clock timer_de_pausa;

		Clock timer_frames;
		float dT_frames;

		bool ganhou;

		Music musica_fase;

	public:
		Fase(const char* caminho_fundo = NULL, const char* caminho_plataformas = NULL, Vector2u tamanho_fase = { 0,0 });
		virtual ~Fase();

		/// Carrega os obstáculos da fase
		virtual void carregarObstaculos() = 0;
		/// Carrega os inimigos da fase
		virtual void carregarInimigos() = 0;
		/// Carrega as moedas da fase
		virtual void carregarMoedas() = 0;

		/// Verifica as condições de vitória
		virtual void verificarVitoria() = 0;

		/// Coloca os jogadores na fase e reseta seus atributos
		void setJogador(Jogador* jogador1, Jogador* jogador2 = NULL);

		/// Coloca todas as entidades do colisor na lista de entidades
		void inserirEntidades();

		/// Insere um inimigo no colisor e na lista de entidades
		void criarInimigo(Inimigo* inimigo);

		/// Gera a fase selecionada
		static Fase* construirFase(int n);

		/// Loop principal da fase
		virtual void executar() = 0;

		/// Desenha o fundo e as plataformas
		virtual void desenharFundo();
		/// Desenha o overlay com as vidas dos personagens
		virtual void desenharVidaPersonagens();

		/// Verifica os eventos de teclado
		void checarEventos(Event& e);

		/// Abre loop de pausa
		void pausa();

		/// Faz a câmera acompanhar o jogador
		void ajustarCamera();

		/// Verifica se o jogador ganhou
		bool vitoria() const { return ganhou; };
	};
}