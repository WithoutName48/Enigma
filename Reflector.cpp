#include "Reflector.h"

Reflector::Reflector(std::string pKey_base): key_base(pKey_base){
    key_actual = key_base;
}
void Reflector::ChangePair(char first_element, char second_element){
    for(int i=0; i<key_base.length(); i++){
        if(key_base[i] == first_element){
            key_actual[i] = second_element;
        }
        if(key_base[i] == second_element){
            key_actual[i] = first_element;
        }
    }
}
char Reflector::ChiperChar(char c){
    for(int i=0; i<key_base.length(); i++){
        if(c == key_base[i])
            return key_actual[i];
    }
}
