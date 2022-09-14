#include <string>

#ifdef TOKEN

#define TOKEN 1

using namespace std;

class Token {
    private:
        int type;
        string value;
    public:
        Token (int Ptype, string Pvalue) {
            type = Ptype;
            value = Pvalue;
        }
    
    int getType() {
        return type;
    }

    string getValue() {
        return value;
    }
};

#endif

