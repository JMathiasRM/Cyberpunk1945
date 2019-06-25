#include "Fase2.h"

using namespace Fases;

Fase2::Fase2():
	Fase("src/imagens/fases/fase2_fundo.png", "src/imagens/fases/fase2_plataformas.png", Vector2u(11300, 1000)),
	chefao(this, "src/imagens/personagens/chefao.png", Vector2f(400, 400), Vector2f(10400, 330), vector<float>{0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1},
		Vector2u(7, 2), vector<unsigned int>{2,2,2,2,2,2,2}, Vector2u(68,118), Vector2f(36,6))
{
	carregarObstaculos();
	carregarInimigos();
	carregarMoedas();

	inserirEntidades();

	musica_fase.openFromFile("src/som/Musica/fase2.wav");
	musica_fase.setLoop(true);
	musica_fase.setVolume(50);
	
	musica_boss.openFromFile("src/som/Musica/boss.wav");
	musica_boss.setLoop(true);
	musica_boss.setVolume(50);
}

Fase2::~Fase2()
{
}

void Fase2::carregarObstaculos()
{
	colisor.pushObstaculo(new Plataforma(Vector2f(-10, 0), Vector2f(10, 1000)));
	colisor.pushObstaculo(new Plataforma(Vector2f(0, 0), Vector2f(11300, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(0, 150), Vector2f(450, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(450, 150), Vector2f(475, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(450, 180), Vector2f(50, 420)));
	colisor.pushObstaculo(new Plataforma(Vector2f(0, 750), Vector2f(850, 250)));
	colisor.pushObstaculo(new Plataforma(Vector2f(650, 600), Vector2f(400, 150)));
	colisor.pushObstaculo(new Plataforma(Vector2f(850, 400), Vector2f(200, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1050, 250), Vector2f(800, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1250, 500), Vector2f(50, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(850, 950), Vector2f(800, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1300, 800), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1750, 950), Vector2f(500, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1550, 600), Vector2f(200, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1850, 650), Vector2f(150, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(2015, 800), Vector2f(100, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(2200, 550), Vector2f(600, 450)));
	colisor.pushObstaculo(new Plataforma(Vector2f(2800, 600), Vector2f(200, 400)));
	colisor.pushObstaculo(new Plataforma(Vector2f(3000, 550), Vector2f(700, 450)));
	colisor.pushObstaculo(new Plataforma(Vector2f(2800, 350), Vector2f(200, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(3150, 350), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(3550, 350), Vector2f(150, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(3800, 450), Vector2f(100, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4050, 450), Vector2f(400, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4050, 500), Vector2f(100, 500)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4150, 750), Vector2f(900, 250)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4450, 300), Vector2f(200, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4650, 450), Vector2f(400, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(5050, 650), Vector2f(100, 350)));
	colisor.pushObstaculo(new Plataforma(Vector2f(5150, 500), Vector2f(550, 500)));
	colisor.pushObstaculo(new Plataforma(Vector2f(5800, 500), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(6100, 350), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(6400, 500), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(6750, 700), Vector2f(875, 300)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7625, 700), Vector2f(875, 300)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7200, 500), Vector2f(150, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7350, 470), Vector2f(150, 60)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7500, 440), Vector2f(400, 90)));
	colisor.pushObstaculo(new Plataforma(Vector2f(8600, 700), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(8900, 700), Vector2f(1900, 300)));
	colisor.pushObstaculo(new Plataforma(Vector2f(9000, 50), Vector2f(800, 550)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10800, 50), Vector2f(500, 950)));

	borda1 = new Plataforma(Vector2f(-1, 0), Vector2f(1, 1000));
	borda2 = new Plataforma(Vector2f(1067, 0), Vector2f(1, 1000));

	colisor.pushObstaculo(borda1);
	colisor.pushObstaculo(borda2);

	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(400, 150)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(900, 950)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(1900, 950)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(1700, 250)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(2400, 550)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(4700, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(2800, 600)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(2900, 600)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(3275, 350)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(4150, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(4500, 300)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(5300, 500)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(5500, 500)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(7350, 470)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(7680, 440)));
}

void Fase2::carregarInimigos()
{
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(190, 150)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(640, 150)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(700, 600)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(1100, 250)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(1125, 950)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(1400, 950)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(3070, 550)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(3450, 550)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(4500, 750)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(4700, 450)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(5810, 500)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(6110, 350)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(6410, 500)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(7000, 700)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(8000, 700)));
}

void Fase2::carregarMoedas()
{
	colisor.pushMoeda(new Moeda(Vector2f(450, 750)));
	colisor.pushMoeda(new Moeda(Vector2f(650, 600)));
	colisor.pushMoeda(new Moeda(Vector2f(0, 150)));
	colisor.pushMoeda(new Moeda(Vector2f(100, 150)));
	colisor.pushMoeda(new Moeda(Vector2f(975, 400)));
	colisor.pushMoeda(new Moeda(Vector2f(1250, 500)));
	colisor.pushMoeda(new Moeda(Vector2f(1400, 800)));
	colisor.pushMoeda(new Moeda(Vector2f(1500, 800)));
	colisor.pushMoeda(new Moeda(Vector2f(2150, 950)));
	colisor.pushMoeda(new Moeda(Vector2f(2200, 550)));
	colisor.pushMoeda(new Moeda(Vector2f(2875, 350)));
	colisor.pushMoeda(new Moeda(Vector2f(3825, 450)));
	colisor.pushMoeda(new Moeda(Vector2f(5075, 650)));
	colisor.pushMoeda(new Moeda(Vector2f(6800, 700)));
	colisor.pushMoeda(new Moeda(Vector2f(7250, 500)));
	colisor.pushMoeda(new Moeda(Vector2f(7600, 440)));
	colisor.pushMoeda(new Moeda(Vector2f(8200, 700)));
	colisor.pushMoeda(new Moeda(Vector2f(8300, 700)));
	colisor.pushMoeda(new Moeda(Vector2f(8400, 700)));
}

