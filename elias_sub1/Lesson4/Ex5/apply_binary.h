//
// Created by Elias on 01.11.16.
//

#include <functional>

#ifndef EX4_APPLY_BINARY_H
#define EX4_APPLY_BINARY_H

using namespace std;

template <class BinOp, class Op1, class Op2>
class apply_binary :
public unary_function<typename Op1::argument_type,
                      typename BinOp::result_type> {
protected:
  BinOp o; Op1 o1; Op2 o2;
public:
apply_binary(BinOp binop, Op1 op1, Op2 op2)
: o(binop), o1(op1), o2(op2) {}
typename BinOp::result_type
operator()(const typename Op1::argument_type &x) {
    return o(o1(x),o2(x));
  }
};
#endif //EX4_APPLY_BINARY_H
