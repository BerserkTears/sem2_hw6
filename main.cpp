#include <iostream>

class polynomial{
private:
    const int m_amount;
    const int * m_coefficients;
    constexpr int pow(const int number, const int degree) const{
        return degree == 0 ? 1 : number * pow(number, degree - 1);
    }
    constexpr int calc (const int point, const int degree) const {
        return degree == 0 ? 0 : m_coefficients[m_amount - degree] * pow(point, m_amount - degree) + calc(point, degree - 1);
    }
public:
      constexpr polynomial(const int amount, const int coefficients[]):m_amount(amount),m_coefficients(coefficients){
    }

    ~polynomial(){
        delete [] m_coefficients;
    }

    constexpr int solve(const int point) const{
        return calc(point, m_amount);
      }
};

int main() {
    constexpr int amount = 3;
    constexpr int vec[] = {3,3, 3};
    const polynomial poly(amount, vec);
    std::cout << poly.solve(5);
    return 0;
}
