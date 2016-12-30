#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class BinOp, class Op1, class Op2>
class somefunction_t:public std::unary_function<typename Op1::argument_type, typename BinOp::result_type> {
protected:
    BinOp o;
    Op1 o1;
    Op2 o2;
public:
    somefunction_t(BinOp binop, Op1 op1, Op2 op2): o(binop), o1(op1), o2(op2) {}
    typename BinOp::result_type operator()(const typename Op1::argument_type &x) {
        return o(o1(x), o2(x));
    }
};

template<typename BinOp,typename UnOp1,typename UnOp2>
somefunction_t<BinOp,UnOp1,UnOp2> func(const BinOp &binop,const UnOp1 &unop1,const UnOp2 &unop2){
    return somefunction_t<BinOp,UnOp1,UnOp2>(binop, unop1, unop2);
};

int main() {
    cout << func(multiplies<int>(),negate<int>(),negate<int>())(5);
    return 0;
}