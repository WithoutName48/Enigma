#include <string>

class Rotor
{
private:
    int turnover_limit;
    int turnover_number;
    const int single_shift;
    const std::string key_base;
    std::string key_actual;
    void RotateRotor(int);

public:
    Rotor(std::string key_base, std::string key_actual, int single_shift);
    void SetTurnoverLimit(int limit);
    void IncreaseTurnoverNumber();
    void SetRotor(int shift_key, int shift_turnover_limit);
    char ChiperChar(char c, bool before_reflector);
};
