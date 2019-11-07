#include <Cost.h>
#include <HalfSquaredError.h>
#include <Matrix.h>
#include <Network.h>
#include <Random.h>
#include <Sigmoid.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  try {
    HalfSquaredError cost;
    Sigmoid hA;
    Sigmoid oA;

    Layer hL(3, &hA);
    Layer oL(1, &oA);

    std::vector<Layer *> layers;

    layers.push_back(&hL);
    layers.push_back(&oL);

    Network net(layers, &cost);

    float accumulated_error = 0.0;

    Matrix input(2, 1);

    for (size_t i = 0; true; i++) {
      int i0 = Random::Binary();
      int i1 = Random::Binary();

      int exp = i0 ^ i1;

      input(0, 0) = i0;
      input(1, 0) = i1;

      Matrix mExpected(1, 1);
      mExpected(0, 0) = i0 ^ i1;

      float error = net.Optimize(input, mExpected, 0.001f) * 100.0f;

      if (i % 1000 == 0) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << i << ": ERROR: " << (error) << ", INPUT: (" << i0 << ", "
                  << i1 << ") OUTPUT:" << oL.GetOutput()(0, 0)
                  << ", EXPECTED: " << exp << "\n";

        // std::cout << std::endl << "Hidden:" << std::endl;
        // hL.Print();
        // std::cout << std::endl << "Output:" << std::endl;
        // oL.Print();
        // std::cout << std::endl;
      }
      // std::cin.get();
    }

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}