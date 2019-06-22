#ifndef FUNCOESUTEIS_H
#define FUNCOESUTEIS_H

#include <string>


std::string removeChar(std::string palavra);
bool tamanhoMinimo(std::string palavra);
bool palavraAcentuada(std::string palavra);
bool valueVogais(std::string palavra);

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

bool tamanhoMinimo(std::string palavra){
    return palavra.size() >= 3;
}

bool palavraAcentuada(std::string palavra){
    return palavra.front() == -61;
}

bool valueVogais(std::string palavra){
    return true;
}


#endif