#pragma once
#include <memory>
#include "Card.h"
#include "CardCollection.h"

typedef std::unique_ptr<CardCollection<std::unique_ptr<Card>>> Cards;

