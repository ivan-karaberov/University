/*2. Создать класс «Время» (часы, минуты).  
При выводе времени должна быть реализована возможность 
вывода в 24-х часовом и 12-ти часовом форматах. 
Должна быть выполнена проверка ввода данных.*/

#define DEBUG

#include <iostream>

class Time{
private:
    int hour;
    int min;
    int sec;
public:
    Time(){
        hour = 0;
        min = 0;
        sec = 0;
    }

    int SetTime(int hour, int min, int sec, int format){
        /*
        24 часовой формат - 0
        12 часовой формат:
            1 - am
            2 - pm
        */
        switch(format){
            case 0: {
                if((hour >= 0 && hour <= 24) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60)){
                    this->hour = hour;
                    this->min = min;
                    this->sec = sec;
                } else{
                    std::cout << "Error: Incorrect Time" << std::endl;
                    return -1; 
                } 
                break;
            }; 
            case 1: {
                if((hour >= 0 && hour <= 12) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60)){
                    this->hour = hour;
                    this->min = min;
                    this->sec = sec;
                } else{
                    std::cout << "Error: Incorrect Time" << std::endl;
                    return -1; 
                } 
                break;
            };
            case 2: {
                if((hour >= 0 && hour <= 12) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60)){
                    this->hour = 12+hour;
                    this->min = min;
                    this->sec = sec;
                } else{
                    std::cout << "Error: Incorrect Time" << std::endl;
                    return -1; 
                } 
                break;
            };
            default: std::cout << "Error: Incorrect Format" << std::endl; return -1;
        }
        return 0;
    }

    void Print(int format){
        char aop; // am or pm
        int tmp;

        if(format){
            if (this->hour > 12){
                aop = 'p';
                tmp = this->hour % 12;
                if(tmp == 0) tmp = 12;
            } else{
                aop = 'a';
                tmp = this->hour;
            }

            std::cout << tmp << ":" << min << ":" << sec << " " << aop << 'm' << std::endl;
        } else{
            std::cout << hour << ":" << min << ":" << sec << std::endl;
        }
    }


};

int main(void){

    #ifdef DEBUG
    Time t, b, c, d, a, f;
    std::cout << "1: " << std::endl;
    t.SetTime(24,15,85,0);
    t.Print(0);
    t.Print(1);
    std::cout << "2: " << std::endl;
    b.SetTime(24,60,20,0);
    b.Print(0);
    b.Print(1);
    std::cout << "3: " << std::endl;
    c.SetTime(24,15,15,0);
    c.Print(0);
    c.Print(1);
    std::cout << "4: " << std::endl;
    d.SetTime(21,15,15,1);
    d.Print(0);
    d.Print(1);
    std::cout << "5: " << std::endl;
    a.SetTime(12,15,05,2);
    a.Print(0);
    a.Print(1);
    std::cout << "6: " << std::endl;
    f.SetTime(12,15,05,1);
    f.Print(0);
    f.Print(1);
    #endif

    return 0;
}