#include <string>

class Reflector
{
private:
    const std::string key_base;
    std::string key_actual;

public:
    Reflector(std::string key_base);
    void ChangePair(char first_element_of_pair, char second_element_to_change);
    char ChiperChar(char c);
};
