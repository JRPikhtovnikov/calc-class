#pragma once
#include <string>
#include <optional>
#include <cmath>
#include <stdexcept>

class Calculator {
public:
    using Number = double;

    Calculator();

    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);

    void Save();
    void Load();
    bool HasMem() const;

    std::string GetNumberRepr() const;

private:
    Number current_result_;
    std::optional<Number> memory_;
};
