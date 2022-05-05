#include <iostream>
#include "istream"

class polynomial{
private:
    const int m_amount;
    const int * m_coefficients;
    constexpr int pow(const int number, const int degree) const{
        int result = 1;
        for (int i = 0; i <= degree; ++i) {
            result *= number;
        }
        return result;
    }
public:
      constexpr polynomial(const int amount, const int coefficients[]):m_amount(amount),m_coefficients(coefficients){
//        m_coefficients = new int[amount];
//        for (int i = 0; i < amount; ++i) {
//            m_coefficients[i] = coefficients[i];
//        }
//    m_coefficients = coefficients;
    }
    constexpr int solve(const int point) const{
        int sum = 0;
        for (int i = 0; i < m_amount; ++i) {
            sum+= pow(m_coefficients[i], i);
        }
        return sum;
      }
};

int main() {
    constexpr int amount = 3;
    constexpr int vec[] = {1,2,3};
    const polynomial poly(amount, vec);
    std::cout << poly.solve(2);
    return 0;
}
