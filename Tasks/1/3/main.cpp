/*
    3.Создать класс «Контакт» (ФИО, телефон, e-mail).
*/

#include <iostream>
#include <string>

class Contact{
private:
    std::string number;
    std::string name;
    std::string secondName;
    std::string lastName;
    std::string email;

public:
    void createContact(std::string number, std::string name, std::string secondName, std::string lastName, std::string email){
        this->number = number;
        this->name = name;
        this->secondName =secondName;
        this->lastName = lastName;
        this->email = email;
    }

    std::string getName(){
        return name;
    }

    std::string getSecondName(){
        return secondName;
    }

    std::string getLastName(){
        return lastName;
    }

    std::string getEmail(){
        return email;
    }

    std::string getNumber(){
        return number;
    }

};

int main(void){
    Contact one;
    one.createContact("+79302475898", "Alex", "Alexeevich", "Alexeenko", "alex@gmail.com");
    std::cout << one.getLastName() << " " << one.getName() << " " << one.getSecondName() << " " << one.getNumber() << std::endl;
    return 0;
}