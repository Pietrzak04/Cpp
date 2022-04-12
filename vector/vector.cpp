#include <iostream>
#include "MyVector.h"
#include <vector>
#include <chrono>

int main()
{
	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second = end - start;

    MyVector<int> vec;

	std::vector<int> vec2;

	start = std::chrono::steady_clock::now();
    for (int i = 0; i < 20000; i++)
    {
        vec.pushBack(i);
    }
	end = std::chrono::steady_clock::now();
	elapsed_second = end - start;

	std::cout << "czas mojego: " << elapsed_second.count() << std::endl;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < 20000; i++)
	{
		vec2.push_back(i);
	}
	end = std::chrono::steady_clock::now();
	elapsed_second = end - start;

	std::cout << "czas std vector: " << elapsed_second.count() << std::endl;

    //std::cout << vec.getCapacity() << std::endl;
    //std::cout << vec.getSize() << std::endl;
   // std::cout << vec[-5] << std::endl;
   // std::cout << vec.at(-4) << std::endl;
   // std::cout << vec[40] << std::endl;
   // std::cout << vec.at(40) << std::endl;

    /*for (int i = 0; i < 10; i++)
    {
        vec.pushBack(4 + i);
    }

    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }

    for (int i = 0; i < 20; i++)
    {
        vec.popBack();
    }

    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }

    for (int i = 0; i < 5; i++)
    {
        vec.pushBack(i);
    }

    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }*/

    /*for (int i = 0; i < 5; i++)
    {
        vec.pushBack(i);
    }

    std::cout << "capacity " << vec.getCapacity() << std::endl;
    std::cout << "size " << vec.getSize() << std::endl;

    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }

    vec.remove(3);

    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }*/

}

