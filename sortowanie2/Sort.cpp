#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include "cstdlib"
#include "Sort.h"




template <typename T, int size>
Sort<T, size>::Sort()
{
    tab = new T[size];

}




template <typename T, int size>
Sort<T, size>::~Sort()
{

    delete[] tab;

}


template <typename T, int size>
void Sort< T , size>::Quicksort(int b, int e){


    int begin=b;
    int end=e;
    int middle=(b+e)/2;
    int pivot=tab[middle];


    while(begin<=end){
        while(tab[begin]<pivot) begin++;
        while(tab[end]>pivot) end--;

        if(begin<=end){
            int tmp=tab[end];
            tab[end]=tab[begin];
            tab[begin]=tmp;
            begin++;
            end--;
        }

    }

    if(b<end)//jezeli poczatkowa wartosc poczatku < konca po operacjach
    {
        Quicksort(b,end);
    }
    if(begin<e){
        Quicksort(begin,e);
    }


}





template <typename T, int size>
void Sort< T , size>::Display(){


        for(int j=0;j<size;j++){
            std::cout<<tab[j]<<std::endl;
        }
        std::cout<<std::endl;


}


template <typename T, int size>
void Sort<T,size>::RandomInit() {

    srand(time(NULL));

        for(int j=0;j<size;j++){
            tab[j]=(std::rand()%100)+1;
        }
        std::cout<<std::endl;

}




/*template <typename T, int size>
void Sort<T,size>::Reverse() {


    int tmp=size/2;
    int j=0;

    for(int i=0;i<size;i++){

        int second=size1-1;
        j=0;
        while(second>=tmp && j<tmp) {
            std::swap(tab[i][j], tab[i][second]);
            second--;
            j++;
        }
    }
}*/





template <typename T, int size>
void Sort<T,size>::Check(){

        for(int j=0;j<size;++j){
            if(tab[j-1]>tab[j]){
                std::cout<<"Nie dziala, sory Ola"<<std::endl;
                exit(1);
            }
        }
    std::cout<<"Poprawnie"<<std::endl;

}


template <typename T, int size>
void Sort<T, size>::Merge(int b, int e,T* temp){

    int m=(b+e)/2;

    if(b<e){

    Merge(b,m,tab);
    Merge(m+1,b,tab);
    MergeSort(b,e,tab);
    }

}


template <typename T, int size>
    void Sort<T, size>::MergeSort(int begin, int end, T* temp){

    int middle=(begin+end)/2;
    int point1=begin;
    int point2=middle+1;
    int k=0;

    while(point1<=middle && point2<=end ){


    if(tab[point1]<tab[point2]){
        temp[k]=tab[point1];
        point1++;
    }

    else {
        temp[k]=tab[point2];
        point2++;
    }

        k++;
    }



    while (point1<=middle){
        temp[k]=tab[point1];
        point1++;
        k++;
    }

    while(point2<=end){
        temp[k]=tab[point2];
        point2++;
        k++;
    }


}