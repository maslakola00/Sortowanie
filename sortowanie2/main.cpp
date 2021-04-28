#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include "cstdlib"
#include "Sort.cpp"


int main() {
    const int size=100;
    int i=2;
    Sort<int, size> tab1; //inicjalizacja samymi zerami
    Sort<int, size> tab2;

    switch(i) {

        case 1:

            tab1.RandomInit();
            tab1.Quicksort(0, size - 1);
            tab1.Display();
            tab1.Check();
            break;

        case 2:

           // int *tab2;
           // tab2=new int[size];


           tab2.RandomInit();
           tab2.MergeSort(0,size-1,tab2);
           for(int i=0;i<size;i++) {

               std::cout <<tab2[i] << std::endl;

           }

         //  tab1.Display();
         //  tab1.Check();
            //delete[] tab2;
            break;



        default:
            std::cout<<"To żadna z opcji, spróbuj ponownie";
    }


}
