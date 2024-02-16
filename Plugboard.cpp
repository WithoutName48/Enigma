#include "Plugboard.h"

Plugboard::Plugboard(std::string pKey_base): key_base(pKey_base){
    key_actual = key_base;
}
void Plugboard::ChangePair(char first_element, char second_element){
    for(int i=0; i<key_base.length(); i++){
        if(key_base[i] == first_element){
            key_actual[i] = second_element;
        }
        if(key_base[i] == second_element){
            key_actual[i] = first_element;
        }
    }
}
char Plugboard::ChiperChar(char c, bool before_reflector){
    if(before_reflector){
        for(int i=0; i<key_base.length(); i++){
            if(c==key_base[i])
                return key_actual[i];
        }
    }
    else{
        for(int i=0; i<key_actual.length(); i++){
            if(c==key_actual[i])
                return key_base[i];
        }
    }
    return ' ';
}