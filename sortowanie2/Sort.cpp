
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
            temp1[index].set_title(tab[point1].get_title());

            point1++;

        }

        else {


            temp1[index].set_ranking(tab[point2].get_ranking());
             temp1[index].set_title(tab[point2].get_title());

            point2++;


        }


        index++;

    }



    while (point1<=middle){

        temp1[index].set_ranking(tab[point1].get_ranking());
        temp1[index].set_title(tab[point1].get_title());

        point1++;
        index++;

    }

    while(point2<=end){

         temp1[index].set_ranking(tab[point2].get_ranking());
         temp1[index].set_title(tab[point2].get_title());

            point2++;
            index++;

    }



    for(int i=begin;i<=end;i++) {


        tab[i].set_ranking(temp1[i].get_ranking());
        tab[i].set_title(temp1[i].get_title());

    }

  delete [] temp1;

}

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
        while(temp_d<size)
        {
            temp=tab[temp_d].get_ranking();
            temp_s=tab[temp_d].get_title();


            for(j=temp_d; j>=distance && tab[j-distance].get_ranking()>temp;j=j-distance)
            {

                tab[j].set_ranking(tab[j-distance].get_ranking());
                tab[j].set_title(tab[j-distance].get_title());


            }

            tab[j].set_ranking(temp);
            tab[j].set_title(temp_s);

            temp_d++;
        }
        distance = distance/2;
    }
}



template <int size>
void Sort<size>::CupSort(const int wmin, const int wmax){

    LinkedList<Object>* temp = new LinkedList<Object>[wmax + 1];

   int value = wmin;


    for(int i=0; i < size; i++)
    {

        while(value <= wmax)
        {
            if(tab[i].get_ranking()==value) {
                temp[value].add_without_priority(tab[i]);

                value++;
            }

             else   value++;

        }

        value = wmin;

    }

    int b=0;
    int i=0;

  while(i<size)
    {
        b++;
        for(int j=0;j<temp[b].getSize();j++) {

            tab[i].set_ranking(temp[b][j].get_ranking());
            tab[i].set_title(temp[b][j].get_title());
            temp[b].removeFront();


            i++;
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




