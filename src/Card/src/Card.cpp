#include "Card.h"

Suit Card::suit() const noexcept {
    return m_suit;
}

Value Card::value() const noexcept {
    return m_value;
}

unsigned int Card::card_index() const noexcept {
    return index;
}

Card::Card(Suit suit, Value value) : m_suit(suit), m_value(value) {
    index = 4 * static_cast<int>(m_value) + static_cast<int>(m_suit);
};

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
