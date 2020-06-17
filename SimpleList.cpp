#include "SimpleList.h"
//#include <type_traits>

template <class T>
void destroy(T element);

template <class T>
void destroy(T* element);

template <class T>
SimpleList<T>::SimpleList(){
	elements = new T[CAPACITY];
	numElements = 0;
}

template <class T>
SimpleList<T>::~SimpleList(){
	for(int i = 0; i < numElements; i++){
		destroy(elements[i]);
	}
	delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){

	if (index >= numElements || index < 0){
		throw InvalidIndexException();
	}
	return elements[index];
	
}

template <class T>
bool SimpleList<T>::empty() const{
	return (numElements == 0);
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
	if(this->empty()){
		throw EmptyListException();
	}
	else return at(0);
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
	if(this->empty()){
		throw EmptyListException();
	}
	else return at(numElements-1);
}

template <class T>
int SimpleList<T>::getNumElements() const{
	return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
	if (numElements == CAPACITY){
		throw FullListException();
	}
	else{
		elements[numElements] = item;
		numElements++;
	}
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
	if(empty()){
		throw EmptyListException();
	}

	else if(index >= numElements)
		throw InvalidIndexException();

	else{
		destroy(elements[index]);
		numElements--;
		for(int i = index; i < numElements; i++){
			if(i != 9){
				elements[i] = elements[i+1];
			}
			else if(i == 9){
				destroy(elements[i]);
			}

		}
	}
}

template<class T>
void destroy(T element) {
	// do nothing
}

template <class T>
void destroy(T* element) {
	// delete the pointer type
	delete element;
}