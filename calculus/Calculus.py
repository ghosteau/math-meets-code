from sympy import *
import sympy
from sympy.calculus.util import continuous_domain
from typing import Union, Dict

class CoreCalc:

    @staticmethod
    def _init_symbol(input_variable: str) -> Symbol:
        # If using multiple variables, seperate via comma in a string --> "x, y, z"
        return(symbols(input_variable))

    def __init__(self, input_func: str) -> None:
        if not isinstance(input_func, str):
            raise TypeError("Must input string to initialize function")

        self.expression = sympify(input_func)

    def differentiate(self) -> Expr:
        return sympify(self.expression.diff())

    def antidifferentiate(self) -> Expr:
        return sympify(self.expression.integrate())

    def evaluate(self, val_dictionary: Dict[str, Union[int, float]]) -> Union[int, float]:
        return self.expression.subs(val_dictionary)

    def domain(self, *symbols: str) -> set:
        # With no params, will automatically assume you are using "x"
        if not symbols:
            symbols = set(["x"])

        domain = sympy.Reals
        for symbol in symbols:
            symbol = self._init_symbol(symbol)
            this_domain = continuous_domain(self.expression, symbol, sympy.Reals)
            domain = domain.intersection(this_domain)

        return domain

    def find_undefined(self, *symbols: str) -> set:
        domain = self.domain(*symbols)
        return Complement(sympy.Reals, domain)

    def newton_method(self, x0: Union[int, float], iterations: int, wrt: str) -> Union[int, float]:
        # Algorithm for Newton's method of approximating roots
        if not isinstance(wrt, str):
            raise TypeError("Wrt expression must be a string")

        function_prime = self.expression.diff(wrt)

        if x0 not in self.domain():
            raise ValueError("x0 is not in the domain of the function; try another value")

        for iteration in range(iterations):
            evaluated_prime = function_prime.evalf(subs={wrt: x0})
            evaluated_function = self.expression.evalf(subs={wrt: x0})

            if evaluated_prime == 0:
                raise ValueError("Evaluated prime was zero; try another value")

            new_x = x0 - (evaluated_function / evaluated_prime)
            x0 = new_x

        return new_x

    def linearize(self, a: Union[int, float], wrt: str) -> Expr:
        # First expansion of Taylor series; linear approximation technique
        if not isinstance(wrt, str):
            raise TypeError("Wrt expression must be a string")

        wrt = self._init_symbol(wrt)

        if a not in self.domain():
            raise ValueError("Input value was not in domain; try another value")

        foa = self.expression.evalf(subs={wrt: a})
        fpoa = self.expression.diff(wrt).evalf(subs={wrt: a})

        linearized_function = sympify(f"{foa} + {fpoa} * ({wrt} - {a})")
        return linearized_function

    @staticmethod
    def factorialRun(num: int) -> int:
        # Calculates the factorial of a number (from an older project I wrote) --> static function
        factorialNum = 1

        if num == 0 or num == 1:
            return factorialNum

        if num < 0:
            raise Exception("Factorial operand not defined for numbers below zero")

        for nextNum in range(2, num + 1):
            factorialNum *= nextNum

        return factorialNum


    def to_string(self) -> str:
        return str(self.expression)
