import sympy as sp

def main():
    x = sp.symbols('x')

    while True:
        print("\nSelect an option:")
        print("1. Addition")
        print("2. Subtraction")
        print("3. Multiplication")
        print("4. Division")
        print("5. Differentiation")
        print("6. Integration")
        print("7. Absolute Value")
        print("8. Exit")
        choice = input("Enter your choice: ")

        if choice == '8':
            print("Exiting the calculator.")
            break

        expression = input("Enter a mathematical expression in terms of 'x': ")

        try:
            f = sp.sympify(expression)

            if choice == '1':
                result = f
            elif choice == '2':
                result = -f
            elif choice == '3':
                result = f**2
            elif choice == '4':
                result = 1/f
            elif choice == '5':
                result = sp.diff(f, x)
            elif choice == '6':
                result = sp.integrate(f, x)
            elif choice == '7':
                result = sp.Abs(f)
            else:
                print("Invalid choice. Please select a valid option.")
                continue

            print(f"Result: {result}")

        except (sp.SympifyError, sp.PolynomialError, sp.CalculusError):
            print("Invalid expression. Please enter a valid mathematical expression.")

if __name__ == "__main__":
    main()
