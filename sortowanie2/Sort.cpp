
#include "Sort.h"



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



/*ALGORYTM SORTOWANIA QUICKSORT*/

template < int size>
void Sort<size>::Quicksort(int b, int e){


    int begin=b; //indeks poczatku tablicy
    int end=e; //indeks konca tablicy
    int middle=(b+e)/2; //indeks srodka tablicy


    int pivot=tab[middle].get_ranking(); //srodek tablicy


    while(begin<=end){


        while(tab[begin].get_ranking()<pivot) begin++; //przesuwanie poczatku az do rankingu mniejszego od pivota
        while(tab[end].get_ranking()>pivot) end--; //przesuwanie konca az do rankingu wiekszego od pivota



        if(begin<=end){


            int tmp=tab[end].get_ranking(); //zmienna pomocnicza do przechowywania rankingu

            tab[end].set_ranking(tab[begin].get_ranking()); //zamiana miejscami
            tab[begin].set_ranking(tmp); //podpisanie pod tablice przechowywanego rankingu

            std::string tmp2=tab[end].get_title();
            tab[end].set_title(tab[begin].get_title());
            tab[begin].set_title(tmp2);


            begin++;
            end--;
        }

    }

    if(b<end)//jezeli poczatkowa wartosc poczatku < konca po operacjach
    {
        Quicksort(b,end); //rekurencyjne wywolanie dla lewej strony od pivota
    }
    if(begin<e){
        Quicksort(begin,e); //rekurencyjne wywolanie dla prawej strony od pivota
    }
}






/*WYSWIETLANIE RANKINGU I TYTULU FILMU*/

template <int size>
void Sort<size>::Display(){

    for(int j=0;j<size;j++){
        std::cout<<tab[j].get_ranking()<<" "<<tab[j].get_title()<<std::endl;

    }
    std::cout<<std::endl;


}



/*SPRAWDZANIE POPRAWNOSCI SORTOWANIA*/


template <int size>
void Sort<size>::Check(){

    for(int j=1;j<size;j++){

        if(tab[j-1].get_ranking()>tab[j].get_ranking()) //jezeli cos poszlo zle to wyswietlamy komunikat
        {

            std::cout<<"Nie dziala"<<std::endl;
            exit(1);

        }

    }
    std::cout<<"Poprawnie"<<std::endl; //jezeli sortowanie jest poprawne wyswietlamy komunikat

}







template <int size>
void Sort< size>::Merge(int b, int e){

    if(b<e){

        int m=(b+e)/2;
        Merge(b,m);
        Merge(m+1,e);
        mergesort(b,m,e);

    }

}





/*ALGORYTM PODZIALU I SCALANIA DO MERGESORTA*/

template <int size>

void Sort<size>::mergesort(int begin, int middle, int end) {


    int first_size = middle - begin + 1; //rozmiar pierwszej tablicy obiektow
    int second_size = end - middle; //rozmiar drugiej tablicy obiektow

    Object* First_array = new Object[first_size]; //tworzenie peirwszej tablicy
    Object* Second_array = new Object[second_size]; //tworzenie drugiej tablicy



    for (int i = 0; i < first_size; ++i)
        First_array[i] = tab[begin + i]; //przepisanie obiektow z oryginalu do pierwszej tablicy

    for (int i = 0; i < second_size; ++i)
        Second_array[i] = tab[middle + i + 1]; //przepisanie obiektow z oryginalu do pierwszej tablicy
    int i = 0, j = 0, k=begin;


    while (i < first_size && j < second_size)
    {
        if (First_array[i].get_ranking() < Second_array[j].get_ranking()) //wykonuje sie jezeli wartosc z pierwszej tablicy jest wieksza od wartosci z drugiej
        {
            tab[k] = First_array[i];
            i++;
        }


        else //wykonuje sie jezeli wartosc z drugiej tablicy jest wieksza od wartosci z pierwszej
        {
            tab[k] = Second_array[j];
            j++;

        }
        k++;

    }

    while (i < first_size)
    {
        tab[k].set_ranking(First_array[i].get_ranking());
        tab[k].set_title(First_array[i].get_title());
        i++;
        k++;
    }

    while (j < second_size)
    {
        tab[k].set_ranking(Second_array[j].get_ranking());
        tab[k].set_title(Second_array[j].get_title());
        j++;
        k++;
    }

    delete[] First_array;
    delete[] Second_array;

}



/*ALGORYTM SORTOWANIA SHELLSORT*/

template <int size>
void Sort<size>::Shellsort(){

    int distance = size / 2;
    int temp_d; //zmienna pomocnicza dla dystansu
    int temp; //zmienna do przechowywania rankingu
    int j=0;
    std::string temp_s; //zmienna do przechowywania stringa

    while(distance>0) //nie chcemy porownywac liczb samych ze soba
    {
        temp_d=distance;


        while(temp_d<size) //wykonujemy kiedy temp_d mniejsze od rozmiaru tablicy
        {
            temp=tab[temp_d].get_ranking();
            temp_s=tab[temp_d].get_title(); //temp_s przechowuje tytul, ktory znajduje sie w oryginale na indeksie temp_d


            for(j=temp_d ; j>=distance && tab[j-distance].get_ranking()>temp ; j=j-distance)

            {

                tab[j].set_ranking(tab[j-distance].get_ranking());
                tab[j].set_title(tab[j-distance].get_title());


            }

            tab[j].set_ranking(temp);
            tab[j].set_title(temp_s);

            temp_d++;
        }
        distance = distance/2; //zmniejszanie dystansu pomiedzy porownywanymi liczbami
    }
}





/*SORTOWANIE KUBELKOWE*/

