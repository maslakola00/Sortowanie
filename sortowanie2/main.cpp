#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <string>
#include "cstdlib"
#include "Object.h"
#include "Sort.cpp"




int main() {


    const int size = 100000;
    const int min = 1;
    const int max = 10;
    int i = 2;
    std::string line;
    std::string line1;
     int k = 0;

    Sort<size> tablica;




    /*CZYTANIE Z PLIKU*/

    std::fstream filmy;
    filmy.open("movie.txt", std::ios::in);

    std::fstream rankingi;
    rankingi.open("rating.txt", std::ios::in);

    if (filmy.good() == false) {

        std::cout << "Nie mozna odtworzyc pliku z filmami" << std::endl;
    }

    if (rankingi.good() == false) {

        std::cout << "Nie mozna odtworzyc pliku z rankingami" << std::endl;
    }


     for(int b=0;b<size;b++){

            std::getline(filmy,line);
            std::string mov = line;

            std::getline(rankingi,line1);

            if(line1!="0") {

                   int rank = atoi(line1.c_str());

                   tablica.get_obj()[k].set_ranking(rank);
                   tablica.get_obj()[k].set_title(mov);


                   k++;

           }


          else {
                std::cout << mov << "brak rankingu" << std::endl;

           }


    }


    /*WYBIERANIE SORTOWANIA*/

       switch(i) {

           case 1:


               tablica.Quicksort(0, size - 1);
              // tablica.Display();
               tablica.Check();
               break;



           case 2:



               // tablica.Display();
                tablica.Merge(0,size-1);
                //tablica.Display();
                tablica.Check();

               break;

/*
           case 3:
               tab1.RandomInit();
               tab1.Display();
               std::cout<<"Po sortowaniu"<<std::endl;
               tab1.Cup(min,max,1);
               tab1.Display();
               tab1.Check();
               break; */


       }



}