#pragma once

#include "Imagem.h"

using namespace Visual;

class Entidade
{
protected:

	Imagem imagem;
	RectangleShape hitbox;

	bool em_animacao_de_morte;
	bool morta;

	bool paraDireita;

	SoundBuffer buffer_som_morte;
	Sound som_morte;

public:
	Entidade(const char* endereco_textura = "", Vector2f tamanho = Vector2f(0,0), Vector2f posicao_inicial = Vector2f(0,0),
		const vector<float>& tempo_por_frame = {0}, Vector2u LinhasxColunas = Vector2u(1, 1), const vector<unsigned int>& frames_por_animacao = {1},
		Vector2u tamanho_hitbox = Vector2u(0,0), Vector2f dif_hitbox_e_sprite = Vector2f(0,0));
	Entidade(Vector2f posicao, Vector2f tamanho);
	virtual ~Entidade();

	/// Move a entidade
	virtual void mover() {};
	/// Desenha a entidade
	virtual void desenhar(float dT=0);
	
	// Apenas para testes
	void desenharHitbox();

	virtual void executar() = 0;

	/// Verifica a menor distância entre as entidades
	Vector2f distancia(Entidade* entidade);

	bool estaViva() { return !morta; };
	bool estaMorrendo() const { return em_animacao_de_morte; };

	Vector2f getPosicao() const { return hitbox.getPosition(); };
	Vector2f getTamanho() const { return hitbox.getSize(); };

	/// Seta as flags de morte
	void morrer();

	void estaParaDireita(bool sim_ou_nao) { paraDireita = sim_ou_nao; };
};