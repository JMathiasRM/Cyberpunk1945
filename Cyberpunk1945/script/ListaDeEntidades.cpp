#include "ListaDeEntidades.h"

using namespace Listagem;

ListaDeEntidades::ListaDeEntidades()
{
}

ListaDeEntidades::~ListaDeEntidades()
{
	while (!listaEntidades.vazia())
		listaEntidades.popPrimeiro();
}

void ListaDeEntidades::executar()
{
	if(!listaEntidades.vazia())
		do {
			if(listaEntidades.getObjeto())
				listaEntidades.getObjeto()->executar();
		} while (listaEntidades.moverIterador());
}

void ListaDeEntidades::moverEntidades()
{
	if(!listaEntidades.vazia())
		do {
			listaEntidades.getObjeto()->mover();
		} while (listaEntidades.moverIterador());
}


void ListaDeEntidades::desenharEntidades(float dT)
{
	if (!listaEntidades.vazia())
		do {
			listaEntidades.getObjeto()->desenhar(dT);
		} while (listaEntidades.moverIterador());
}