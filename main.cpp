#include <iostream>
#include "vector"
#include "istream"

using namespace std;

class polynomial {
private:
    vector<double> coefficients;

    static string indeterminate(unsigned long power) {
        switch (power) {
            case (0):
                return "";
            case (1):
                return "x";
            default:
                return "x^" + to_string(power);
        }
    }

    static char sign(double number) {
        if (number < 0) return '-';
        return '+';
    }

public:
    polynomial() {
        coefficients.push_back(0);
    }

    polynomial(const vector<int> &input_coefficients) {
        for (int input_coefficient: input_coefficients) {
            coefficients.push_back(input_coefficient);
        }
    }

    polynomial &operator=(const polynomial &copy) {
        coefficients = copy.coefficients;
        return *this;
    }

    ~polynomial() = default;

    bool operator==(polynomial &pol) {
        return coefficients == pol.coefficients;
    }

    bool operator!=(polynomial &pol) {
        return !(coefficients == pol.coefficients);
    }

    polynomial &operator+(const polynomial &pol) {
        for (int i = 0; i < pol.coefficients.size(); ++i) {
            if (i > coefficients.size() - 1) {
                coefficients.push_back(pol.coefficients[i]);
            } else {
                coefficients[i] += pol.coefficients[i];
            }
        }
        while (coefficients[coefficients.size() - 1] == 0) {
            coefficients.pop_back();
        }
        return *this;
    }

    polynomial &operator+=(const polynomial &pol) {
        for (int i = 0; i < pol.coefficients.size(); ++i) {
            if (i > coefficients.size() - 1) {
                coefficients.push_back(pol.coefficients[i]);
            } else {
                coefficients[i] += pol.coefficients[i];
            }
        }
        while (coefficients[coefficients.size() - 1] == 0) {
            coefficients.pop_back();
        }
        return *this;
    }

    polynomial &operator-() {
        for (double &coefficient: coefficients) {
            coefficient = -coefficient;
        }
        return *this;
    }

    polynomial &operator-(const polynomial &pol) {
        for (int i = 0; i < pol.coefficients.size(); ++i) {
            if (i > coefficients.size() - 1) {
                coefficients.push_back(-pol.coefficients[i]);
            } else {
                coefficients[i] -= pol.coefficients[i];
            }
        }
        while (coefficients[coefficients.size() - 1] == 0) {
            coefficients.pop_back();
        }
        return *this;
    }

    polynomial &operator-=(const polynomial &pol) {
        for (int i = 0; i < pol.coefficients.size(); ++i) {
            if (i > coefficients.size() - 1) {
                coefficients.push_back(-pol.coefficients[i]);
            } else {
                coefficients[i] -= pol.coefficients[i];
            }
        }
        while (coefficients[coefficients.size() - 1] == 0) {
            coefficients.pop_back();
        }
        return *this;
    }

    polynomial &operator*(int number) {
        for (double &coefficient: coefficients) {
            coefficient *= number;
        }
        return *this;
    };

    polynomial &operator*=(int number) {
        for (double &coefficient: coefficients) {
            coefficient *= number;
        }
        return *this;
    };

    polynomial &operator/(int number) {
        for (double &coefficient: coefficients) {
            coefficient *= number;
        }
        return *this;
    };

    polynomial &operator/=(int number) {
        for (double &coefficient: coefficients) {
            coefficient *= number;
        }
        return *this;
    };

    friend ostream &operator<<(ostream &os, polynomial &out) {
        if (out.coefficients[out.coefficients.size() - 1] < 0) {
            os << "- " << abs(out.coefficients[out.coefficients.size() - 1])
               << indeterminate(out.coefficients.size() - 1);
        } else {
            os << abs(out.coefficients[out.coefficients.size() - 1])
               << indeterminate(out.coefficients.size() - 1);
        }

        for (int i = (int) out.coefficients.size() - 2; i >= 0; --i) {
            if (out.coefficients[i] != 0) {
                os << " " << sign(out.coefficients[i]) << " " << abs(out.coefficients[i]) << indeterminate(i);
            }
        }
        return os;
    }

    // При чтении с консоли полином обязательно должен заканчиваться каким-либо коэффициентом 0 степени.
    friend istream &operator>>(istream &is, polynomial &in) {
        string element;
        in.coefficients.resize(0);
        bool positive = true;
        bool first = true;
        while (is >> element) {
            if (element == "-") {
                positive = false;
                continue;
            }
            if (element == "+") {
                positive = true;
                continue;
            }
            int coefficient = 0;
            int power = 0;
            int i = 0;
            while ((element[i] != 'x') and (element[i] != '\n')) {
                i++;
                if (element.size() < i + 1) {
                    element += '\n';
                    break;
                }
            }
            if (i == 0) {
                coefficient = 1;
            } else {
                for (int j = 0; j < i; j++) {
                    coefficient *= 10;
                    coefficient += element[j] - '0';
                }
            }
            if (element[i] != '\n') {
                if (element[i + 1] == '^') {
                    for (int j = i + 2; j < element.size(); ++j) {
                        power *= 10;
                        power += element[j] - '0';
                    }
                } else {
                    power = 1;
                }
            }
            int sign = 1;
            if (!positive) sign = -1;
            if (first) {
                in.coefficients.resize(power + 1);
                first = false;
            }
            in.coefficients[power] = sign * coefficient;
            if ((element[i] == '\n') or (power == 0)) {
                break;
            }
        }
        return is;
    }

    double &operator[](const int &index) {
        return coefficients[index];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
