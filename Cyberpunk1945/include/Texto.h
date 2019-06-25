#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

namespace Visual
{
	class Texto
	{
	private:
		Text texto;
		Font fonte;
	public:
		Texto();
		Texto(String caminho_da_fonte, unsigned int tamanho_da_fonte = 0, Color cor = Color::White);
		~Texto();

		/// Muda o texto
		void setTexto(String textoStr) { this->texto.setString(textoStr); };
		/// Seta a posição do texto
		void setPosicao(Vector2f posicao) { texto.setPosition(posicao); };

		/// Retorna a variável desenhável de texto
		Text getTextoParaDesenho() {
			return texto; };

		/// Retorna uma string aleatória de um tamanho dado
		static String stringAleatoria(unsigned int n_chars);
	};
}