from Calculus import CoreCalc

# Some examples/test-cases of the class in action

my_func = CoreCalc("x**2 - 5*x + 2") # Init the function using the CoreCalc class

print("FUNCTION:", my_func.to_string()) # Prints the init'ed CoreCalc object

print("DOMAIN:", my_func.domain()) # Will evaluate to all real numbers

print("UNDEFINED VALUES:", my_func.find_undefined()) # Prints undefined values

print("EVALUATION:", my_func.evaluate({"x": 1})) # Will evaluate to -2 via plugging in

print("FIRST DERIVATIVE:", my_func.differentiate()) # Prints the derivative (f'(x))

print("INTEGRAL: ", my_func.antidifferentiate()) # Prints the general antiderivative (F(X))

print("LINEARIZED FUNCTION (CENTERED AT 2):", my_func.linearize(2, "x")) # Outputs linearized function centered at 2

print("NEWTON ZERO APPROXIMATION:", my_func.newton_method(6, 100, "x")) # Output approximated zero using Newton's method with 100 iterations
