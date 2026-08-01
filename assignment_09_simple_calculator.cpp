// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function for addition
double add(double a, double b) {
    return a + b;
}

// Function for subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function for multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function for division
bool divide(double a, double b, double &result) {
    if (b == 0)
        return false;

    result = a / b;
    return true;
}

// Function for modulus
bool modulusOperation(double a, double b, double &result) {
    if (b == 0)
        return false;

    result = fmod(a, b);
    return true;
}

// Function for exponentiation
double power(double base, double exponent) {
    return pow(base, exponent);
}

// Display menu
void printMenu() {
    cout << "=============================\n";
    cout << "      SIMPLE CALCULATOR\n";
    cout << "=============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
}

int main() {
    cout << fixed << setprecision(2);

    while (true) {
        printMenu();

        int choice;
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n\n";
            continue;
        }

        if (choice == 7) {
            cout << "Thank you for using the calculator!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please choose between 1 and 7.\n\n";
            continue;
        }

        double num1, num2;
        cout << "Enter first number : ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        double result = 0;
        bool success = true;
        char symbol;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                symbol = '+';
                break;

            case 2:
                result = subtract(num1, num2);
                symbol = '-';
                break;

            case 3:
                result = multiply(num1, num2);
                symbol = '*';
                break;

            case 4:
                success = divide(num1, num2, result);
                symbol = '/';
                if (!success)
                    cout << "Error: Division by zero is not allowed.\n";
                break;

            case 5:
                success = modulusOperation(num1, num2, result);
                symbol = '%';
                if (!success)
                    cout << "Error: Modulus by zero is not allowed.\n";
                break;

            case 6:
                result = power(num1, num2);
                symbol = '^';
                break;
        }

        if (success) {
            cout << "\nResult:\n";
            cout << num1 << " " << symbol << " " << num2
                 << " = " << result << "\n\n";
        }
    }

    return 0;
}