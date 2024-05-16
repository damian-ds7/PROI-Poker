#include "Card.h"

Suit Card::suit() const noexcept {
return m_suit;
}

Value Card::value() const noexcept {
return m_value;
}

Card::Card(Suit suit, Value value) : m_suit(suit), m_value(value) {};

bool Card::operator==(const Card& other) const noexcept {
return m_value == other.m_value;
}

bool Card::operator!=(const Card& other) const noexcept {
return !(*this == other);
}

bool Card::operator<(const Card& other) const noexcept {
return m_value < other.m_value;
}

bool Card::operator>(const Card& other) const noexcept {
return m_value > other.m_value;
}

bool Card::operator<=(const Card& other) const noexcept {
return m_value <= other.m_value;
}

bool Card::operator>=(const Card& other) const noexcept {
return m_value >= other.m_value;
}

bool Card::operator==(const Value& other) const noexcept {
return m_value == other;
}

bool Card::operator!=(const Value& other) const noexcept {
return m_value != other;
}

bool Card::operator<(const Value& other) const noexcept {
return m_value < other;
}

bool Card::operator>(const Value& other) const noexcept {
return m_value > other;
}

bool Card::operator<=(const Value& other) const noexcept {
return m_value <= other;
}

bool Card::operator>=(const Value& other) const noexcept {
return m_value >= other;
}