void Fase2::verificarVitoria()
{
	if (jogador1->estaViva()) {
		if (jogador2 && jogador2->estaViva()) {
			if ((jogador1->getPosicao().x > 9800) && (jogador2->getPosicao().x > 9800)) {
				lutaFinal();
				rodando = false;
			}
		}
		else if (jogador1->getPosicao().x > 9800) {
			lutaFinal();
			rodando = false;
		}
	}
	else if (jogador2 && jogador2->estaViva()) {
		if (jogador2->getPosicao().x > 9800) {
			lutaFinal();
			rodando = false;
		}
	}
	else {
		Texto derrota("navycadetexpand.ttf", 72, Color::Red);
		derrota.setTexto("Voce perdeu!");
		derrota.setPosicao(Vector2f(camera.getCenter().x - (derrota.getTextoParaDesenho().getGlobalBounds().width / 2), camera.getCenter().y));
		GerenciadorGrafico::Instancia()->getJanela()->draw(derrota.getTextoParaDesenho());
		rodando = false;
		ganhou = false;
	}
}

void Fases::Fase2::verificarVitoriaChefao()
{
	if (!chefao.estaViva()) {
		Texto vitoria("navycadetexpand.ttf", 72, Color::Red);
		vitoria.setTexto("Voce ganhou!");
		vitoria.setPosicao(Vector2f(camera.getCenter().x - (vitoria.getTextoParaDesenho().getGlobalBounds().width / 2), 400));
		GerenciadorGrafico::Instancia()->desenhar(vitoria.getTextoParaDesenho());
		rodando = false;
		ganhou = true;
	}
	else if (!jogador1->estaViva()) {
		if ((jogador2 && !jogador2->estaViva()) || !jogador2) {
			Texto derrota("navycadetexpand.ttf", 72, Color::Red);
			derrota.setTexto("Voce perdeu!");
			derrota.setPosicao(Vector2f(camera.getCenter().x - (derrota.getTextoParaDesenho().getGlobalBounds().width / 2), 400));
			GerenciadorGrafico::Instancia()->desenhar(derrota.getTextoParaDesenho());
			rodando = false;
			ganhou = false;
		}
	}
}

void Fase2::executar()
{
	Event e;

	GerenciadorGrafico::Instancia()->getJanela()->setView(camera);

	musica_fase.play();

	rodando = true;
	while (rodando)
	{
		// Importante que sejam a PRIMEIRA coisa a ser feita quando começar o loop
		dT_frames = timer_frames.restart().asSeconds();

		// Calcular velocidades
		listaEntidades.executar();

		// Eventos
		checarEventos(e);
		pausa();

		// Colidir entidades
		colisor.verificarColisoes();

		// Mover entidades
		listaEntidades.moverEntidades();

		ajustarCamera();

		// Desenhar entidades
		GerenciadorGrafico::Instancia()->limparJanela();
		desenharFundo();
		listaEntidades.desenharEntidades(dT_frames);
		desenharVidaPersonagens();

		verificarVitoria();

		// Importante que sejam a ÚLTIMA coisa a ser feita antes de terminar o loop
		GerenciadorGrafico::Instancia()->atualizarJanela();

	}

	sleep(seconds(5));

	musica_fase.stop();
}

void Fase2::lutaFinal()
{
	Event e;

	// Parede invisível que prende os jogadores na sala
	Plataforma* parede = new Plataforma(Vector2f(9760, 600), Vector2f(40, 100));
	colisor.pushObstaculo(parede);
	listaEntidades.pushEntidade(parede);

	// Fixa a câmera
	camera.setCenter(10300, 445);

	// Prende as bordas invisíveis, já que não serão mais usadas
	borda1->setPosicao(Vector2f(camera.getCenter().x - (camera.getSize().x / 2), 0));
	borda2->setPosicao(Vector2f(camera.getCenter().x + (camera.getSize().x / 2), 0));

	// Boss é carregado na fase
	colisor.pushInimigo(&chefao);
	listaEntidades.pushEntidade(&chefao);

	musica_fase.stop();
	musica_boss.play();

	rodando = true;
	while (rodando)
	{
		// Importante que sejam a PRIMEIRA coisa a ser feita quando começar o loop
		dT_frames = timer_frames.restart().asSeconds();
		
		// Calcular velocidades
		listaEntidades.executar();

		// Eventos
		checarEventos(e);
		pausa();

		// Colidir entidades
		colisor.verificarColisoes();

		// Mover entidades
		listaEntidades.moverEntidades();

		// Desenhar entidades
		GerenciadorGrafico::Instancia()->limparJanela();
		GerenciadorGrafico::Instancia()->getJanela()->setView(camera);
		desenharFundo();
		listaEntidades.desenharEntidades(dT_frames);
		desenharVidaPersonagens();

		verificarVitoriaChefao();

		// Importante que sejam a ÚLTIMA coisa a ser feita antes de terminar o loop
		GerenciadorGrafico::Instancia()->atualizarJanela();
	}

	musica_boss.stop();
}