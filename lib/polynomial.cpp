#include <istream>


class polynomial {
private:
    const int m_amount;
    const int *m_coefficients;

    constexpr int pow(const int number, const int degree) const {
        return degree == 0 ? 1 : number * pow(number, degree - 1);
    }

    constexpr int calc(const int point, const int degree) const {
        return degree == 0 ? 0 : m_coefficients[m_amount - degree] * pow(point, m_amount - degree) +
                                 calc(point, degree - 1);
    }

public:
    constexpr polynomial(const int amount, const int * coefficients) : m_amount(amount), m_coefficients(coefficients) {
    }

    constexpr int solve(const int point) const {
        return calc(point, m_amount);
    }

    friend std::ostream &operator<<(std::ostream &os, polynomial poly) {
        if (poly.m_amount > 1) {
            os << poly.m_coefficients[0] << " + ";
            for (int i = 1; i < poly.m_amount - 1; ++i) {
                os << poly.m_coefficients[i] << "x^" << i << " + ";
            }
            os << poly.m_coefficients[poly.m_amount - 1] << "x^" << poly.m_amount - 1;
        } else {
            os << poly.m_coefficients[0];
        }
        return os;
    }
};