#pragma once
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include "cstdlib"
#include "Object.h"
#include "LinkedList.cpp"


template < int size>
class Sort{

    Object *tab;


public:


    Sort(); //konstruktor bezparamtrowy
    ~Sort(); //destruktor
    void Quicksort(int , int ); //funkcja quicksorta
    void Display(); //wyswietlanie
    void Check(); //sprawdzanie czy tablica dobrze się posortowała
    void Merge(int, int);
    void MergeSort(int, int, int );
    void CupSort(const int, const int ); //sortowanie kubelkowe
    void Shellsort();

    Object* get_obj(){

        return tab;
    }



};

