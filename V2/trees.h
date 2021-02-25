#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

#pragma once


class Node{
public:
    virtual ~Node();
    char ch;
    int freq;
    Node *left, *right;
};