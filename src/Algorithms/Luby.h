#ifndef SRC_LUBY_H
#define SRC_LUBY_H

#include <mutex>
#include <atomic>

#include "compute.h"
#include "../Helpers/Graph.h"
#include "../Helpers/Split_Range.h"
#include "../Helpers/ParallelProcessing.hpp"

class Luby : public Compute {

public:
    explicit Luby(int numThreads = MAX_THREADS);

    [[nodiscard]] std::string name() const override;

    void solve(Graph &G) override;
};

#endif //SRC_LUBY_H
