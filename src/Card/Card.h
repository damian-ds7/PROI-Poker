#pragma once
#include "Suit.h"
#include "Value.h"
#include <string>

class Card {
    Suit m_suit;
    Value m_value;
    unsigned int index;
public:
    [[nodiscard]] Suit suit() const noexcept;
    [[nodiscard]] Value value() const noexcept;
    [[nodiscard]] unsigned int card_index() const noexcept;
    Card(Suit suit, Value value);
    ~Card() = default;
    bool operator==(const Card& other) const noexcept;
    bool operator!=(const Card& other) const noexcept;
    bool operator<(const Card& other) const noexcept;
    bool operator>(const Card& other) const noexcept;
    bool operator<=(const Card& other) const noexcept;
    bool operator>=(const Card& other) const noexcept;
    bool operator==(const Value& other) const noexcept;
    bool operator!=(const Value& other) const noexcept;
    bool operator<(const Value& other) const noexcept;
    bool operator>(const Value& other) const noexcept;
    bool operator<=(const Value& other) const noexcept;
    bool operator>=(const Value& other) const noexcept;
    std::string to_string() const noexcept;
};