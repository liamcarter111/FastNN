#include <Matrix.h>
#include <Network.h>
#include <chrono>
#include <iomanip>
#include <iostream>

#define DIM_S 5
#define DIM_M 25
#define DIM_L 125
#define DIM_XL 625

#define ITERATIONS_S 10000000
#define ITERATIONS_M 100000
#define ITERATIONS_L 1000
#define ITERATIONS_XL 10

template <int DIM, int ITERATIONS> void Test() {
  Matrix mat1(DIM, DIM);
  Matrix mat2(DIM, DIM);
  Matrix mat3(DIM, DIM);
  Matrix::RANDOM(mat1);
  Matrix::RANDOM(mat2);

  auto t_start = std::chrono::high_resolution_clock::now();

  for (size_t i = 0; i < ITERATIONS; i++) {
    // mat3 = mat2 * mat1;
    Matrix::MUL(mat3, mat1, mat2);
  }

  auto t_end = std::chrono::high_resolution_clock::now();
  double total =
      std::chrono::duration<double, std::milli>(t_end - t_start).count();
  double opTime = total / ITERATIONS;
  double opSec = 1000.0 / opTime;

  std::cout << std::setprecision(2);
  std::cout << std::setw(14);
  std::cout << total << "|";
  std::cout << std::setw(14);
  std::cout << opTime * 1000000;
  std::cout << "|";
  std::cout << std::setw(14);
  if (opSec > 1000) {
    std::cout << std::setprecision(0);
    std::cout << opSec / 1000 << "K";
  } else {
    std::cout << std::setprecision(3);
    std::cout << opSec / 1000;
  }
  std::cout << "|";
}

int main() {
  try {

    std::cout << "-------------------------------------------------------------"
                 "-------------------------------------------------------------"
                 "-------------------------------------------------------------"
                 "------\n"
              << "|                       S                      "
              << "|                       M                      "
              << "|                       L                      "
              << "|                       XL                     |\n"
              << "|   Total ms   |"
              << "    Op A/ns    |"
              << "    Op K/Sec   |"
              << "   Total ms   |"
              << "    Op A/ns    |"
              << "    Op P/Sec   |"
              << "   Total ms   |"
              << "    Op A/ns    |"
              << "    Op P/Sec   |"
              << "   Total ms   |"
              << "    Op A/ns    |"
              << "    Op P/Sec   |\n"
              << "-------------------------------------------------------------"
                 "-------------------------------------------------------------"
                 "-------------------------------------------------------------"
                 "------\n";
    std::cout << std::fixed;

    // while (1) {
    std::cout << "|";

    Test<DIM_S, ITERATIONS_S>();
    Test<DIM_M, ITERATIONS_M>();
    Test<DIM_L, ITERATIONS_L>();
    Test<DIM_XL, ITERATIONS_XL>();

    std::cout << "\n";
    //  }

    // std::cin.get();

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}