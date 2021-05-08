#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "cstdlib"
#include "Object.h"
#include "Sort.cpp"




int main() {


    const int size = 3000;
    const int min = 0;
    const int max = 10;
    int i = 4;
    std::string line;
    std::string line1;
    std::string mark;
    int first, second;
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

            if(line1!=" ") {

                   int rank = atoi(line1.c_str());

                   tablica.get_obj()[k].set_ranking(rank);
                   tablica.get_obj()[k].set_title(mov);

                   k++;

           }

    }



/*
    std::ifstream dane;
    dane.open("projekt2_dane.csv",std::ios::in);

    if (dane.good() == false) {

        std::cout << "Nie mozna odtworzyc pliku" << std::endl;
    }

    getline(dane,line);
    while(k < size){

        line1="";
        getline(dane,line);
        first = line.rfind(',');
        second = line.find_first_of(',');

        for(int j=first+1; j<second;j++){

            line1 += line[j];

        }

        tablica.get_obj()[k].set_title(line1);


        if(line[second+2]=='.'){

            mark[0]=line[second+1];
            tablica.get_obj()[k].set_ranking(std::stoi(mark));
            k++;

        }

        if(line[second+3]=='.'){

            tablica.get_obj()[k].set_ranking(10);
            k++;
        }

    }
 dane.close();

*/

    /*WYBIERANIE SORTOWANIA*/

       switch(i) {

           case 1:


               tablica.Quicksort(0, size - 1);
              tablica.Display();
               tablica.Check();
               break;



           case 2:



               // tablica.Display();
                tablica.Merge(0,size-1);
                //tablica.Display();
                tablica.Check();

               break;


           case 3:

              // tablica.Display();
               tablica.Shellsort();
               std::cout<<"Po sortowaniu:"<<std::endl;
               tablica.Display();
               tablica.Check();




               break;



           case 4:
              // tab1.RandomInit();
              // tablica.Display();
               std::cout<<"Po sortowaniu"<<std::endl;
               tablica.CupSort(0,10);
              // tablica.Display();
               tablica.Check();

               break;


       }



}