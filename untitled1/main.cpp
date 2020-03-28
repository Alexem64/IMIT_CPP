#include <iostream>
#include <string>

int string_to_number(const std::string& s) {
    int stn=0;
    int base=1;
    int val=0;

    for (int  i=0; i<s.size()-1; i++) {
        if (s.at(i)=='-') continue;
        base*=10;
    }
        for (int  i=0; i<s.size(); i++)  {
                    if (s.at(i)=='-') continue;
           if (s.at(i) == '0') val = 0;
            if (s.at(i) == '1') val = 1;
            if (s.at(i) == '2') val = 2;
            if (s.at(i) == '3') val = 3;
            if (s.at(i) == '4') val = 4;
            if (s.at(i) == '5') val = 5;
            if (s.at(i) == '6') val = 6;
            if (s.at(i) == '7') val = 7;
            if (s.at(i) == '8') val = 8;
            if (s.at(i) == '9') val = 9;


            stn+=val*base;
            base/=10;
            std::cout << "VAL: " << val << std::endl << "s[i]: " << s.at(i) << std::endl << "i: " << i << std::endl;
        }
        if (s[0]=='-')  return stn*(-1); else return stn;

    //        std::cout << "i: " << i << std::endl << "s[i]: " << s.at(i) << std::endl;
    //    }
        }

int main()
{

    std::cout << "Input a keyboard character: "; // предположим, что пользователь ввёл abcd

    std::string ch;
    std::cin >> ch;
    std::cout << string_to_number(ch)  << " - number"<< std::endl;

    return 0;
}