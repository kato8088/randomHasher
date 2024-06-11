#include <iostream>
#include <string>
#include <stdlib.h>
#include <sha.h>
#include <hex.h>
#include <filters.h>
#include <cryptlib.h>
//#pragma comment(lib, "cryptlib.lib")  // Adicione esta linha para garantir que o linker use a biblioteca correta

using namespace std;
using namespace CryptoPP;

void GenerateSHA256Hash(const string& input, string& output) {
    // Definindo o objeto SHA256
    SHA256 hash;

    // Definindo o objeto StringSource
    StringSource(input, true,
        new HashFilter(hash,
            new HexEncoder(
                new StringSink(output)
            ) // HexEncoder
        ) // HashFilter
    ); // StringSource
}

string RandomString(int lenght)
{
      string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
 //   string charset = "0123456789abcdefghijklmnopqrstuvwxyz";
    string rstring;
    int pos;
    while (rstring.size() != lenght) {
        pos = ((rand() % (charset.size() - 1)));
        rstring += charset.substr(pos, 1);
    }
    return rstring;
}

int main() {
    
    srand(time(0));
    
    int randomStringSize;
    cout << "insira o tamanho da string: ";
    cin >> randomStringSize;

    string randomStringOut = RandomString(randomStringSize);
    string SHA256_out;
    
    GenerateSHA256Hash(randomStringOut, SHA256_out);

    cout << endl << "Hash SHA-256: " << SHA256_out << endl;
    cout << endl << "string original: " << randomStringOut;

    return 0;
}
