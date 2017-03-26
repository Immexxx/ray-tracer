#pragma once

#include <thread>
#include <cstdlib>
#include <algorithm>

const float numeric_eps = 1e-6;

inline float randf() {
  return rand() / static_cast<float>(RAND_MAX);
}

inline float clamp(float x, float l, float r) {
  return std::min(std::max(x, l), r);
}