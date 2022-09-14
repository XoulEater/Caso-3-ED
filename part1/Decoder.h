#include <../List.h>
#include <string>

class Decoder
{
    private:
        List<Token>* elements = new List<Token>();

    public:
        List<Token>* decodeString(string operacion) {
            string character = "";
            int count = 0;
            while (operacion.size() > count)
            {    
                character = ""; 
                character.push_back(operacion[count]);       
                if (operacion[count] > 47 && operacion[count] < 58) {
                    Token* element = new Token(0, character);
                    elements->add(element);
                } else if (operacion[count] == 40 || operacion[count] == 41){
                    Token* element = new Token(1, character);
                    elements->add(element);
                } else {
                    Token* element = new Token(2, character);
                    elements->add(element);
                    }
                
                
                count ++;
            }
            return elements;
        }
};