#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> values;
    std::vector<bool> value(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (value[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                value[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (value[p])
        {
            values.push_back(p);
        }
    }
    return values;
}