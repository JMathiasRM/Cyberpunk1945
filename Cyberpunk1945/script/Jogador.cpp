#include "Jogador.h"

#include <sstream>

using namespace Personagens;

Jogador::Jogador(int qual_jogador, const char* endereco_textura, Vector2f tamanho, Vector2f posicao_inicial,
				const vector<float>& tempo_por_frame, Vector2u LinhasxColunas, const vector<unsigned int>& frames_por_animacao,
				Vector2u tamanho_hitbox, Vector2f dif_hitbox_e_sprite):
				Entidade(endereco_textura, tamanho, posicao_inicial, tempo_por_frame, LinhasxColunas, frames_por_animacao,
				tamanho_hitbox, dif_hitbox_e_sprite),
				id_jogador(qual_jogador),
				pontos(0),
				texto_pontuacao("navycadetexpand.ttf", 36, Color::Blue),
				knockback(false)
{
	switch (qual_jogador) {
	case 1:
		vida_imagem = Imagem(GerenciadorGrafico::carregaTextura("src/imagens/personagens/jogador1_vida.png"), { 1066,600 }, vector<float>{0, 0, 0, 0, 0, 0},
			Vector2u(6, 1), vector<unsigned int>{1, 1, 1, 1, 1, 1});
		break;
	case 2:
		vida_imagem = Imagem(GerenciadorGrafico::carregaTextura("src/imagens/personagens/jogador2_vida.png"), { 1066,600 }, vector<float>{0, 0, 0, 0, 0, 0},
			Vector2u(6, 1), vector<unsigned int>{1, 1, 1, 1, 1, 1});
		break;
	}

	vidas = 5;

	buffer_som_morte.loadFromFile("src/som/Efeitos_Sonoros/jogador_morte.wav");
	som_morte.setBuffer(buffer_som_morte);

	buffer_som_atirando.loadFromFile("src/som/Efeitos_Sonoros/jogador_atirando.wav");
	som_atirando.setBuffer(buffer_som_atirando);
}

Jogador::~Jogador()
{
}

void Personagens::Jogador::executar()
{
	velocidade.y += GRAVIDADE;

	if (((hitbox.getPosition().y > 1100) || (vidas <= 0)) && !em_animacao_de_morte) {
		imagem.setAnimacao(MORTE);
		som_morte.play();
		morrer();
	}
	
	moverBalas();
}

void Personagens::Jogador::cair()
{
	relogio_da_queda.restart();
	velocidade.y = 0;
}

void Personagens::Jogador::restaurar()
{
	knockback = false;
	vidas = 5;
	hitbox.setPosition(Vector2f(200, 640));
	imagem.setAnimacaoDeMorte(false);
	em_animacao_de_morte = false;
	morta = false;
	paraDireita = true;
}

void Personagens::Jogador::desenharVida()
{
	std::stringstream conversor_int_em_string;
	conversor_int_em_string << pontos;
	texto_pontuacao.setTexto(conversor_int_em_string.str());
	GerenciadorGrafico::Instancia()->desenhar(texto_pontuacao.getTextoParaDesenho());
	vida_imagem.setAnimacao(5 - vidas);
	GerenciadorGrafico::Instancia()->desenhar(vida_imagem.getSpriteAtual());
}

void Personagens::Jogador::atirar()
{
	som_atirando.play();
	Atirador::atirar(Vector2f(hitbox.getPosition().x + hitbox.getSize().x, hitbox.getPosition().y + hitbox.getSize().y / 2), paraDireita ? 1 : -1);
}

void Personagens::Jogador::dano()
{
	if (!knockback)
	{
		vidas--;
		if (vidas < 0)
			vidas = 0;
		pular(ALTURA_DE_PULO * 0.3);
		knockback = true;
	}
}
