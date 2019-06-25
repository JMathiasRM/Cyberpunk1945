#include "Fase1.h"

using namespace Fases;

Fase1::Fase1() :
	Fase("src/imagens/fases/fase1_fundo.png", "src/imagens/fases/fase1_plataformas.png", Vector2u(12500, 1000))
{
	carregarObstaculos();
	carregarInimigos();
	carregarMoedas();

	inserirEntidades();

	musica_fase.openFromFile("src/som/Musica/fase1.wav");
	musica_fase.setLoop(true);
	musica_fase.setVolume(50);
}


Fase1::~Fase1()
{
}

void Fase1::carregarObstaculos()
{
	colisor.pushObstaculo(new Plataforma(Vector2f(-100, 0), Vector2f(1000, 100)));
	colisor.pushObstaculo(new Plataforma(Vector2f(-12500, 0), Vector2f(10, 1000)));
	colisor.pushObstaculo(new Plataforma(Vector2f(12500, 0), Vector2f(1000, 100)));
	//Chão 1
	colisor.pushObstaculo(new Plataforma(Vector2f(0, 750), Vector2f(1615, 750)));

	//Obstaculos de tutorial
	colisor.pushObstaculo(new Mina(Vector2f(600, 750 + CORRECAO_MINA)));
	colisor.pushObstaculo(new Armadilha(Vector2f(750, 750 + CORRECAO_ARMADILHA)));
	colisor.pushObstaculo(new Arame(Vector2f(1000, 750 + CORRECAO_ARAME)));

	colisor.pushObstaculo(new Plataforma(Vector2f(1215, 675), Vector2f(100, 75)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1315, 600), Vector2f(100, 150)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1415, 525), Vector2f(100, 225)));
	colisor.pushObstaculo(new Plataforma(Vector2f(1515, 450), Vector2f(100, 300)));


	colisor.pushObstaculo(new Plataforma(Vector2f(1765, 600), Vector2f(100, 50)));

	// Chão 2
	colisor.pushObstaculo(new Plataforma(Vector2f(2015, 750), Vector2f(1685, 750)));
	colisor.pushObstaculo(new Plataforma(Vector2f(2015, 700), Vector2f(100, 50)));

	colisor.pushObstaculo(new Plataforma(Vector2f(2450, 700), Vector2f(100, 50)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(2570, 750)));

	colisor.pushObstaculo(new Plataforma(Vector2f(2760, 630), Vector2f(200, 50)));

	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(3075, 530)));
	colisor.pushObstaculo(new Plataforma(Vector2f(3000, 530), Vector2f(200, 50)));

	colisor.pushObstaculo(new Plataforma(Vector2f(3300, 530), Vector2f(300, 50)));

	// Chão 3
	colisor.pushObstaculo(new Plataforma(Vector2f(3850, 750), Vector2f(550, 750)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4000, 550), Vector2f(220, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4300, 650), Vector2f(100, 100)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(4200, 750)));

	// Chão 4
	colisor.pushObstaculo(new Plataforma(Vector2f(4500, 500), Vector2f(300, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(4800, 500), Vector2f(300, 50)));

	colisor.pushObstaculo(new Plataforma(Vector2f(5200, 500), Vector2f(400, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(5400, 200), Vector2f(100, 300)));
	colisor.pushObstaculo(new Plataforma(Vector2f(5300, 340), Vector2f(100, 10)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(5300, 500)));

	colisor.pushObstaculo(new Plataforma(Vector2f(5700, 430), Vector2f(50, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(5850, 340), Vector2f(300, 10)));
	colisor.pushObstaculo(new Plataforma(Vector2f(6240, 500), Vector2f(60, 50)));
	colisor.pushObstaculo(new Plataforma(Vector2f(6375, 700), Vector2f(60, 50)));

	// Chão 5
	colisor.pushObstaculo(new Plataforma(Vector2f(6550, 750), Vector2f(2000, 750)));

	colisor.pushObstaculo(new Plataforma(Vector2f(6850, 600), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7150, 525), Vector2f(300, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7450, 450), Vector2f(300, 30)));

	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(7250, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(7400, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(7550, 750)));

	colisor.pushObstaculo(new Plataforma(Vector2f(7750, 450), Vector2f(100, 150)));
	colisor.pushObstaculo(new Plataforma(Vector2f(7850, 525), Vector2f(100, 75)));

	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(7850, 525)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(8150, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(8360, 750)));

	colisor.pushObstaculo(new Plataforma(Vector2f(8600, 800), Vector2f(100, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(8800, 900), Vector2f(200, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(9125, 900), Vector2f(125, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(9350, 930), Vector2f(200, 30)));

	// Chão 6
	colisor.pushObstaculo(new Plataforma(Vector2f(9600, 850), Vector2f(50, 150)));
	colisor.pushObstaculo(new Plataforma(Vector2f(9650, 750), Vector2f(1575, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(9725, 750)));

	colisor.pushObstaculo(new Plataforma(Vector2f(9900, 675), Vector2f(100, 75)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10000, 600), Vector2f(100, 150)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10100, 525), Vector2f(100, 225)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10200, 450), Vector2f(100, 300)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10300, 375), Vector2f(100, 375)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10400, 300), Vector2f(100, 450)));

	colisor.pushObstaculo(new Plataforma(Vector2f(10650, 450), Vector2f(100, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(10900, 500), Vector2f(100, 30)));
	colisor.pushObstaculo(new Plataforma(Vector2f(11000, 325), Vector2f(100, 30)));

	colisor.pushObstaculo(new Plataforma(Vector2f(11225, 300), Vector2f(100, 350)));

	colisor.pushObstaculo(new Plataforma(Vector2f(11225, 750), Vector2f(300, 750)));
	colisor.pushObstaculo(new Plataforma(Vector2f(11525, 750), Vector2f(975, 750)));
	colisor.pushObstaculo(Obstaculo::obstaculoAleatorio(Vector2f(11825, 750)));

	colisor.pushObstaculo(new Plataforma(Vector2f(11525, 450), Vector2f(100, 200)));

	borda1 = new Plataforma(Vector2f(-1, 0), Vector2f(1, 1000));
	borda2 = new Plataforma(Vector2f(1067, 0), Vector2f(1, 1000));

	colisor.pushObstaculo(borda1);
	colisor.pushObstaculo(borda2);

}

