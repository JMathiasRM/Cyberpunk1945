#include "Colisor.h"

using namespace std;
using namespace Visual;
using namespace Obstaculos;

Colisor::Colisor()
{
}

Colisor::~Colisor()
{
}

Lista<Entidade> Colisor::getListaCompleta()
{
	Lista<Entidade> l;

	if (!listaObstaculos.vazia()) {
		listaObstaculos.zerarIterador();
		do {
			l.pushLista(listaObstaculos.getObjeto());
		} while (listaObstaculos.moverIterador());
	}

	if (!listaInimigos.vazia()) {
		listaInimigos.zerarIterador();
		do {
			l.pushLista(listaInimigos.getObjeto());
		} while (listaInimigos.moverIterador());
	}

	if (!listaMoedas.vazia()) {
		listaMoedas.zerarIterador();
		do {
			l.pushLista(listaMoedas.getObjeto());
		} while (listaMoedas.moverIterador());
	}

	return l;
}

void Colisor::setJogadores(Jogador* jogador1, Jogador* jogador2)
{
	this->jogador1 = jogador1;
	this->jogador2 = jogador2;
}

void Colisor::verificarColisoes()
{
	bool sem_obstaculos = listaObstaculos.vazia();
	bool sem_inimigos = listaInimigos.vazia();
	bool sem_moedas = listaMoedas.vazia();

	// Jogador 1
	if (jogador1->estaViva()) {
		if(!sem_obstaculos)
			colisaoJogadorObstaculos(jogador1);
		if (!sem_inimigos)
			colisaoJogadorInimigos(jogador1);
		if (!sem_moedas)
			colisaoJogadorMoedas(jogador1);
	}

	// Jogador 2
	if (jogador2 && jogador2->estaViva()) {
		if (!sem_obstaculos)
			colisaoJogadorObstaculos(jogador2);
		if (!sem_inimigos)
			colisaoJogadorInimigos(jogador2);
		if (!sem_moedas)
			colisaoJogadorMoedas(jogador2);
	}

	if (!sem_obstaculos && !sem_inimigos) {
		colisaoInimigosObstaculos();
	}

}

void Colisor::colisaoJogadorObstaculos(Jogador* jogador)
{
	listaObstaculos.zerarIterador();
	do {
		if (listaObstaculos.getObjeto()->estaMorrendo())
			continue;

		int direcao = colide(jogador, listaObstaculos.getObjeto());
		Vector2f distancia = jogador->distancia(listaObstaculos.getObjeto());
		if (direcao == DIR_TOPO)
		{
			jogador->setVelocY(distancia.y);
			jogador->resetarPulos();
			if (jogador->emKnockback()) {
				jogador->setKnockback(false);
				jogador->setVelocX(0);
			}
			listaObstaculos.getObjeto()->colisaoEspecial(jogador, direcao);

		}
		if (direcao == DIR_ESQUERDA || direcao == DIR_DIREITA)
		{
			jogador->setVelocX(distancia.x);
			listaObstaculos.getObjeto()->colisaoEspecial(jogador, direcao);
		}
		if (direcao == DIR_BAIXO)
		{
			jogador->setVelocY(distancia.y);
			jogador->resetarTimer();
			listaObstaculos.getObjeto()->colisaoEspecial(jogador, direcao);

		}

		jogador1->colidirProjeteis(listaObstaculos.getObjeto());

	} while (listaObstaculos.moverIterador());
}

void Colisor::colisaoJogadorInimigos(Jogador* jogador)
{
	listaInimigos.zerarIterador();
	do {
		if (listaInimigos.getObjeto()->estaMorrendo())
			continue;

		int direcao = colide(jogador, listaInimigos.getObjeto());
		Vector2f distancia = jogador->distancia(listaInimigos.getObjeto());

		jogador->ataque(listaInimigos.getObjeto());
		listaInimigos.getObjeto()->ataque(jogador);

		if (direcao == DIR_TOPO)
		{
			jogador->resetarPulos();
			jogador->pular(ALTURA_DE_PULO * 0.5);
			listaInimigos.getObjeto()->dano();
		}
		if (direcao == DIR_DIREITA || direcao == DIR_ESQUERDA)
		{
			listaInimigos.getObjeto()->colisaoEspecial(jogador, direcao);
		}
	} while (listaInimigos.moverIterador());
}

