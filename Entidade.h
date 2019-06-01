#ifndef ENTIDADE_H__
#define ENTIDADE_H__

#include "Animador.h"

class Entidade
{
private:
	Animador animador;

public:
	Entidade();
	virtual ~Entidade();

	virtual void go() = 0;
};

#endif // ENTIDADE_H__