# Powering the Hero

> ID: CF 1800C2 \
> Level: 1100

## Description

Given a deck of $n$ cards, each card has either 0 or a positive integer value.
For each positive integer value, we can either put the card on top of the deck
or discard it. For every card with value 0, we can take a card from the top of
the deck if the deck is not empty. Find the maximum sum of the values of the
cards that were selected from the 0-value cards.

## Solution

### Greedy Algorithm + Priority Queue

> Implementation: [C++ (78ms, 900KB)](./src/a.cpp)
