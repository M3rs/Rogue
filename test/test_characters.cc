#include <iostream>
#include <typeinfo>
#include <ncurses.h>

#define PRINT_NAME(x) std::cout << #x << " - " << typeid(x).name() << '\n'

int main() {

	auto x = ACS_VLINE;	

	std::cout << typeid(x).name() << "\n";

	    PRINT_NAME(char);
    PRINT_NAME(signed char);
    PRINT_NAME(unsigned char);
    PRINT_NAME(short);
    PRINT_NAME(unsigned short);
    PRINT_NAME(int);
    PRINT_NAME(unsigned int);
    PRINT_NAME(long);
    PRINT_NAME(unsigned long);
    PRINT_NAME(float);
    PRINT_NAME(double);
    PRINT_NAME(long double);
    PRINT_NAME(char*);
    PRINT_NAME(const char*);

}

