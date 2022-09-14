#include "../List.h"

#ifndef STACK

#define STACK 1


template <class T>
class Stack {
    private:
        List<T>* stackList;
    public:
        Stack() {
            this->stackList = new List<T>();
        }

        // Mete un elemento a la pila
        void push (T* pValue) {
            this->stackList->insert(this->stackList->getSize(), pValue);
        }

        // Saca el ultimo elemento de la pila
        T* pop () {
            T* lastT = this->stackList->getLast()->getData();
            this->stackList->remove(this->stackList->getSize() - 1);
            return lastT;
        }

         // Retorna True si la pila está vacía 
        bool isEmpty() {
            return this->stackList->isEmpty();
        }

        // Retorna el ultimo elemento pero sin modificar la pila
        T* top () {
            T* lastT = this->stackList->getLast()->getData();
            return lastT;
        }

};

#endif