#include "Random.h"
#include <cfloat>
#include <chrono>
#include <random>

using namespace std::chrono;

std::random_device rd;
unsigned long seed =
    std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch())
        .count();
std::mt19937 gen(rd.entropy() != 0 ? rd() : seed);

float Random::Normalized() {
  std::uniform_real_distribution<> dis(0 + FLT_EPSILON, 1 - FLT_EPSILON);
  return dis(gen);
}

int Random::Binary() {
  unsigned int number = gen();
  return number % 2;
}