template <int size>
void Sort<size>::CupSort(const int wmin, const int wmax){

    LinkedList<int>* temp_rate = new LinkedList<int>[wmax + 1]; //tworzenie listy int

    LinkedList<std::string>* temp_title = new LinkedList<std::string>[wmax + 1]; //tworzenie listy string

   int value = wmin;
    int i=0;
 while(i<size)
 {
        while(value < wmax+1) //wykonuje az do osiagniecia przez value wartosci maksymalnej kubeczka
        {
            if(tab[i].get_ranking()==value)//dodanie obiektu do listy
            {
                temp_rate[value].add_without_priority(tab[i].get_ranking());
                temp_title[value].add_without_priority(tab[i].get_title());
                value++;

            }

             else
                 value++;
        }
        value = wmin;
     i++;
    }


    i=0;
    for(int b=1; b<wmax+1;b++)
      {
          for (int j = 0; j < temp_rate[b].getSize(); j++)
          {
              tab[i].set_ranking(temp_rate[b][j]); //dodanie rankingu
              tab[i].set_title(temp_title[b][j]); //dodanie tytulu

              i++;
          }
          //zwolnienie pamieci
          temp_rate[b].deleteList();
          temp_title[b].deleteList();


      }

}



/*FUNKCJA CZYTAJACA Z PLIKU*/

template <int size>

void Sort<size>::Read_from_file() {


        std::ifstream dane;
        dane.open ("projekt2_dane.csv");


        //zmienne pomocnicze
        int gdzie_kon, gdzie_pocz; //przechowywanie miejsc przecinka
        std::string pomoc_ocen, pomoc_tyt;

        //zmienne główne
        std::string odczyt;
        int ocena;
        int j = 0; // licznik rekordów


        //odczyt z pliku
        std::getline (dane, odczyt); // ignorowanie pierwszej linii w excelu ktora nie zawiera danych

        while (j < size)
        {
            pomoc_tyt = ""; // resetujemy pole tytuł
            std::getline (dane, odczyt); // odczytuję linię
            gdzie_kon = odczyt.rfind (','); // pozycja początkowego przecinka
            gdzie_pocz = odczyt.find_first_of (','); // pozycja końcowego przecinka

            for (int i=gdzie_pocz+1; i<gdzie_kon; i++) // podpisywanie tytułu
            {
                pomoc_tyt += odczyt [i];
            }
            tab[j].set_title(pomoc_tyt);

            if (odczyt[gdzie_kon+2] == '.') // podpisywanie oceny
            {
                pomoc_ocen [0] = odczyt [gdzie_kon+1];
                tab[j].set_ranking(atoi(pomoc_ocen.c_str()));
                j++;
            }
            if (odczyt[gdzie_kon+3] == '.')
            {
                tab[j].set_ranking(10);
                j++;
            }


        }



        dane.close(); //zamkniecie pliku


}






template <int size>

void Sort<size>::Calculations(){

    long double sum = 0.0;
    double mediana;
    long double srednia;

    for(int i=0;i<size;i++){

        sum = sum + tab[i].get_ranking(); //zliczanie sumy rankingow

    }

    srednia = sum/size; //obliczenie sredniej


    std::cout<<"Średnia wynosi: "<<srednia<<std::endl;

    if (size%2==0){ // przypadek dla liczby parzystej

        mediana = (tab[(size-1)/2].get_ranking()+tab[(size-1)/2+1].get_ranking())/2;

    }
    else{ // przypadek dla liczby nieparzystej

      mediana = tab[(size-1)/2].get_ranking();

    }
    

    std::cout<<"Mediana: "<<mediana<<std::endl;


}



/*SORTOWANIE KUBELKOWE NA TABLICY*/

template <int size>
void Sort<size>::bucket(const int wmin, const int wmax) {


    int *cups = new int[wmax]; //tablica kubelkow o rozmiarze wmax
    int *cups_copy = new int[wmax]; //kopia tablicy




    for (int i = 0; i < wmax; i++) //zerowanie kubelkow
        cups[i] = 0;



    for (int i = 0; i < size; i++) //zliczenie wystepowania rankingow w oryginalnej tablicy
        cups[tab[i].get_ranking() - 1]++;



    std::string **temp = new std::string *[wmax]; //tablica string



    for (int i = 0; i < wmax; i++)
        temp[i] = new std::string[cups[i]]; //ustawianie rozmiaru kubeczka w zaleznosci od ilosci wystapien


    for (int i = 0; i < wmax; i++) //kopiowanie ilosci wystapien rankigow w kubelkach
        cups_copy[i] = cups[i];



    for (int i = 0; i < size ; i++) //przypisanie danych to tablicy pomocniczej

    {
        temp[tab[i].get_ranking() - 1][cups_copy[tab[i].get_ranking() - 1] - 1] = tab[i].get_title(); //temp[RANKING][INDEKS] -- podpisujemy pod nia odpowiedni tytul;
        cups_copy[tab[i].get_ranking() - 1]--; //wypelnienie calej tablicy

    }



    for (int i = 0; i < wmax; i++)
        cups_copy[i] = cups[i];



    int k = 0;
    for (int i = 0; i < wmax; i++) //przypisanie wartosci do tablicy oryginalej
    {
        int j;
        for (j = k; cups_copy[i] > 0; j++) {
            tab[j].set_ranking(i + 1);
            tab[j].set_title(temp[i][cups_copy[i] - 1]);
            cups_copy[i]--;
        }
        k = j;
    }



    //zwolenienie pamieci
    for (int i = 0; i < wmax; i++)
        delete[] temp[i];
        delete[] temp;
        delete[] cups;
        delete[] cups_copy;


}

