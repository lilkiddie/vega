#include <benchmark/benchmark.h>

#include "include/my_add.hpp"


static void BenchmarkAdd(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(my_add(state.range(0), state.range(1)));
    }
}

BENCHMARK(BenchmarkAdd)->Args({2, 2})->Args({4, 7})->Args({-2, 15});
BENCHMARK_MAIN();
