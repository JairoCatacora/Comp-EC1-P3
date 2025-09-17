#include "ast.h"

#include <complex.h>
#include <iostream>

using namespace std;

// ------------------ Exp ------------------
Exp::~Exp() {}

string Exp::binopToChar(BinaryOp op) {
    switch (op) {
        case PLUS_OP:  return "+";
        case MINUS_OP: return "-";
        case MUL_OP:   return "*";
        case DIV_OP:   return "/";
        case POW_OP:   return "**";
        default:       return "?";
    }
}

// ------------------ BinaryExp ------------------
BinaryExp::BinaryExp(Exp* l, Exp* r, BinaryOp o)
    : left(l), right(r), op(o) {}

    
BinaryExp::~BinaryExp() {
    delete left;
    delete right;
}



// ------------------ NumberExp ------------------
NumberExp::NumberExp(int v) : value(v) {}

NumberExp::~NumberExp() {}


// ------------------ SqrtExp ------------------
SqrtExp::SqrtExp(Exp* v) : value(v) {}

SqrtExp::~SqrtExp() {}

///////////////////////////////////////////////
Program::Program(){}
Program::~Program(){}
Stm::~Stm(){}
PrintStm::PrintStm(list<Exp*> e1){
    e=e1;
}

PrintStm::~PrintStm(){}
AssignStm::AssignStm(string id1, Exp* rhs1){
    id = id1;
    rhs=rhs1;
}
AssignStm::~AssignStm(){}

IdExp::IdExp(string v) {
    value=v;
}
IdExp::~IdExp() {
}

RandExp::RandExp(Exp* e1,Exp* e2): e1(e1), e2(e2) {};
RandExp::~RandExp() {}

MinExp::MinExp(list<Exp*> e): e(e) {};
MinExp::~MinExp() {}

StrExp::StrExp(string v): val(v) {};
StrExp::~StrExp() {}