void Fase1::carregarInimigos()
{
	colisor.pushInimigo(new Soldado(Vector2i(2030, 700 + CORRECAO_SOLDADO)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(2150, 750)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(3310, 530)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(3070, 750)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(3400, 750)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(3900, 750)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(4510, 500)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(4810, 500)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(5860, 340)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(6860, 600)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(7160, 525)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(7460, 450)));

	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(10525, 750)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(10900, 750)));
	colisor.pushInimigo(Inimigo::inimigoAleatorio(Vector2f(11330, 750)));
}

void Fase1::carregarMoedas()
{
	colisor.pushMoeda(new Moeda(Vector2f(1215, 675)));
	colisor.pushMoeda(new Moeda(Vector2f(1315, 600)));
	colisor.pushMoeda(new Moeda(Vector2f(1415, 525)));
	colisor.pushMoeda(new Moeda(Vector2f(1515, 450)));

	colisor.pushMoeda(new Moeda(Vector2f(2470, 700)));

	colisor.pushMoeda(new Moeda(Vector2f(4085, 550)));

	colisor.pushMoeda(new Moeda(Vector2f(5325, 340)));
	colisor.pushMoeda(new Moeda(Vector2f(5520, 500)));
	colisor.pushMoeda(new Moeda(Vector2f(5700, 430)));

	colisor.pushMoeda(new Moeda(Vector2f(6245, 525)));
	colisor.pushMoeda(new Moeda(Vector2f(6370, 700)));

	colisor.pushMoeda(new Moeda(Vector2f(7725, 450)));
	colisor.pushMoeda(new Moeda(Vector2f(7725, 750)));

	colisor.pushMoeda(new Moeda(Vector2f(8625, 800)));
	colisor.pushMoeda(new Moeda(Vector2f(8825, 900)));
	colisor.pushMoeda(new Moeda(Vector2f(8925, 900)));
	colisor.pushMoeda(new Moeda(Vector2f(9600, 850)));

	colisor.pushMoeda(new Moeda(Vector2f(9925, 675)));
	colisor.pushMoeda(new Moeda(Vector2f(10025, 600)));
	colisor.pushMoeda(new Moeda(Vector2f(10125, 525)));
	colisor.pushMoeda(new Moeda(Vector2f(10225, 450)));
	colisor.pushMoeda(new Moeda(Vector2f(10325, 375)));
	colisor.pushMoeda(new Moeda(Vector2f(10425, 300)));

}

void Fase1::verificarVitoria()
{
	if (jogador1->estaViva()) {
		if (jogador2 && jogador2->estaViva()) {
			if ((jogador1->getPosicao().x > 12300) && (jogador2->getPosicao().x > 12300)) {
				Texto vitoria("navycadetexpand.ttf", 72, Color::Red);
				vitoria.setTexto("Fase completa!");
				vitoria.setPosicao(Vector2f(camera.getCenter().x - (vitoria.getTextoParaDesenho().getGlobalBounds().width / 2), camera.getCenter().y));
				GerenciadorGrafico::Instancia()->getJanela()->draw(vitoria.getTextoParaDesenho());
				rodando = false;
				ganhou = true;
			}
		}
		else if (jogador1->getPosicao().x > 12300) {
			Texto vitoria("navycadetexpand.ttf", 72, Color::Red);
			vitoria.setTexto("Fase completa!");
			vitoria.setPosicao(Vector2f(camera.getCenter().x - (vitoria.getTextoParaDesenho().getGlobalBounds().width / 2), camera.getCenter().y));
			GerenciadorGrafico::Instancia()->getJanela()->draw(vitoria.getTextoParaDesenho());
			rodando = false;
			ganhou = true;
		}
	}
	else if (jogador2 && jogador2->estaViva()) {
		if (jogador2->getPosicao().x > 12300) {
			Texto vitoria("navycadetexpand.ttf", 72, Color::Red);
			vitoria.setTexto("Fase completa!");
			vitoria.setPosicao(Vector2f(camera.getCenter().x - (vitoria.getTextoParaDesenho().getGlobalBounds().width / 2), camera.getCenter().y));
			GerenciadorGrafico::Instancia()->getJanela()->draw(vitoria.getTextoParaDesenho());
			rodando = false;
			ganhou = true;
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

void Fase1::executar()
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
