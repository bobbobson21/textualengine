#pragma once

#include <iostream>

template <typename T >
class BaseEntityRunTimeHolder //helps pervent issies in deallocateing in run time memory for base entities and components
{
private:
	T* Object = nullptr;

public:

	BaseEntityRunTimeHolder()
	{
	}

	BaseEntityRunTimeHolder(T* Obj)
	{
		std::cout << sizeof(Obj);
		Object = Obj;
	}

	inline T* Get()
	{
		return Object;
	}

	void Set(T* Obj)
	{
		Object = Obj;
	}

	void Delete()
	{
		if (Object == nullptr) { return; }
		realloc( Object, 0 );
	}
};