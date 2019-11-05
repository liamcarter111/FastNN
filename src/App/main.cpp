#include <Cost.h>
#include <HalfSquaredError.h>
#include <HiddenLayer.h>
#include <InputLayer.h>
#include <Linear.h>
#include <Matrix.h>
#include <Network.h>
#include <OutputLayer.h>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  try {
    HalfSquaredError cost;
    Linear hA;
    Linear oA;
    InputLayer iL(2);
    HiddenLayer hL(2, 2, &hA);
    OutputLayer oL(1, 2, &oA);

    std::vector<HiddenLayer> hiddenLayers({hL});

    Network net(iL, hiddenLayers, oL, &cost);

    int iterations = 1000;

    while (--iterations) {
      int i0 = rand() % 2;
      int i1 = rand() % 2;
      int exp = i0 ^ i1;

      iL.GetValues()(0, 0) = i0;
      iL.GetValues()(1, 0) = i1;

      net.ForwardProp();

      Matrix mExpected(1, 1);
      mExpected(0, 0) = i0 ^ i1;

      net.Optimize(mExpected);
      std::cout << "ERROR: " << cost.GetError() << ", INPUT: (" << i0 << ", "
                << i1 << ") OUTPUT:" << oL.GetValues()(0, 0)
                << ", EXPECTED: " << exp << "\n";
    }

    std::cin;

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}