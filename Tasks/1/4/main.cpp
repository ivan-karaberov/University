/*
4.	Создать класс «Адрес» (город,  улицу, номер дома, квартиры/офиса).
*/

#include <iostream>
#include <string>

class Adress{
private:
    std::string city;
    std::string street;
    std::string homeNumber;
    std::string kvartira;

public:
    void setAdress(std::string city, std::string street, std::string homeNumber, std::string kvartira){
        this->city = city;
        this->street = street;
        this->homeNumber = homeNumber;
        this->kvartira = kvartira;
    }
    std::string getCity(){
        return city;
    }
    std::string getStreet(){
        return street;
    }
    std::string getHomeNumber(){
        return homeNumber;
    }
    std::string getKvartira(){
        return kvartira;
    }
};

int main(void){
    Adress one;
    one.setAdress("Nizhniy Novgorod", "Minina", "21", "17");
    std::cout << one.getCity() << " " << one.getStreet() << " " << one.getHomeNumber() << " " << one.getKvartira() << std::endl;
    return 0;
}