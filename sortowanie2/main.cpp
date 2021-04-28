#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include "cstdlib"
#include "Sort.cpp"


int main() {
    const int size=1000;
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

            tab1.RandomInit();

            std::cout<<"Po sortowaniu:"<<std::endl;

            tab1.Merge(0,size-1);
            tab1.Display();
            tab1.Check();

            break;

    }


}
