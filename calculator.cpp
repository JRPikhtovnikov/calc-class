#include "calculator.h"
#include <iostream>

Calculator::Calculator() : current_result_(0), memory_(std::nullopt) {}

void Calculator::Set(Number n) {
    current_result_ = n;
}

Calculator::Number Calculator::GetNumber() const {
    return current_result_;
}

void Calculator::Add(Number n) {
    current_result_ += n;
}

void Calculator::Sub(Number n) {
    current_result_ -= n;
}

void Calculator::Div(Number n) {
    if (n == 0) {
        current_result_ = std::numeric_limits<Number>::infinity();
    }
    else {
        current_result_ /= n;
    }
}

void Calculator::Mul(Number n) {
    current_result_ *= n;
}

void Calculator::Pow(Number n) {
    current_result_ = std::pow(current_result_, n);
}

void Calculator::Save() {
    memory_ = current_result_;
}

void Calculator::Load() {
    if (!memory_) {
        std::cerr << "Error: Memory is empty";
    }
    current_result_ = *memory_;
}

bool Calculator::HasMem() const {
    return memory_.has_value();
}

std::string Calculator::GetNumberRepr() const {
    return std::to_string(current_result_);
}
