#ifndef AST_H
#define AST_H

#include <string>
#include <unordered_map>
#include <list>
#include <ostream>

using namespace std;

class Visitor; 

// Operadores binarios soportados
enum BinaryOp { 
    PLUS_OP, 
    MINUS_OP, 
    MUL_OP, 
    DIV_OP,
    POW_OP
};

// Clase abstracta Exp
class Exp {
public:
    virtual int  accept(Visitor* visitor) = 0;
    virtual ~Exp() = 0;  // Destructor puro → clase abstracta
    static string binopToChar(BinaryOp op);  // Conversión operador → string
};

// Expresión binaria
class BinaryExp : public Exp {
public:
    Exp* left;
    Exp* right;
    BinaryOp op;
    int accept(Visitor* visitor);
    BinaryExp(Exp* l, Exp* r, BinaryOp op);
    ~BinaryExp();
};

// Expresión numérica
class NumberExp : public Exp {
public:
    int value;
    int accept(Visitor* visitor);
    NumberExp(int v);
    ~NumberExp();
};

class IdExp : public Exp {
public:
    string value;
    int accept(Visitor* visitor);
    IdExp(string v);
    ~IdExp();
};

// Raiz cuadrada
class SqrtExp : public Exp {
public:
    Exp* value;
    int accept(Visitor* visitor);
    SqrtExp(Exp* v);
    ~SqrtExp();
}
;
class Stm{
public:
    virtual int  accept(Visitor* visitor) = 0;
    virtual ~Stm() = 0;  
};
class AssignStm: public Stm{
public:
    string id;
    Exp* rhs;
    int accept(Visitor* visitor);
    AssignStm(string , Exp* );
    ~AssignStm();
};

class PrintStm: public Stm{
public:
    list<Exp*> e;
    int accept(Visitor* visitor);
    PrintStm(list<Exp*>);
    ~PrintStm();
};

class Program{
public:
    list<Stm*> slist;
    int accept(Visitor* visitor);
    Program();
    ~Program();
}
;

class RandExp : public Exp {
public:
    Exp* e1;
    Exp* e2;
    int accept(Visitor* visitor);
    RandExp(Exp* e1,Exp* e2);
    ~RandExp();
};

class MinExp : public Exp {
public:
    list<Exp*> e;
    int accept(Visitor* visitor);
    MinExp(list<Exp*> e);
    ~MinExp();
};

class StrExp : public Exp {
public:
    string val;
    int accept(Visitor* visitor);
    StrExp(string v);
    ~StrExp();
};


#endif // AST_H


