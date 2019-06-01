#ifndef ELEMENTO_H__
#define ELEMENTO_H__

template <class T>
class Elemento
{
private:
	Elemento<T>* proximo;

	Elemento<T>* objeto;

	int ID;

public:
	Elemento(T* novo_objeto = 0, int id = 0)
	{
		proximo = 0;

		objeto = novo_objeto;

		ID = id;
	};
	~Elemento() {};
};

#endif // ELEMENTO_H__