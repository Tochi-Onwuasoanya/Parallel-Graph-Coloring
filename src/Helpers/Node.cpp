#include "Node.h"

Node::Node(int self, int color) : _self(self), _color(color) {}

void Node::addEdge(int v2) {
    _adjV.push_back(v2);
}

const std::vector<int> &Node::getAdjV() const {
    return _adjV;
}

int Node::getColor() const {
    return _color;
}

int Node::getSelf() const {
    return _self;
}

void Node::setColor(int color) {
    _color = color;
}

unsigned int Node::getDegree() const {
    return _adjV.size();
}

unsigned int Node::getDegree(const boost::dynamic_bitset<> &vMap) const {
    unsigned int deg = 0;
    for(auto w : _adjV)
        if(vMap[w])
            deg++;

    return deg;
}

unsigned int Node::getDegree(const std::vector<char> &vMap) const {
    unsigned int deg = 0;
    for(auto w : _adjV)
        if(vMap[w])
            deg++;

    return deg;
}

