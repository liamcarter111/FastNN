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

    int iterations = 1000;

    Matrix input(2, 1);

    while (iterations--) {
      int i0 = rand() % 2;
      int i1 = rand() % 2;
      int exp = i0 ^ i1;

      input(0, 0) = i0;
      input(1, 0) = i1;

      Matrix mExpected(1, 1);
      mExpected(0, 0) = i0 ^ i1;

      net.Optimize(input, mExpected, 1.0f);

      std::cout << "ERROR: " << (cost.GetError()) * 100.0f << ", INPUT: (" << i0
                << ", " << i1 << ") OUTPUT:" << oL.GetOutput()(0, 0)
                << ", EXPECTED: " << exp << "\n";
    }

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}