void Colisor::colisaoJogadorMoedas(Jogador* jogador)
{
	listaMoedas.zerarIterador();
	do {
		if (!listaMoedas.getObjeto()->jaFoiColetada() && colisaoGenerica(jogador, listaMoedas.getObjeto())) {
			jogador->aumentarPontuacao();
			listaMoedas.getObjeto()->morrer();
			listaMoedas.getObjeto()->foiColetada(true);
		}
	} while (listaMoedas.moverIterador());
}

void Colisor::colisaoInimigosObstaculos()
{
	listaObstaculos.zerarIterador();
	listaInimigos.zerarIterador();

	do {
		//Verifica a colisão de cada inimigo com cada objeto
		Inimigo* inimigo_atual = listaInimigos.getObjeto();
		do {
			int direcao = colide(inimigo_atual, listaObstaculos.getObjeto());
			Vector2f distancia = inimigo_atual->distancia(listaObstaculos.getObjeto());

			if (direcao == DIR_TOPO)
			{
				inimigo_atual->setVelocY(distancia.y);
				if (abs(distancia.x) < 5)
					inimigo_atual->setVelocX(-inimigo_atual->getVeloc().x);
			}
			if (direcao == DIR_ESQUERDA || direcao == DIR_DIREITA)
			{
				inimigo_atual->setVelocX(-inimigo_atual->getVeloc().x);
			}

			inimigo_atual->colidirProjeteis(listaObstaculos.getObjeto());

		} while (listaObstaculos.moverIterador());
	} while (listaInimigos.moverIterador());
}

//Retorna a direção de colisão com um objeto
int Colisor::colide(Personagens::Personagem* personagem, Entidade* objeto)
{
	Vector2f posicaoPersonagem = personagem->getPosicao();
	Vector2f tamanhoPersonagem = personagem->getTamanho();
	Vector2f velocidadePersonagem = personagem->getVeloc();

	Vector2f posicaoObjeto = objeto->getPosicao();
	Vector2f tamanhoObjeto = objeto->getTamanho();

	//Verifica se o personagem está em cima de um obstáculo e se no próximo movimento ele entra
	if ((posicaoPersonagem.y + tamanhoPersonagem.y <= posicaoObjeto.y) &&
		(posicaoPersonagem.x + velocidadePersonagem.x < posicaoObjeto.x + tamanhoObjeto.x && posicaoPersonagem.x + tamanhoPersonagem.x + velocidadePersonagem.x  > posicaoObjeto.x &&
			posicaoPersonagem.y + tamanhoPersonagem.y + velocidadePersonagem.y > posicaoObjeto.y))
		return DIR_TOPO;
	//Verifica se o personagem está em baixo de um obstáculo e se no próximo frame ele entra
	if ((posicaoPersonagem.y >= posicaoObjeto.y + tamanhoObjeto.y) &&
		(posicaoPersonagem.x + velocidadePersonagem.x < posicaoObjeto.x + tamanhoObjeto.x && posicaoPersonagem.x + tamanhoPersonagem.x + velocidadePersonagem.x  > posicaoObjeto.x &&
			posicaoPersonagem.y + velocidadePersonagem.y < posicaoObjeto.y + tamanhoObjeto.y))
		return DIR_BAIXO;
	if ((posicaoPersonagem.x + tamanhoPersonagem.x <= posicaoObjeto.x) &&
		(posicaoPersonagem.y + velocidadePersonagem.y < posicaoObjeto.y + tamanhoObjeto.y && posicaoPersonagem.y + tamanhoPersonagem.y + velocidadePersonagem.y > posicaoObjeto.y &&
			posicaoPersonagem.x + tamanhoPersonagem.x + velocidadePersonagem.x > posicaoObjeto.x))
		return DIR_ESQUERDA;
	if ((posicaoPersonagem.x >= posicaoObjeto.x + tamanhoObjeto.x) &&
		(posicaoPersonagem.y + velocidadePersonagem.y < posicaoObjeto.y + tamanhoObjeto.y && posicaoPersonagem.y + tamanhoPersonagem.y + velocidadePersonagem.y > posicaoObjeto.y &&
			posicaoPersonagem.x + velocidadePersonagem.x < posicaoObjeto.x + tamanhoObjeto.x))
		return DIR_DIREITA;
	return 0;
}

