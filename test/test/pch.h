/// @file pch.h Plik zawieraj�cy klas� scalanie

//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
/// @brief Klasa scalanie oraz deklaracje jej metod
class scalanie {
private:
	string* tab;///< wska�nik do Zmiennej zawieraj�cej nieposortowanieowan� tablic� typu string
	int* tabs;///< wska�nik do tablicy zawieraj�cej posortowanieowan� tablic� tab
public:

	scalanie(string a);
	~scalanie();
	int sprawdzanie(int i, string a);
	int dlugosc(string a);
	void convert(int a);
	void sortowanie(int a);
	string zwrottabs(string a);
	int* wsaztabs();
};