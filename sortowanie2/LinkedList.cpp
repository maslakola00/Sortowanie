#include <iostream>
#include "LinkedList.h"
//#include "/include/LinkedList.h"


template<typename TYPE>
LinkedList<TYPE>::~LinkedList()
{

}


//inicjuje obiekt ktory nie poakzuje na nic (NULL)
template<typename TYPE>
LinkedList<TYPE>::LinkedList(): head(nullptr)
{


}


template<typename TYPE>
const TYPE & LinkedList<TYPE>::front() const
{
    return head->get_elem();
}


template<typename TYPE>
void LinkedList<TYPE>::removeFront()
{

    SNode<TYPE>* temp = head; //tworzymy zmienna ktora pokazuje na head zeby nie zgubic pamieci head
    head = head->get_next_elem(); //przestawiamy head na nastepny element
    Listsize--;

    delete temp; //usuwamy pamiec ktora byla pod head


}


template<typename TYPE>
void LinkedList<TYPE>::print()
{
    SNode<TYPE>* tmp = head; //podpisanie zmiennej pod wartosc i adres head(by od pcozatku printowac liste)
    while(tmp->get_next_elem() !=nullptr ) //jesli lista nie jest pusta
    {
        std::cout << tmp->get_elem()<< " ";  //print wartosc pod adresem tmp
        tmp = tmp->get_next_elem(); //przestaw na kolejne miejsce
    }
    std::cout << tmp->get_elem() <<"  "; //printowanie ostatniego elementu
}


template<typename TYPE>
bool LinkedList<TYPE>::empty() const
{
    if(head == nullptr)
        return true; //glowa pokazuje zerowy wskaznik, lista jest pusta
    else
        return false; //lista nie jest pusta
}




template<typename TYPE>
void LinkedList<TYPE>::add_without_priority(const TYPE& Node)
{
    SNode<TYPE>* temp = new SNode<TYPE>;
    temp->set_elem(Node); //podpisujemy wartosc
    temp->set_next_elem(*head); // pod temp podpisz head
    head = temp;
    Listsize++;
}

template<typename TYPE>
Object LinkedList<TYPE>::operator[](int index)
{
    SNode<TYPE>* tmp = new SNode<TYPE>;
    tmp = head;

    for(int i=0;i< index;i++)
        tmp = tmp->get_next_elem();


        return tmp->get_elem();

}























































