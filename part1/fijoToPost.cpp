
#include <Token.h>
#include <Converter.h>
#include <Decoder.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Decoder* Decodificador = new Decoder();
    Converter* Conversor = new Converter();

    string operacion = "2+4/5*";

    List<Token>* operacionDeco = Decodificador->decodeString(operacion);
    operacion = Conversor->Convert(operacionDeco);
    cout << operacion;
}