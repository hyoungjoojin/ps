# 스타트 택시

> ID: BOJ 19238 \
> Level: Gold 2

## Description

Given a grid of walls and empty spaces, we simulate a taxi that has to pick up
and drop off passengers. The taxi starts with a certain amount of fuel, and it
consumes fuel as it moves. The taxi can only pick up one passenger at a time,
and it must drop off the passenger at their destination before picking up
another one. The goal is to determine if the taxi can successfully pick up and
drop off all passengers without running out of fuel.

## Solution

### BFS

> Implementation: [C++ (4ms, 2724KB)](./src/a.cpp)
