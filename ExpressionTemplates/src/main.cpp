/**
 * @file main.cpp
 * @date Mar 20, 2016
 * @author Mateusz Midor
 * @brief Expression Templates based on: "CppCon 2015_ Joel Falcou PART 1 “Expression Templates - Past, Present, Future”"
 */

#include <iostream>
#include <typeinfo>

using namespace std;


// "curiously recursive template pattern"
// this is used to cause early compiler error when trying to compose an invalid expressions, eg:
// auto expr = Terminal<int>{5} + 7
// (7 does not inherit from BaseExpression so it is not a valid operand)
template <class Derived>
struct BaseExpression {
	Derived const& self() const { return static_cast<const Derived&>(*this); }
	auto operator()() const { return self()(); }
};

// terminal: a box for a operand, eg. 3, 5.5
template <class T>
struct Terminal : public BaseExpression<Terminal<T>> {
	explicit Terminal(const T& value) : value(value) {}
	T operator()() const { return value; }
	T value;
};

// unary expression: one operand and a operation, eg "!op"
template <class Operation, class Operand>
struct UnaryExpression : public BaseExpression<UnaryExpression<Operation, Operand>> {
	explicit UnaryExpression(const Operand& operand) : operand(operand) {}
	auto operator()() const { return operation(operand()); }
	Operation operation;
	Operand operand;
};

// binary expression: two operands and a operation, eg "op1 + op2"
template <class Operation, class LeftOperand, class RightOperand>
struct BinaryExpression : public BaseExpression<BinaryExpression<Operation, LeftOperand, RightOperand>> {
	explicit BinaryExpression(const LeftOperand& lop, const RightOperand& rop) : lop(lop), rop(rop) {}
	auto operator()() const { return operation(lop(), rop()); }
	Operation operation;
	LeftOperand lop;
	RightOperand rop;
};

// mathematical "+" functor
struct OperationPlus {
	template <class E1, class E2>
	auto operator()(const E1 &e1, const E2 &e2) const { return e1 + e2; }
};

// mathematical "*" functor
struct OperationTimes {
	template <class E1, class E2>
	auto operator()(const E1 &e1, const E2 &e2) const { return e1 * e2; }
};

// provide "+" operator
template <class E1, class E2>
auto operator+(const BaseExpression<E1> &e1, const BaseExpression<E2> &e2)
{
	return BinaryExpression<OperationPlus, E1, E2>(e1.self(), e2.self());
}

// provide "*" operator
template <class E1, class E2>
auto operator*(BaseExpression<E1> const &e1, BaseExpression<E2> const &e2)
{
	return BinaryExpression<OperationTimes, E1, E2>(e1.self(), e2.self());
}

// main entry point
int main()
{
	auto t = Terminal<int> {4};
	auto expr = t + t * t;
	cout << "compound expression of d + d * d; where d = Terminal<int>{4}: \n\t" << typeid(expr).name() << endl;
	cout << "result of expression: \n\t" << expr() << endl;
}
