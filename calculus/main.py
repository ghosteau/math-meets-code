from Calculus import CoreCalc

# Some examples/test-cases of the class in action

my_func = CoreCalc("x**2 - 5*x + 2")  # Init the function using the CoreCalc class

print("FUNCTION:", my_func.to_string())

print("DOMAIN:", my_func.domain())  # Will evaluate to all real numbers

print("UNDEFINED VALUES:", my_func.find_undefined())

print("EVALUATION:", my_func.evaluate({"x": 1}))  # Will evaluate to -2 via plugging in

print("FIRST DERIVATIVE:", my_func.differentiate())  # f'(x)

print("INTEGRAL:", my_func.antidifferentiate())  # General antiderivative F(x)

print("LINEARIZED FUNCTION (CENTERED AT 2):", my_func.linearize(2, "x"))

print("NEWTON ZERO APPROXIMATION:", my_func.newton_method(6, 100, "x"))  # 100 iterations starting at x = 6

print("FACTORIAL OF 5:", CoreCalc.factorial_run(5))
