#include <iostream>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
#include "cstdlib"
#include "Object.h"
#include "Sort.cpp"
typedef std::chrono::high_resolution_clock Clock;



int main() {


    const int size = 962763; //ilosc elementow do posortowania
    const int min = 0; //wartosc minimalna kubelka
    const int max = 10; //wartosc maksymalna kubelka
    int i; //zmienna do funkcji switch
    clock_t start,stop;
    double czas;




    Sort<size> tablica; //oryginal tablicy


    std::cout<<""<<std::endl;
    auto start_time = Clock::now();
    tablica.Read_from_file(); //czytanie z pliku i usuwanie pustych rankingow
    auto end_time = Clock::now();
    std::cout << "Czas czytania z pliku i usuwania tytulow bez rankingu: "
              <<std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " milliseconds " << std::endl;



    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"------------MENU--------------"<<std::endl;
    std::cout<<"Jaki algorytm sortowania chcesz wykonać?"<<std::endl;
    std::cout<<"1.QUICKSORT"<<std::endl;
    std::cout<<"2.MERGESORT"<<std::endl;
    std::cout<<"3.SHELLSORT"<<std::endl;
    std::cout<<"4.SORTOWANIE KUBELKOWE (STRUKTURA:LISTA)"<<std::endl;
    std::cout<<"5.SORTOWANIE KUBELKOWE (STRUKTURA: TABLICA)"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Dodatkowe opcje: "<<std::endl;
    std::cout<<"6.Wyświetlenie aktualnej tablicy"<<std::endl;
    std::cout<<"7.Mediana i srednia"<<std::endl;
    std::cout<<"8.Zakonczenie dzialania programu"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;


    while(i!=8) {


        std::cin>>i;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;

        switch (i) {


            case 1: {

                auto start_time = Clock::now();
                tablica.Quicksort(0, size - 1);
                auto end_time = Clock::now();
                tablica.Check();

                std::cout << "Time difference: "
                          <<std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
                          << " milliseconds " << std::endl;


                break;
            }

            case 2: {
                auto start_time = Clock::now();
                tablica.Merge(0, size - 1);
                auto end_time = Clock::now();
                tablica.Check();

                std::cout << "Time difference: "
                          <<std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
                          << " milliseconds " << std::endl;
                break;
            }

            case 3: {
                auto start_time = Clock::now();
                tablica.Shellsort();
                auto end_time = Clock::now();

                tablica.Check();
                std::cout << "Time difference: "
                          <<std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
                          << " milliseconds " << std::endl;
                break;
            }
            case 4:
            {
                auto start_time = Clock::now();
                tablica.CupSort(1, 10);
                auto end_time = Clock::now();

                tablica.Check();
                std::cout << "Time difference: "
                          <<std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
                          << " milliseconds " << std::endl;



                break;
            }

            case 5:
            {
                auto start_time = Clock::now();
                tablica.bucket(1, 10);
                auto end_time = Clock::now();

                tablica.Check();
                std::cout << "Time difference: "
                          <<std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count()
                          << " nanoseconds " << std::endl;


                break;
            }


            case 6:
                tablica.Display();
                break;

            case 7:
                tablica.Calculations();
                break;

            default:
                i=8;
                std::cout<<"Zakonczenie pracy programu"<<std::endl;
                break;

        }

    }


}