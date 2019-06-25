#include "ChefaoFinal.h"

#include "Fase.h"
#include "Soldado.h"
#include "Tanque.h"

using namespace Personagens;
using namespace Inimigos;
using namespace Fases;

ChefaoFinal::ChefaoFinal(Fase* fase_onde_esta,
						const char* endereco_textura, Vector2f tamanho, Vector2f posicao_inicial, const vector<float>& tempo_por_frame,
						Vector2u LinhasxColunas, const vector<unsigned int>& frames_por_animacao,
						Vector2u tamanho_hitbox, Vector2f dif_hitbox_e_sprite):
	Entidade(endereco_textura, tamanho, posicao_inicial, tempo_por_frame, LinhasxColunas, frames_por_animacao, tamanho_hitbox, dif_hitbox_e_sprite),
	tempo_por_ataque(10),
	fase(fase_onde_esta)
{
	vidas = 90;

	buffer_som_morte.loadFromFile("src/som/Efeitos_Sonoros/jogador_morte.wav");
	som_morte.setBuffer(buffer_som_morte);
}


ChefaoFinal::~ChefaoFinal()
{
}

void ChefaoFinal::executar()
{
	if (vidas < 0 && !em_animacao_de_morte) {
		som_morte.play();
		morrer();
		imagem.setAnimacao(MORRENDO);
	}
	else {
		if (timer_de_ataque.getElapsedTime().asSeconds() > tempo_por_ataque) {
			timer_de_ataque.restart();
			atacando = true;
		}
		if (atacando && timer_de_ataque.getElapsedTime().asSeconds() > tempo_por_ataque / 10) {
			int r = rand() % 3;
			switch (r) {
			case 0:
				ataque1();
				break;
			case 1:
				ataque2();
				break;
			case 2:
				ataque3();
				break;
			}
			atacando = false;
		}

		if (atacando) {
			if (vidas > 60)
				imagem.setAnimacao(ATACANDO_VIDACHEIA, false);
			else if (vidas > 30)
				imagem.setAnimacao(ATACANDO_MEIAVIDA, false);
			else if (vidas > 0)
				imagem.setAnimacao(ATACANDO_VIDABAIXA, false);
		}
		else {
			if (vidas > 60)
				imagem.setAnimacao(NORMAL_VIDACHEIA, false);
			else if (vidas > 30)
				imagem.setAnimacao(NORMAL_MEIAVIDA, false);
			else if (vidas > 0)
				imagem.setAnimacao(NORMAL_VIDABAIXA, false);
		}
	}
}

void ChefaoFinal::ataque1()
{
	int x = 10700;
	for (int i = 0; i < 5; i++) {
		Soldado* s = new Soldado(Vector2i(x, 700 + CORRECAO_SOLDADO));
		s->estaParaDireita(false);
		fase->criarInimigo(s);
		x -= 100;
	}
}

void ChefaoFinal::ataque2()
{
	int x = 10600;
	for (int i = 0; i < 2; i++) {
		Tanque* t = new Tanque(Vector2i(x, 700 + CORRECAO_TANQUE));
		t->estaParaDireita(false);
		fase->criarInimigo(t);
		x -= 200;
	}
}

void ChefaoFinal::ataque3()
{
	int x = 10600;
	for (int i = 0; i < 2; i++) {
		Carro* c = new Carro(Vector2i(x, 700 + CORRECAO_CARRO));
		c->estaParaDireita(false);
		fase->criarInimigo(c);
		x -= 200;
	}
}
