#include <iostream>
#include "cstdio"
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
    double a=0,b=0,result=0;
    char operation=0;
    char buf[100];
    do {
        std::cout << "input operation a[+-*/]b:" << std::endl;
        std::string buffer;
        std::cin >> buffer;
        std::stringstream buffer_stream(buffer);
        buffer_stream >> a >> operation >> b;
        result = calc(a, b, operation);
        if (std::isnan(result))
            sprintf(buf, "Not correct operation on %.5f and %.5f", a, b);
        else sprintf(buf, "Result %f", result);
        std::cout << buf << std::endl;
    } while (std::isfinite(result));
}
