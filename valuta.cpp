#include <iostream>

using namespace std;

class Currecy
{
public:
    virtual unsigned int GetCurse()
    {
        return 1;
    }
};

class Dollar
{
public:
    unsigned int GetCurseDollars()
    {
        return 76;
    }
};

class Euro
{
public:
    unsigned int GetCurseEuro()
    {
        return 90;
    }
};

class Pound
{
public:
    unsigned int GetCursePound()
    {
        return 105;
    }
};


class ConvertorDollarToRubl : public Currecy, public Dollar
{
public:
    unsigned int GetCurse() override
    {
        return GetCurseDollars();
    }
};


class ConvertorEuroToRubl : public Currecy, public Euro
{
public:
    unsigned int GetCurse() override
    {
        return GetCurseEuro();
    }
};


class ConvertorPoundToRubl : public Currecy, public Pound
{
public:
    unsigned int GetCurse() override
    {
        return GetCursePound();
    }
};


void GetCource(Currecy* currency)
{
    cout << "Расчет будет производится по курсу "
        << currency->GetCurse()
        << " рублей за валюту\n";
}


int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Добро пожаловать в магазин" << endl;
    cout << "Ваша локация - РФ\nРасчет производится в рублях по текущему курсу" << endl;

    Currecy* rubl = new Currecy;
    GetCource(rubl);

    cout << "\nТеперь цены указаны в долларах\n";
    Currecy* bank = new ConvertorDollarToRubl();
    GetCource(bank);

    cout << "\nТеперь цены указаны в евро\n";
    Currecy* euro = new ConvertorEuroToRubl();
    GetCource(euro);

    cout << "\nТеперь цены указаны в фунтах стерлингов\n";
    Currecy* pound = new ConvertorPoundToRubl();
    GetCource(pound);

    delete rubl;
    delete bank;
    delete euro;
    delete pound;

    return 0;

}
