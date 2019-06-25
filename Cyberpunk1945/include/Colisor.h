#pragma once

#include "Lista.h"
#include "ListaDeObstaculos.h"
#include "ListaDeInimigos.h"
#include "ListaDeMoedas.h"
#include "Jogador.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Moeda.h"

#define DIR_DIREITA 1
#define DIR_ESQUERDA 2
#define DIR_TOPO 4
#define DIR_BAIXO 8

using namespace std;
using namespace Personagens;
using namespace Inimigos;
using namespace Obstaculos;
using namespace Listagem;

class Colisor
{
private:
	ListaDeObstaculos listaObstaculos;
	ListaDeInimigos listaInimigos;
	ListaDeMoedas listaMoedas;

	Jogador* jogador1;
	Jogador* jogador2;
public:
	Colisor();
	~Colisor();

	void pushObstaculo(Obstaculo* obstaculo) { listaObstaculos.pushLista(obstaculo); };
	void popObstaculo(Obstaculo* obstaculo) { listaObstaculos.popLista(obstaculo); };

	void pushInimigo(Inimigo* inimigo) { listaInimigos.pushLista(inimigo); };
	void popInimigo(Inimigo* inimigo) { listaInimigos.popLista(inimigo); };

	void pushMoeda(Moeda* moeda) { listaMoedas.pushLista(moeda); };
	void popMoeda(Moeda* moeda) { listaMoedas.popLista(moeda); };

	Lista<Entidade> getListaCompleta();
	void setJogadores(Jogador* jogador1, Jogador* jogador2);

	void verificarColisoes();

	void colisaoJogadorObstaculos(Jogador* jogador);
	void colisaoJogadorInimigos(Jogador* jogador);
	void colisaoJogadorMoedas(Jogador* jogador);
	void colisaoInimigosObstaculos();

	static int colide(Personagens::Personagem* personagem, Entidade* objeto);
	static int colide(Personagens::Personagem* personagem, Personagens::Personagem* obj);

	static bool colisaoGenerica(Entidade* ent1, Entidade* ent2);
};

