#include "Imagem.h"

using namespace Visual;

Imagem::Imagem(Texture* nTextura, Vector2f tamanho,
				const vector<float>& tempo_por_frame, Vector2u LinhasxColunas,
				const vector<unsigned int>& frames_por_animacao,
				Vector2f dif_hitbox_e_sprite) :
	dT_por_frame(tempo_por_frame),
	frames_por_animacao(frames_por_animacao),
	em_animacao_de_morte(false)
{
	if (nTextura != NULL && frames_por_animacao.size() > 0)
	{
		textura = nTextura;
		N_ANIMACOES = LinhasxColunas.x;

		// Criando a matriz de sprites com os tamanhos e recortes da textura adequados
		sprites = new Sprite*[N_ANIMACOES];
		for (unsigned int i = 0; i < N_ANIMACOES; i++) {
			sprites[i] = new Sprite[this->frames_por_animacao.at(i)];
		}

		Vector2u clip_tamanho(textura->getSize().x / LinhasxColunas.y, textura->getSize().y / LinhasxColunas.x);
		IntRect clip(0, 0, clip_tamanho.x, clip_tamanho.y);

		razao = Vector2f(tamanho.x / clip_tamanho.x, tamanho.y / clip_tamanho.y);

		for (unsigned int linha = 0; linha < N_ANIMACOES; linha++) {
			for (unsigned int frame = 0; frame < this->frames_por_animacao.at(linha); frame++) {
				sprites[linha][frame].setTexture(*textura);
				sprites[linha][frame].setTextureRect(clip);
				sprites[linha][frame].setScale(razao);
				clip.left += clip_tamanho.x;
			}
			clip.left = 0;
			clip.top += clip_tamanho.y;
		}

		TIPO_DE_ANIMACAO = 0;
		frame_atual = 0;
		dT_acumulado = 0;
		diferenca_textura_e_hitbox = dif_hitbox_e_sprite;
		diferenca_textura_e_hitbox.x *= razao.x;
		diferenca_textura_e_hitbox.y *= razao.y;
	}
	else
		textura = NULL;
}

Imagem::~Imagem()
{
	
}

bool Imagem::vazio()
{
	if (textura == NULL)
		return true;
	return false;
}

bool Imagem::atualizarAnimacao(float dT)
{
	dT_acumulado += dT;
	if (dT_acumulado > dT_por_frame.at(TIPO_DE_ANIMACAO)) {
		dT_acumulado -= dT_por_frame.at(TIPO_DE_ANIMACAO);

		frame_atual++;

		// Roda a animação de morte só uma vez e retorna false APENAS quando acaba (retorna true em todas as outras ocasiões)
		if (frame_atual > frames_por_animacao.at(TIPO_DE_ANIMACAO) - 1) {
			frame_atual = 0;
			if (em_animacao_de_morte)
				return false;
		}
	}
	return true;
}

void Imagem::inverterSprite()
{
	sprites[TIPO_DE_ANIMACAO][frame_atual].setTextureRect(
		IntRect(
			sprites[TIPO_DE_ANIMACAO][frame_atual].getTextureRect().left + sprites[TIPO_DE_ANIMACAO][frame_atual].getTextureRect().width,
			sprites[TIPO_DE_ANIMACAO][frame_atual].getTextureRect().top,
			-sprites[TIPO_DE_ANIMACAO][frame_atual].getTextureRect().width,
			sprites[TIPO_DE_ANIMACAO][frame_atual].getTextureRect().height
		)
	);
	sprites[TIPO_DE_ANIMACAO][frame_atual].move(largura_hitbox + 2 * (diferenca_textura_e_hitbox.x - (sprites[TIPO_DE_ANIMACAO][frame_atual].getGlobalBounds().width / 2)), 0);
}

void Imagem::operator=(const Imagem& novaImagem)
{
	textura = novaImagem.textura;
	sprites = novaImagem.sprites;

	N_ANIMACOES = novaImagem.N_ANIMACOES;
	frames_por_animacao = novaImagem.frames_por_animacao;
	TIPO_DE_ANIMACAO = novaImagem.TIPO_DE_ANIMACAO;

	dT_por_frame = novaImagem.dT_por_frame;
	dT_acumulado = novaImagem.dT_acumulado;
	frame_atual = novaImagem.frame_atual;
	
	razao = novaImagem.razao;

	diferenca_textura_e_hitbox = novaImagem.diferenca_textura_e_hitbox;
}

bool Imagem::mouseDentro()
{
	Vector2i pos = GerenciadorGrafico::Instancia()->posicaoMouse();
	IntRect r(sprites[TIPO_DE_ANIMACAO][frame_atual].getGlobalBounds());

	if (pos.x > r.left && pos.x < (r.left + r.width) &&
		pos.y > r.top && pos.y < (r.top + r.height))
		return true;

	return false;
}