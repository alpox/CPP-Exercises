#include <iostream>

using namespace std;

struct Form{
    int prc;
    ios_base::fmtflags fmt;
    ostream& formatStream;

    Form(ostream& os = cout, int p = 6) : formatStream(os), prc(p){
    }

    Form& scientific(){
        fmt = ios_base::scientific;
        return *this;
    }

    Form& precision(int p) {
        prc = p;
        return *this;
    }

    ostream& operator()(double value){
        formatStream.setf(fmt, ios_base::floatfield);
        formatStream.precision(prc);
        formatStream << value;
        return formatStream;
    }

    ~Form(){
        formatStream.unsetf(ios_base::floatfield);
        formatStream.precision(6);
    }
};

ostream& operator<<(ostream& os, const Form &f){
    os.setf(f.fmt, ios_base::floatfield);
    os.precision(f.prc);
    return os;
}

Form gen4(cout, 4);
void f(double d){
    Form sci8 = gen4;
    sci8.scientific().precision(8);
    cout << gen4(d) << " back to old options: " << d << endl;
}

int main() {
    f(1./3);
    return 0;
}