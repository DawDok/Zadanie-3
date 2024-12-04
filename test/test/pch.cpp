/// @file test.cpp Plik g³ówny

//
// pch.cpp
//

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
/// @brief konstruktor, automatycznie sortowanieuje tablicê
/// @param a - tablica do posortowanieowania 
scalanie::scalanie(string a) {
    if (a != "") {//je¿eli string == "" to przechodzi do else w którym ustawia tablicê na 0
        int i = 0;
        int tabtab = 0;
        int spaces = dlugosc(a);
        tab = new string[spaces + 1];
        tabs = new int[spaces + 1];

        while (i < a.length()) {
            if (a[i] == ' ') {
                i += 1;
                continue;
            }

            int wordLength = sprawdzanie(i, a);

            tab[tabtab] = a.substr(i, wordLength);
            tabtab += 1;

            i += wordLength;
        }
        convert(spaces);
        sortowanie(spaces);
    }
    else {
        tab = new string[1];
        tab[0] = "";
        tabs = new int[0];
    }
    
}
/// @brief Destruktor, usuwa zmienne dynamiczne tab i tabs
scalanie::~scalanie() {
    delete[] tab;
    delete[] tabs;
};

/// @brief metoda sprawdzanie, zwraca d³ugoœæ danego elementu tablicy (np. 3 element to 25 czyli ma d³ugoœæ 2) 
/// @param i - miejece elementu w string a 
/// @param a - nieposortowanieowana tablica tab
int scalanie::sprawdzanie(int i, string a) {
    int length = 0;
    while (i + length < a.length() && a[i + length] != ' ') {
        length += 1;
    }
    return length;
}

/// @brief metoda dlugosc zwraca iloœæ spacji w stringu powiêkszonej o 1
/// @param a - nieposortowanieowana tablica tab
int scalanie::dlugosc(string a) {
    int spaces = 0;
    for (int j = 0; j < a.length(); j++) {
        if (a[j] == ' ') {
            spaces += 1;
        }
    }
    return spaces + 1;
}
/// @brief metoda zwrottab, konwertuje string tab do tablicy int tabs 
/// @param spaces - iloœæ elementów tablicy tabs
void scalanie::convert(int spaces) {
    int i = 0;
    while (i < (spaces)) {
        tabs[i] = stoi(tab[i]);
        i++;
    }
}
/// @brief metoda sortowanie, sortowanieuje tablicê tabs
/// @param spaces - iloœæ elementów tablicy tabs
void scalanie::sortowanie(int spaces) {
    int mnoznik = 1;

    while (mnoznik < spaces) {
        for (int i = 0; i < spaces; i += (2 * mnoznik)) {
            int mid = min(i + mnoznik, spaces);
            int end = min(i + 2 * mnoznik, spaces);


            int* temp = new int[spaces];
            int left = i, right = mid, k = i;


            while (left < mid && right < end) {
                if (tabs[left] <= tabs[right]) {
                    temp[k++] = tabs[left++];
                }
                else {
                    temp[k++] = tabs[right++];
                }
            }


            while (left < mid) {
                temp[k++] = tabs[left++];
            }


            while (right < end) {
                temp[k++] = tabs[right++];
            }


            for (int j = i; j < end; j++) {
                tabs[j] = temp[j];
            }

            delete[] temp;
        }

        mnoznik *= 2;
    }
}



/// @brief metoda zwrottabs,zwraca tablicê w stringu
/// @param a - nieposortowanieowana tablica tab
string scalanie::zwrottabs(string a) {
    if (tab[0] == "") {
        return "";
    }
    else {
        int i = 0;
        string r;
        while (i < dlugosc(a)) {
            r += to_string(tabs[i]);
            if (i != (dlugosc(a) - 1)) {
                r += " ";
            }
            i++;
        }
        return  r;
    }
}
/// @brief metoda wsaztabs, zwraca wskaŸnik na tabs
int* scalanie::wsaztabs() {
    return tabs;
}