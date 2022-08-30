#include <iostream>
#include "sstream"
#include "cmath"

double epsylon=0.000001;

double calc(double a,double b,char op){
    if(op=='+')return a+b;
    else if (op=='-') return a-b;
    else if (op=='*') return a*b;
    else if (op=='/'&&(b>epsylon||b<-epsylon)) return a/b;
    else return NAN;
}
int main() {
    double a=0,b=0,result;
    char operation=0;
    do {
        std::cout << "input operation a[+-*/]b:" << std::endl;
        std::string buffer;
        std::cin >> buffer;
        std::stringstream buffer_stream(buffer);
        buffer_stream >> a >> operation >> b;
        result = calc(a, b, operation);
        buffer_stream.clear();
        if (std::isnan(result))
            buffer_stream <<"Not correct operation on "<<a <<" and "<< b;
        else buffer_stream << "Result " <<result;
        std::cout << buffer_stream.str() << std::endl;
    } while (std::isfinite(result));
}
