#ifndef SRC_GRAPHCOLOR_H
#define SRC_GRAPHCOLOR_H

#include <vector>
#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include "Helper.h"

#define DEFAULT_SIZE 64

class GraphColor {
    boost::dynamic_bitset<> colors;

    void resizeColors(int maxCol);

public:
    GraphColor();

    explicit GraphColor(size_t size);

    [[nodiscard]] int findMinCol() const;

    void addColor(int col);
};

#endif 
