#include <string>
#include <iostream>
using namespace std;

class Phone
{
public:
    string brand, model, form, year, screen, price;
};

class PhoneShop
{
private:
    Phone* phones = new Phone[1];
    int numberOfPhones = 0;

public:
    void AddPhone(Phone phoneToAdd)
    {
        phones[numberOfPhones].brand = phoneToAdd.brand;
        phones[numberOfPhones].model = phoneToAdd.model;
        phones[numberOfPhones].form = phoneToAdd.form;
        phones[numberOfPhones].year = phoneToAdd.year;
        phones[numberOfPhones].screen = phoneToAdd.screen;
        phones[numberOfPhones].price = phoneToAdd.price;

        numberOfPhones++;

        std::cout << phones[numberOfPhones].model;
    }
    void DeletePhone(string modelToDelete)
    {
        for (auto i = 0; i < numberOfPhones; ++i)
        {
            if (phones[i].model == modelToDelete)
            {
                phones[i] = Phone();
                phones[i].model = "EMPTY";
                numberOfPhones--;
            }
        }
    }

    void ClearTable()
    {
        Phone* copyOfPhones = new Phone[numberOfPhones];
        for (int i = 0; i < numberOfPhones; ++i)
        {
            if (phones[i].model == "EMPTY")
            {
                copyOfPhones[i] = phones[i];
            }
        }

        phones = new Phone[numberOfPhones];

        for (int i = 0; i < numberOfPhones; ++i)
        {
            phones[i] = copyOfPhones[i];
        }
        delete[]copyOfPhones;
    }
    void Report()
    {
        for (int i = 0; i < numberOfPhones; ++i)
        {
            std::cout << phones[i].model << std::endl;
            std::cout << phones[i].brand << std::endl;
            std::cout << phones[i].form << std::endl;
            std::cout << phones[i].year << std::endl;
            std::cout << phones[i].screen << std::endl;
            std::cout << phones[i].price << std::endl;
        }
    }

};

int main()
{
    PhoneShop shop;
    string c = "1";

    do
    {
        cout << "1) Adding a phone" << endl;
        cout << "2) Deleting a phone" << endl;
        cout << "3) Reports" << endl;
        cout << "4) Exit" << endl;
        cout << "\nPlease enter your choice in number:";
        cin >> c;
        cout << endl;
        std::cout << c << std::endl;

        Phone newPhone;

        cout << "\nBrand name : ";
        cin >> newPhone.brand;
        cout << "\nModel name: ";
        cin >> newPhone.model;
        cout << "\nForm factor: ";
        cin >> newPhone.form;
        cout << "\nYear of issue: ";
        cin >> newPhone.year;
        cout << "\nScreen size: ";
        cin >> newPhone.screen;
        cout << "\nPrice: ";
        cin >> newPhone.price;
        if (c == "1")
            shop.AddPhone(newPhone);
        if (c == "2")
            shop.DeletePhone(newPhone.model);
        if (c == "3")
            shop.Report();
        cout << " Phone added!" << endl;
    } while (c == "4");

}