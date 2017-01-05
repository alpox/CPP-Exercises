#include <iostream>
#include <sstream>

using namespace std;

struct Form{
    int prc;
    ios_base::fmtflags fmt;

    Form(int p = 6) : prc(p){
    }

    Form& scientific(){
        fmt = ios_base::scientific;
        return *this;
    }

    Form& precision(int p) {
        prc = p;
        return *this;
    }

    string operator()(double value){
        stringstream ss;
        ss.setf(fmt, ios_base::floatfield);
        ss.precision(prc);
        ss << value;
        string myString = ss.str();
        return myString;
    }
};

ostream& operator<<(ostream& os, const Form &f){
    os.setf(f.fmt, ios_base::floatfield);
    os.precision(f.prc);
    return os;
}

void f(double d){
    Form gen4(4);
    Form sci8 = gen4;
    sci8.scientific();
    cout << gen4(d) << " back to old option: " << d << endl;
}

int main() {
    f(1./3);
    return 0;
}