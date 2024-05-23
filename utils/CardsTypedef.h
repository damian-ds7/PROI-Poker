#pragma once
#include <memory>
#include "../src/Card/Card.h"
#include "../src/CardCollection/CardCollection.h"

typedef std::unique_ptr<CardCollection<std::unique_ptr<Card>>> Cards;

