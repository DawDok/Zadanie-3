/// @file pch.h Plik zawieraj¹cy klasê scalanie

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
	string* tab;///< wskaŸnik do Zmiennej zawieraj¹cej nieposortowanieowan¹ tablicê typu string
	int* tabs;///< wskaŸnik do tablicy zawieraj¹cej posortowanieowan¹ tablicê tab
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