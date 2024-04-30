#ifndef SRC_SEQALG_H
#define SRC_SEQALG_H

#include "compute.h"
#include "../Helpers/Graph.h"

class SeqAlg : public Compute {

public:
    explicit SeqAlg();

    [[nodiscard]] std::string name() const override;

    void solve(Graph & G) override;
};


#endif 
