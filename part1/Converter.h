#include <../Stack.h>
#include <string>
#include <Token.h>



#ifndef CONVER

#define CONVER 1

using namespace std;


class Converter
{
    private:
        string resul;
        Stack<char>* operadores = new Stack<char>();
        
    public:
        string Convert (List<Token>* Pelements) {

            Stack<Token>* elements = new Stack<Token>(); 
            Token* element;
            string resul;
            
            for (int i = 0; i < Pelements->getSize(); i++)
            {

                element = Pelements->find(i);
                if (element->getType() == 0) {
                    resul += element->getValue();

                } else if (element->getType() == 1) {

                    if (element->getValue() == "(")
                    {
                        operadores->push("(");
                    } else {
                        while (!operadores->isEmpty()) {
                            if (operadores->top() == "(") {
                                operadores->pop();
                                break;
                            } else {
                                resul += operadores->pop();
                            }
                        } 
                    }
                
                } else {

                    if (element->getValue() == "+" || element->getValue() == "-")
                    {
                        if (operadores->top() == "+" || operadores->top() == "-") {
                            resul += operadores->pop();
                            operadores->push(&element->getValue()[0]); 
                        } else if (operadores->top() == "(" || operadores->isEmpty()) {
                            operadores->push(&element->getValue()[0]);
                        } else {
                            while (!operadores->isEmpty()) {
                                if (operadores->top() == "(") {
                                    break;
                                } else {
                                    resul += operadores->pop();
                                }
                            } 
                            operadores->push(&element->getValue()[0]);      
                        }

                    } else if (element->getValue() == "*" || element->getValue() == "/") {
                        if (operadores->top() == "/" || operadores->top() == "*") {
                            resul += operadores->pop();
                            operadores->push(&element->getValue()[0]); 
                        } else if (operadores->top() == "(" || operadores->isEmpty()) {
                            operadores->push(&element->getValue()[0]);
                        } else {
                            operadores->push(&element->getValue()[0]); 
                        }
                    }
                       
                }
                  
            }
            while (!operadores->isEmpty())
            {
                if (operadores->top() != "(")
                {
                    resul += operadores->pop();
                } else
                {
                    operadores->pop();
                }
                
            }
            
            return resul;
        }
};

#endif