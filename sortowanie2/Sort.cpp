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
            tab[j]=(std::rand()%10)+1;
        }
        std::cout<<std::endl;

}




template <typename T, int size>
void Sort<T,size>::Check(){

        for(int j=0;j<size;++j){
            if(tab[j-1]>tab[j]){
                std::cout<<"Nie dziala"<<std::endl;
                exit(1);
            }
        }
    std::cout<<"Poprawnie"<<std::endl;

}




template <typename T, int size>
void Sort<T, size>::Merge(int b, int e){

    if(b<e){
        int m=(b+e)/2;
        Merge(b,m);
        Merge(m+1,e);
        MergeSort(b,e,m);
    }

}


template <typename T, int size>
    void Sort<T, size>::MergeSort(int begin, int end, int middle){

    int *temp= new int[size];

    int point1=begin;
    int point2=middle+1;
    int index=begin;



    while(point1<=middle && point2<=end ){



    if(tab[point1]<tab[point2]){
        temp[index]=tab[point1];
        point1++;
    }

    else {
        temp[index]=tab[point2];
        point2++;
    }
        index++;
    }



    while (point1<=middle){
        temp[index]=tab[point1];
        point1++;
        index++;
    }

    while(point2<=end){
        temp[index]=tab[point2];
        point2++;
        index++;
    }

    for(int i=begin;i<=end;i++) {
        tab[i]=temp[i];
    }
    delete[] temp;

}


template <typename T, int size>
void Sort<T, size>::Cup(const int wmin, const int wmax,int index){

    int *temp= new int[wmax+1];
    int b=0;



    while(index<=wmax) {
        int i=1;
        while (i <= size) {
            if (tab[i-1] ==index) {
                temp[index]=temp[index]+1;
            }
            i++;
        }
        index++;

    }

    for(int j=0;j<(wmax+1);j++){

        for(int k=1;k<=temp[j];k++) {
            tab[b]=j;
             b++;
          }

    }



}





