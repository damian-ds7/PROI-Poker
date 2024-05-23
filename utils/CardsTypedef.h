#pragma once
#include <memory>
#include "../src/Card/src/Card.h"
#include "../src/CardCollection/src/CardCollection.h"

typedef std::unique_ptr<CardCollection<std::unique_ptr<Card>>> Cards;

