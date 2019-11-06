#include <Cost.h>
#include <HalfSquaredError.h>
#include <Matrix.h>
#include <Network.h>
#include <Sigmoid.h>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  try {
    HalfSquaredError cost;
    Sigmoid hA;
    Sigmoid oA;

    Layer hL(2, &hA);
    Layer oL(1, &oA);

    std::vector<Layer *> layers;

    layers.push_back(&hL);
    layers.push_back(&oL);

    Network net(layers, &cost);

    // const int iterations = 10000;
    float accumulated_error = 0.0;

    Matrix input(2, 1);

    for (size_t i = 1; true; i++) {
      int i0 = rand() % 2;
      int i1 = rand() % 2;
      int exp = i0 ^ i1;

      input(0, 0) = i0;
      input(1, 0) = i1;

      Matrix mExpected(1, 1);
      mExpected(0, 0) = i0 ^ i1;

      float error = net.Optimize(input, mExpected, 0.2f) * 100.0f;

      std::cout << "ERROR: " << (error) << ", INPUT: (" << i0 << ", " << i1
                << ") OUTPUT:" << oL.GetOutput()(0, 0) << ", EXPECTED: " << exp
                << "\n";
    }

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}