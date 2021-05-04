#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include "cstdlib"
#include "Sort.h"
#include "Object.h"


template <int size>
Sort<size>::Sort()
{
    tab = new Object[size];

}



template <int size>
Sort<size>::~Sort()
{
    delete[] tab;
}


template < int size>
void Sort<size>::Quicksort(int b, int e){


    int begin=b;
    int end=e;
    int middle=(b+e)/2;
    int pivot=tab[middle].get_ranking();


    while(begin<=end){
        while(tab[begin].get_ranking()<pivot) begin++;
        while(tab[end].get_ranking()>pivot) end--;

        if(begin<=end){
            int tmp=tab[end].get_ranking();
            tab[end].set_ranking(tab[begin].get_ranking());
            tab[begin].set_ranking(tmp);

            std::string tmp2=tab[end].get_title();
            tab[end].set_title(tab[begin].get_title());
            tab[begin].set_title(tmp2);


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




template <int size>
void Sort<size>::Display(){


    for(int j=0;j<size;j++){
        std::cout<<tab[j].get_ranking()<<" "<<tab[j].get_title()<<std::endl;

    }
    std::cout<<std::endl;


}



template <int size>
void Sort<size>::Check(){

    for(int j=1;j<size;j++){

        if(tab[j-1].get_ranking()>tab[j].get_ranking()){

            std::cout<<"Nie dziala"<<std::endl;
            exit(1);

        }

    }
    std::cout<<"Poprawnie"<<std::endl;

}




template <int size>
void Sort< size>::Merge(int b, int e){

    if(b<e){
        int m=(b+e)/2;
        Merge(b,m);
        Merge(m+1,e);
        MergeSort(b,e,m);
    }

}


template <int size>
void Sort<size>::MergeSort(int begin, int end, int middle){




    Object *temp1 = new Object[begin+end+1];


    int point1=begin;
    int point2=middle+1;
    int index=begin;



    while(point1<=middle && point2<=end ){


        if(tab[point1].get_ranking()<tab[point2].get_ranking()){


            temp1[index].set_ranking(tab[point1].get_ranking());
           // temp1[index].set_title(tab[point1].get_title());

            point1++;

        }

        else {


            temp1[index].set_ranking(tab[point2].get_ranking());
           // temp1[index].set_title(tab[point2].get_title());

            point2++;


        }


        index++;

    }



    while (point1<=middle){

        temp1[index].set_ranking(tab[point1].get_ranking());
        //temp1[index].set_title(tab[point1].get_title());

        point1++;
        index++;

    }

    while(point2<=end){

        temp1[index].set_ranking(tab[point2].get_ranking());
       // temp1[index].set_title(tab[point2].get_title());

        point2++;
        index++;

    }



    for(int i=begin;i<=end;i++) {


        tab[i].set_ranking(temp1[i].get_ranking());
        //tab[i].set_title(temp1[i].get_title());

    }

  delete [] temp1;

}









template <int size>
void Sort<size>::CupSort(const int wmin, const int wmax,int index){




    Object **temp1 = new Object[wmax+1];

    while(wmax<=index){

        for(int i=0;i<size;i++) {

           //int j = tab[i].get_ranking();


        }
    }

}








/*

template <int size>
void Sort<size>::Cup(const int wmin, const int wmax,int index){

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



}*/




