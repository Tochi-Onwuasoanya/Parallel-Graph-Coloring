#include "Helper.h"

std::vector<int> randomPermutation(unsigned int N) {
    std::vector<int> v(N);
    for (int i = 0; i < N; i++)
        v[i] = i;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    return v;
}

bool randomWithProb(double p) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::discrete_distribution<> distrib({ 1-p, p });

    return distrib(g);
}

int randomWithinRange(int a, int b) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> distrib(a, b);

    return distrib(g);
}

unsigned int findPrimeWithinRange(unsigned int a, unsigned int b) {
    if (a <= 2) {
        a = 2;
        if (b >= 2)
            a++;
    }

    if (a % 2 == 0)
        a++;

    for(auto i=a; i<=b; i=i+2) {
        bool flag = true;
        for(auto j=2; j*j <= i; ++j)
            if(i % j == 0) {
                flag = false;
                break;
            }
        if(flag)
            return i;
    }

    return 0;   // no prime found
}

// From graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
// compute the next highest power of 2 of 32-bit v
unsigned int nextHighestPowerOf2(unsigned int v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}


