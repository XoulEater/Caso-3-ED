#include <Stack.h>

#ifndef QUEUEP

#define QUEUEP 1

template <class T>
class QueueP {
    private:
        Stack<T>* StackFW; // Stack Foward
        Stack<T>* StackBW; // Stack Backward
    public:
        QueueP(){
            this->StackBW = new Stack<T>();
            this->StackFW = new Stack<T>();
        }

        bool isEmpty () {
            return this->StackBW->isEmpty() && this->StackFW->isEmpty();
        }

        void enqueue (T* pValue) {
            this->StackFW->push(pValue);
        }

        T* dequeue () {
            if (this->StackBW->isEmpty()){
                while (!this->StackFW->isEmpty()) {
                    this->StackBW->push(this->StackFW->pop());
                }
            }
            return this->StackBW->pop();
        }

        T* front () {
            if (this->StackBW->isEmpty()){
                while (!this->StackFW->isEmpty()) {
                    this->StackBW->push(this->StackFW->pop());
                }
            }
            return this->StackBW->top();    
            

        }
        
};

#endif