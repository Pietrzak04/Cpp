#pragma once

template <class T>
class Object
{
public:
	Object() {}

	Object* next = nullptr;
	T value;
};