#include <string>
bool tamanhoMinimo(std::string palavra){
    return palavra.size() >= 3;
}

bool acentoInicio(std::string palavra){
    return palavra.front() == -61;
}

bool acentoFim(std::string palavra){
    if(palavra.back() == -61){
        //std::cout << palavra << "\n";
    }
    return palavra.back() == -61;
}

bool charEspecial(std::string palavra, int op){
    int array[] = {-61, -95, -77, -87, -70, -76, -93};
    if(op == 1){
        for(int i = 0; i < 6; i++){
            if(palavra.front() == array[i]){
               return true;
            }
        } 
    }else{
        for(int i = 0; i < 6; i++){
            int j = palavra.back();
            /*if(j == -61){
                std::cout << "é esse mesmo: " << palavra << "\n";
            }*/            
            if(palavra.back() == array[i]){
               return true;
            }
        } 
    }
    return false;
}

std::string removeChar(std::string palavra) {
    bool fim = false;
    while(!fim){
        //std::cout << palavra << " =\n"; |\*',"!@#$%*()¬¢£\_-§+=`´{}ªº]}°/?:;.>,<
        if(tamanhoMinimo(palavra)){
            if(palavra.front() >= 97 && palavra.front() <= 122 ){
            }else{
                if(!charEspecial(palavra, 1)){
                    palavra.erase(palavra.begin());
                    continue;
                }
            }

            if(palavra.back() >= 97 && palavra.back() <= 122 ){
            }else{
                //std::cout << "como era: " << palavra << "\n";
                if(!charEspecial(palavra, 2)){
                    palavra.erase(palavra.end()-1);
                    int i = palavra.back();
                    //std::cout << "como ficou: " << palavra << " " << i <<  "\n";
                    continue;
                }
            }
        }
        fim = true;
    }
    return palavra;
}

