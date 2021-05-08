#include "SNode.h"

template<typename TYPE>
SNode<TYPE>::~SNode()
{

}

template<typename TYPE>
SNode<TYPE>::SNode(): _next_elem(nullptr)
{

}

template<typename TYPE>
SNode<TYPE>::SNode(const TYPE & elem): _next_elem(nullptr),  _elem(elem)
{

}

template<typename TYPE>
TYPE &SNode<TYPE>::get_elem()
{
    return _elem;
}

template<typename TYPE>
SNode<TYPE>* SNode<TYPE>::get_next_elem()
{
    return _next_elem;
}


template<typename TYPE>
void SNode<TYPE>::set_elem(const TYPE & elem)
{
    _elem=elem;
}

template<typename TYPE>
void SNode<TYPE>::set_next_elem( SNode<TYPE>& next_elem)
{
    _next_elem = &next_elem;
}








