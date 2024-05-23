#pragma once

enum class Suit{
    Spades,
    Hearts,
    Diamonds,
    Clubs
};

enum class Value{
    Two,
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
};