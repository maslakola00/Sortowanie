/*
 * KLASA LINKEDLIST
 *
 * zawiera wskaźnik na głowę listy
 * jest zbudowana z obiektów klasy SNode
 *
 * dodawanie elementów
 *
 * */


#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include "SNode.cpp"



template<typename TYPE>
class LinkedList
{

private:
    SNode<TYPE>* head;
    int Listsize;

public:
    LinkedList(); //konstruktor bezparametrowy
    ~LinkedList(); //destruktor


/*
 * removeFront
 * usuwane początku listy przestawiajac wskaznika head na nastepny element
 * */
    void removeFront();

/*
 *front()
 *zwraca pierwszy element listy
 * */
    const TYPE & front() const;

/*
 * empty()
 * sprawdzanie czy lista ma jakies elementy
 * return true - lista jest pusta
 * return false - lista nie jest pusta
 * */
    bool empty() const;

/*
 * print()
 * funkcja wypisuje elementy listy
 * */
    void print();

/*
 *add_without_priority
 *dodawanie pakietow do listy bez uwzgledniania priorytetow
 *
 * */
    void add_without_priority(const TYPE& Node);

  //  Object operator[](int index);

    TYPE operator[](int index);

    int getSize(){

        return Listsize;

    };

    void deleteList();

};






#endif


































