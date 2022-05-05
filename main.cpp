#include <iostream>
#include <polynomial.h>

int main() {
    // Настройка
    constexpr int amount = 3;
    constexpr int vec[] = {3, 3, 3};
    constexpr int point = 5;

   constexpr int res = polynomial(amount, vec).solve(point);
   std::cout << res << std::endl;
   std::cout << polynomial(amount, vec);
    return 0;
}
