#include <Cost.h>
#include <Linear.h>
#include <Matrix.h>
#include <Network.h>
#include <ReLU.h>
#include <RootSquaredError.h>
#include <Sigmoid.h>
#include <Tanh.h>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <time.h>
#include <vector>

int main() {
  try {
    srand(time(0));

    RootSquaredError cost;
    Tanh hA1;
    // ReLU hA2;
    Tanh oA;

    Layer hL1(2, &hA1);
    // Layer hL2(6, &hA2);
    Layer oL(1, &oA);

    /*
        Matrix m1(hL1.GetSize(), 2);
        Matrix m2(oL.GetSize(), hL1.GetSize());

        m1.Randomize();
        m2.Randomize();

        Matrix b1(hL1.GetSize(), 1);
        Matrix b2(oL.GetSize(), 1);

        b1.Randomize();
        b2.Randomize();

        hL1.Init(2, m1, b1);
        oL.Init(4, m2, b2);
        */

    hL1.Init(2);
    // hL2.Init(hL1.GetSize());
    oL.Init(hL1.GetSize());

    std::vector<Layer *> layers;

    layers.push_back(&hL1);
    // layers.push_back(&hL2);
    layers.push_back(&oL);

    Network net(2, layers, &cost);

    // double accumulated_error = 0.0;

    Matrix input(2, 1);

    for (size_t i = 1; true; i++) {
      int i0 = rand() % 2;
      int i1 = rand() % 2;

      int exp = i0 ^ i1;

      input(0, 0) = (double)i0;
      input(1, 0) = (double)i1;

      Matrix mExpected(1, 1);
      mExpected(0, 0) = (double)exp;

      std::cin.get();
      // std::cout << std::endl << "Hidden:" << std::endl;
      // hL1.Print();

      const double error = net.Optimize(input, mExpected, 1, 1);

      if (i % 1 == 0) {
        std::cout << std::fixed;
        std::cout << std::setw(8) << std::right << (i / 1) << std::setfill('0')
                  << std::setprecision(3)
                  << ": ERROR: " << std::round(error * 1000) / 1000
                  << ", INPUT: (" << i0 << ", " << i1 << ")"
                  << " OUTPUT:"
                  << std::round(oL.GetOutput()(0, 0) * 1000) / 1000
                  << ", EXPECTED: " << exp << "\n"
                  << std::setprecision(-1) << std::defaultfloat;

        // std::cout << std::endl << "Hidden:" << std::endl;
        // hL2.Print();
        // std::cout << std::endl << "Output:" << std::endl;
        // oL.Print();
        // std::cout << std::endl;
      }
    }

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}