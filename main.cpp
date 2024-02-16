#include <iostream>
#include <string>
#include <math.h>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;

const string key_base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    string r1_key = "XYHGQJWINCMAOPRLVKSBDFZTUE";
    string r2_key = "LDCRWFZXKAIPOYHGNVBMQEUSJT";
    string r3_key = "NAMZGLOQPDBHVTCYUEIFRXKSJW";
    string r4_key = "HPOQZDTRUEJVKLCBANGWFSIXMY";
    string r5_key = "PGKQZNDRYFUALSMBWXJTEOCIVH";
    Rotor *tabRotors[5];
    tabRotors[0] = new Rotor(key_base, r1_key, 1);
    tabRotors[1] = new Rotor(key_base, r2_key, 1);
    tabRotors[2] = new Rotor(key_base, r3_key, 1);
    tabRotors[3] = new Rotor(key_base, r4_key, 1);
    tabRotors[4] = new Rotor(key_base, r5_key, 1);

    // cout << "Dostepnych jest 5 roznych wirnikow. Wybierz 3 z nich i podaj ich kolejnosc (numer wirnika - od 1 do 5 wlcznie) oddzielajac je spacja." << endl;
    // cout << "Podaj kolejnosc wirnikow: " << endl;
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    num1--;
    num2--;
    num3--;
    tabRotors[num1]->SetTurnoverLimit(pow(key_base.length(), 0));
    tabRotors[num2]->SetTurnoverLimit(pow(key_base.length(), 1));
    tabRotors[num3]->SetTurnoverLimit(pow(key_base.length(), 2));

    // cout << "Podaj poczatkowe ustawienie wirnikow (liczba od 1 do 26 wlacznie): " << endl;
    int rt1_settings, rt2_settings, rt3_settings;
    cin >> rt1_settings >> rt2_settings >> rt3_settings;
    tabRotors[num1]->SetRotor(rt1_settings, 0);
    tabRotors[num2]->SetRotor(rt2_settings, rt1_settings);
    tabRotors[num3]->SetRotor(rt3_settings, key_base.length() * rt2_settings + rt1_settings);

    Reflector *rf = new Reflector(key_base);
    // cout << "Podaj ustawienie Reflector. Najpierw podaj pierwszy element pary, a potem nastepny (nie oddzielaj ich spacja). Kazda pare oddziel spacja. Ciag par mozesz zakonczyc wpisujac '0'. " << endl;
    string rf_settings;
    cin >> rf_settings;
    while (rf_settings != "0")
    {
        rf->ChangePair(toupper(rf_settings[0]), toupper(rf_settings[1]));
        cin >> rf_settings;
    }

    Plugboard *pb = new Plugboard(key_base);
    // cout << "Podaj ustawienie Plugboard. Najpierw podaj pierwszy element pary, a potem nastepny (nie oddzielaj ich spacja). Kazda pare oddziel spacja. Ciag par mozesz zakonczyc wpisujac '0'. " << endl;
    string pb_settings;
    cin >> pb_settings;
    while (pb_settings != "0")
    {
        pb->ChangePair(toupper(pb_settings[0]), toupper(pb_settings[1]));
        cin >> pb_settings;
    }

    // cout << "Wpisz tekst do odszyfrowania lub zaszyfrowania, aby zakonczyc dzialanie programu wpisz '0': " << endl;
    cin.get();
    string text;
    getline(cin, text, '\n');
    while (text != "0")
    {
        // Encryption and Decryption
        for (int i = 0; i < (int)text.length(); i++)
        {
            char c = text[i];
            if (!isalpha(c))
                continue;
            c = toupper(c);
            c = pb->ChiperChar(c, true);
            c = tabRotors[num1]->ChiperChar(c, true);
            c = tabRotors[num2]->ChiperChar(c, true);
            c = tabRotors[num3]->ChiperChar(c, true);
            c = rf->ChiperChar(c);
            c = tabRotors[num3]->ChiperChar(c, false);
            c = tabRotors[num2]->ChiperChar(c, false);
            c = tabRotors[num1]->ChiperChar(c, false);
            c = pb->ChiperChar(c, false);
            text[i] = c;
            // Preparation for next char
            tabRotors[num1]->IncreaseTurnoverNumber();
            tabRotors[num2]->IncreaseTurnoverNumber();
            tabRotors[num3]->IncreaseTurnoverNumber();
        }
        // cout << "Po szyfrowaniu/odszyfrowaniu: " << endl;
        cout << text << endl;
        getline(cin, text, '\n');
    }
    return 0;
}
