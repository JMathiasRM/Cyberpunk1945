#include "Entidade.h"

Entidade::Entidade(const char* endereco_textura, Vector2f tamanho, Vector2f posicao_inicial,
					const vector<float>& tempo_por_frame, Vector2u LinhasxColunas, const vector<unsigned int>& frames_por_animacao,
					Vector2u tamanho_hitbox, Vector2f dif_hitbox_e_sprite):
	imagem(GerenciadorGrafico::carregaTextura(endereco_textura), tamanho, tempo_por_frame, LinhasxColunas, frames_por_animacao, dif_hitbox_e_sprite),
	hitbox(Vector2f(tamanho_hitbox)),
	em_animacao_de_morte(false),
	morta(false),
	paraDireita(true)
{
	hitbox.setSize(Vector2f(hitbox.getSize().x * imagem.getRazao().x, hitbox.getSize().y * imagem.getRazao().y));
	hitbox.setPosition(posicao_inicial);
	imagem.setLarguraHitbox(hitbox.getSize().x);
}

Entidade::Entidade(Vector2f posicao, Vector2f tamanho):
	hitbox(Vector2f(tamanho)),
	em_animacao_de_morte(false),
	morta(false)
{
	hitbox.setPosition(posicao);
}

Entidade::~Entidade()
{
}

void Entidade::desenhar(float dT)
{
	if (!imagem.vazio() && !morta)
	{
		// Animações comuns
		if (imagem.atualizarAnimacao(dT)) {
			imagem.setPosicao(hitbox.getPosition());
			if (!paraDireita)
				imagem.inverterSprite();
			GerenciadorGrafico::Instancia()->desenhar(imagem.getSpriteAtual());
			if (!paraDireita)
				imagem.inverterSprite();
		}

		// Último frame da animação de morte foi desenhado
		else {
			morta = true;
		}
		desenharHitbox();

	}
}

void Entidade::desenharHitbox()
{

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(hitbox.getSize().x, hitbox.getSize().y));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(1);
	rectangle.setFillColor(Color(0, 0, 0, 0));
	rectangle.setPosition(hitbox.getPosition().x, hitbox.getPosition().y);
	GerenciadorGrafico::Instancia()->desenhar(rectangle);
}

Vector2f Entidade::distancia(Entidade* entidade)
{
	Vector2f posicaoObj1 = this->hitbox.getPosition();
	Vector2f tamanhoObj1 = this->hitbox.getSize();
	Vector2f posicaoObj2 = entidade->getPosicao();
	Vector2f tamanhoObj2 = entidade->getTamanho();

	float distHorizontal[4];
	float distVertical[4];

	distHorizontal[0] = posicaoObj2.x - posicaoObj1.x;
	distHorizontal[1] = posicaoObj2.x - (posicaoObj1.x + tamanhoObj1.x);
	distHorizontal[2] = (posicaoObj2.x + tamanhoObj2.x) - posicaoObj1.x;
	distHorizontal[3] = (posicaoObj2.x + tamanhoObj2.x) - (posicaoObj1.x + tamanhoObj1.x);
	distVertical[0] = posicaoObj2.y - posicaoObj1.y;
	distVertical[1] = posicaoObj2.y - (posicaoObj1.y + tamanhoObj1.y);
	distVertical[2] = (posicaoObj2.y + tamanhoObj2.y) - posicaoObj1.y;
	distVertical[3] = (posicaoObj2.y + tamanhoObj2.y) - (posicaoObj1.y + tamanhoObj1.y);


	float minDistHorizontal = distHorizontal[0];
	float minDistVertical = distVertical[0];

	for (int i = 1; i < 4; i++)
	{
		if (abs(distHorizontal[i]) < abs(minDistHorizontal))
			minDistHorizontal = distHorizontal[i];
		if (abs(distVertical[i]) < abs(minDistVertical))
			minDistVertical = distVertical[i];
	}

	return Vector2f(minDistHorizontal, minDistVertical);
}

void Entidade::morrer()
{
	imagem.setAnimacaoDeMorte(true);
	em_animacao_de_morte = true;
}