//Retorna a direção de colisão com um personagem
int Colisor::colide(Personagens::Personagem* personagem, Personagens::Personagem* objeto)
{
	Vector2f posicaoPersonagem = personagem->getPosicao();
	Vector2f tamanhoPersonagem = personagem->getTamanho();
	Vector2f velocidadePersonagem = personagem->getVeloc();

	Vector2f posicaoObjeto = objeto->getPosicao() + objeto->getVeloc();
	Vector2f tamanhoObjeto = objeto->getTamanho() + objeto->getVeloc();
	Vector2f velocidadeObjeto = objeto->getVeloc();

	//Verifica se o personagem está em cima de um obstáculo e se no próximo movimento ele entra
	if ((posicaoPersonagem.y + tamanhoPersonagem.y <= posicaoObjeto.y - velocidadeObjeto.y) &&
		(posicaoPersonagem.x + velocidadePersonagem.x < posicaoObjeto.x + tamanhoObjeto.x && posicaoPersonagem.x + tamanhoPersonagem.x + velocidadePersonagem.x  > posicaoObjeto.x &&
			posicaoPersonagem.y + tamanhoPersonagem.y + velocidadePersonagem.y > posicaoObjeto.y))
		return DIR_TOPO;
	//Verifica se o personagem está em baixo de um obstáculo e se no próximo frame ele entra
	if ((posicaoPersonagem.y >= posicaoObjeto.y + tamanhoObjeto.y - velocidadeObjeto.y) &&
		(posicaoPersonagem.x + velocidadePersonagem.x < posicaoObjeto.x + tamanhoObjeto.x && posicaoPersonagem.x + tamanhoPersonagem.x + velocidadePersonagem.x  > posicaoObjeto.x &&
			posicaoPersonagem.y + velocidadePersonagem.y < posicaoObjeto.y + tamanhoObjeto.y))
		return DIR_BAIXO;
	//etc
	if ((posicaoPersonagem.x + tamanhoPersonagem.x <= posicaoObjeto.x - velocidadeObjeto.x) &&
		(posicaoPersonagem.y + velocidadePersonagem.y < posicaoObjeto.y + tamanhoObjeto.y && posicaoPersonagem.y + tamanhoPersonagem.y + velocidadePersonagem.y > posicaoObjeto.y &&
			posicaoPersonagem.x + tamanhoPersonagem.x + velocidadePersonagem.x > posicaoObjeto.x))
		return DIR_ESQUERDA;
	if ((posicaoPersonagem.x >= posicaoObjeto.x + tamanhoObjeto.x - velocidadeObjeto.x) &&
		(posicaoPersonagem.y + velocidadePersonagem.y < posicaoObjeto.y + tamanhoObjeto.y && posicaoPersonagem.y + tamanhoPersonagem.y + velocidadePersonagem.y > posicaoObjeto.y &&
			posicaoPersonagem.x + velocidadePersonagem.x < posicaoObjeto.x + tamanhoObjeto.x))
		return DIR_DIREITA;
	return 0;
}

bool Colisor::colisaoGenerica(Entidade* ent1, Entidade* ent2)
{
	Vector2f pos1 = ent1->getPosicao();
	Vector2f tam1 = ent1->getTamanho();
	Vector2f pos2 = ent2->getPosicao();
	Vector2f tam2 = ent2->getTamanho();

	if (pos1.x < pos2.x + tam2.x && pos1.y < pos2.y + tam2.y &&
		pos1.x + tam1.x > pos2.x && pos1.y + tam1.y > pos2.y)
		return true;
	return false;
}