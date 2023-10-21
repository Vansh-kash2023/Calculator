#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

double differentiate(const function<double(double)>& f, double x, double h = 1e-5) {
    double x_plus_h = x + h;
    double x_minus_h = x - h;
    double derivative = (f(x_plus_h) - f(x_minus_h)) / (2 * h);
    return derivative;
}

double integrate(const function<double(double)>& f, double a, double b, int n = 1000) {
    double h = (b - a) / n;
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double x0 = a + i * h;
        double x1 = x0 + h;
        result += (f(x0) + f(x1)) * h / 2;
    }
    return result;
}

double absoluteValue(double a) {
    return abs(a);
}

int main() {
    cout << "Calculator Menu:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Differentiate" << endl;
    cout << "6. Integrate" << endl;
    cout << "7. Absolute Value" << endl;
    cout << "Enter the option (1-7): ";

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 7) { 
        cout << "Invalid choice." << endl;
        return 1;
    }

    double result, a, b;
    function<double(double)> f;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
        cout << "Enter two numbers: ";
        cin >> a >> b;
    } else if (choice == 5 || choice == 6 || choice == 7) {
        cout << "Enter a single number: ";
        cin >> a;
    }

    switch (choice) {
        case 1:
            result = add(a, b);
            break;
        case 2:
            result = subtract(a, b);
            break;
        case 3:
            result = multiply(a, b);
            break;
        case 4:
            result = divide(a, b);
            break;
        case 5:
            // Define the function to differentiate here, e.g., f(x) = x^2:
            cout<<"Differentiating x^2 and putting the value of x"<<endl;
            f = [](double x) { return x * x; };
            result = differentiate(f, a);
            break;
        case 6:
            cout << "Enter the integration interval [a, b]: ";
            double interval_a, interval_b;
            cin >> interval_a >> interval_b;
            // Define the function to integrate here, e.g., f(x) = x^2:
            f = [](double x) { return x * x; };
            result = integrate(f, interval_a, interval_b);
            break;
        case 7:
            result = absoluteValue(a);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}
