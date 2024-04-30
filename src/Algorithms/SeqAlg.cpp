#include "../Helpers/Graph.h"
#include "SeqAlg.h"

SeqAlg::SeqAlg(): Compute(1) {}

std::string SeqAlg::name() const {
    return "Greedy";
}

void SeqAlg::solve(Graph &G) {
    std::vector<int> idx = randomPermutation(G.getV());

    auto& vertices = G.getVertices();
    for(int i=0; i<G.getV(); i++)
        G.colorVertexMinimum(vertices[idx[i]]);
}
