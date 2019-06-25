#include "Jogo.h"

#ifndef _DEBUG
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#endif

int main()
{
#ifndef _DEBUG
	FreeConsole();
#endif

	srand(static_cast<unsigned int>(time(NULL)));

	Jogo jogo;
	jogo.executar();

	return 0;
}