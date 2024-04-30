#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <thread>
#include <filesystem>

// Data Structures
#include <vector>
#include <unordered_set>
#include <boost/dynamic_bitset.hpp>

#include "Node.h"
#include "GraphColor.h"
#include "Helper.h"
#include "Jobs.hpp"

class Graph {
private:
    std::vector<Node> _vertices;
    unsigned int V;
    unsigned int E;

public:
    explicit Graph(int V, int E = 0);

    [[nodiscard]] unsigned int getV() const;

    [[nodiscard]] unsigned int getE() const;

    [[nodiscard]] unsigned int getMaxDegree() const;

    std::vector<Node> &getVertices();

    Node &getVertex(unsigned int pos);

    void addEdge(int v1, int v2);
    void setEdgeNumber(unsigned int E);

    // COLORING FUNCTIONS
    bool isColored();
    void resetColors();
    void colorVertexMinimum(Node &v);
    int numColorsUsed();

    // MIS ALGORITHMS
    bool isMIS(const boost::dynamic_bitset<> &vMap);
};

Graph loadGraph(const std::string &fileName, bool multithreading = false);

#endif //SRC_GRAPH_H
