#pragma once
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include "cstdlib"
#include "Object.h"
#include "LinkedList.cpp"


template < int size>
class Sort{

    Object *tab;


public:


    Sort(); //konstruktor bezparamtrowy
    ~Sort(); //destruktor

    /*FUNKCJA OBSLUGUJACE TABLICE*/
    void Read_from_file(); //czytanie z pliku i usuwanie miejsc bez rankingu
    void Check(); //sprawdzanie czy tablica poprawnie się posortowała
    void Calculations(); //obliczenie sredniej i mediany
    void Display(); //wyswietlanie tablicy



    /*ALGORYTMY SORTOWANIA*/

    void Quicksort(int , int ); //algorytm quicksort
    void Merge(int, int); //wywolanie rekurencyjne dla algorytmu mergesort
    void mergesort(int begin, int middle, int end); //podzial i scalanie dla mergesorta
    void CupSort(const int, const int ); //sortowanie kubelkowe na liscie
    void Shellsort(); //algorytm shellsorta
    void bucket(const int, const int); //sortowanie kubelkowe na tablicy



    /*getter dla obiektu */
    Object* get_obj(){

        return tab;
    }



};

