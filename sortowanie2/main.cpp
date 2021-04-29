#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include "cstdlib"
#include "Sort.cpp"




int main() {


    const int size=10;
    const int wmin=1;
    const int wmax=10;
    int i=3;
    Sort<int, size> tab1; //inicjalizacja samymi zerami



    switch(i) {

        case 1:

            tab1.RandomInit();
            tab1.Quicksort(0, size - 1);
            tab1.Display();
            tab1.Check();
            break;

        case 2:

            tab1.RandomInit();

            std::cout<<"Po sortowaniu:"<<std::endl;

            tab1.Merge(0,size-1);
            tab1.Display();
            tab1.Check();

            break;


        case 3:
            tab1.RandomInit();
            tab1.Display();
            std::cout<<"Po sortowaniu"<<std::endl;
            tab1.Cup(wmin,wmax,1);
            tab1.Display();
            tab1.Check();
            break;


    }


}
