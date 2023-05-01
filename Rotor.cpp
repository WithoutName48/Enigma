#include "Rotor.h"

Rotor::Rotor(std::string pKey_base, std::string pKey_actual, int pSingleShift): key_base(pKey_base), key_actual(pKey_actual), single_shift(pSingleShift){
    turnover_number = 0;
    turnover_limit = 0;
}
void Rotor::SetTurnoverLimit(int limit){
    turnover_limit = limit;
}
void Rotor::IncreaseTurnoverNumber(){
    turnover_number+=single_shift;
    if(turnover_number >= turnover_limit){
        turnover_number-=turnover_limit;
        RotateRotor(single_shift);
    }
}
void Rotor::SetRotor(int shift_key, int shift_turnover_number){
    turnover_number+=shift_turnover_number;
    RotateRotor(shift_key);
}
void Rotor::RotateRotor(int shift){
    std::string key_new = "";
    for(int i=key_actual.length()-shift; i < key_actual.length(); i++){
        key_new += key_actual[i];
    }
    for(int i=0; i < key_actual.length()-shift; i++){
        key_new += key_actual[i];
    }
    key_actual = key_new;
}
char Rotor::ChiperChar(char c, bool before_reflector){
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
}
