#pragma once

#ifndef NULL
#define NULL 0
#endif

namespace Listagem
{
	template <class T>
	class Lista
	{
	private:

		template <class TE>
		class Elemento
		{
		private:
			Elemento<TE>* anterior;
			Elemento<TE>* proximo;

			TE* objeto;

		public:
			Elemento(TE* novo_objeto = NULL);
			~Elemento();

			friend class Lista;
		};

		Elemento<T>* primeiro;
		Elemento<T>* ultimo;

		int n_elementos;

		Elemento<T>* iterador;

	public:
		Lista();
		~Lista() {};

		/// Insere um valor
		void pushLista(T* novo_obj);

		/// Remove um valor
		void popLista(T* objeto);
		/// Remove o primeiro
		void popPrimeiro();

		/// Retorna o objeto apontado pelo iterador
		T* getObjeto();

		/// Verifica se a lista está vazia
		bool vazia() { return !n_elementos; };

		/// Move o iterador para o próximo elemento
		bool moverIterador();
		/// Volta o iterador para o primeiro da lista
		void zerarIterador();

		void operator=(Lista<T>& nova_lista);
	};
}
#include "Lista.inl"