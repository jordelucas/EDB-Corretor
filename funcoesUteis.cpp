#include <string>
bool tamanhoMinimo(std::string palavra){
    return palavra.size() >= 3;
}

bool palavraAcentuada(std::string palavra){
    return palavra.front() == -61;
}

std::string removeChar(std::string palavra) {
    while((palavra.front() < 97 && palavraAcentuada(palavra) == false) || palavra.front() > 122 || palavra.back() < 97 || palavra.back() > 122){
        if(tamanhoMinimo(palavra)){
            if((palavra.front() < 97 && palavraAcentuada(palavra) == false) || palavra.front() > 122) {
                palavra.erase(palavra.begin());
            }
            if(palavra.back() < 97 || palavra.back() > 122) {
                palavra.pop_back();
            }
        }else{
            return palavra;
        }
    }
    return palavra;
}