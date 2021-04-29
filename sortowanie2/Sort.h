#pragma once

template <typename T, int size>
class Sort{

    T *tab;


public:


    Sort(); //konstruktor bezparamtrowy
    ~Sort(); //destruktor
    void Quicksort(int , int ); //funkcja quicksorta
    void Display(); //wyswietlanie
    void RandomInit();
    void Check(); //sprawdzanie czy tablica dobrze się posortowała
    void Merge(int, int);
    void MergeSort(int, int, int );
    void Cup(const int, const int, int ); //sortowanie kubelkowe


};

