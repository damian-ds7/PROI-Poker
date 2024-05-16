#pragma once

enum class Suit{
    Spades,
    Hearts,
    Diamonds,
    Clubs
};

enum class Value{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card {
    Suit m_suit;
    Value m_value;
public:
    [[nodiscard]] Suit suit() const noexcept;
    [[nodiscard]] Value value() const noexcept;
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
};