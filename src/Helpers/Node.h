#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <list>
#include <iostream>
#include <memory>
#include <boost/dynamic_bitset.hpp>

#include "GraphColor.h"

#define UNCOLORED -1

class Node {
    std::vector<int> _adjV;
    int _self;
    int _color;

public:
    explicit Node(int self, int color = UNCOLORED);

    void addEdge(int v2);

    [[nodiscard]] const std::vector<int> &getAdjV() const;

    [[nodiscard]] int getColor() const;

    [[nodiscard]] int getSelf() const;

    [[nodiscard]] unsigned int getDegree() const;

    [[nodiscard]] unsigned int getDegree(const boost::dynamic_bitset<> &vMap) const;

    [[nodiscard]] unsigned int getDegree(const std::vector<char> &vMap) const;

    void setColor(int color);
};


#endif 