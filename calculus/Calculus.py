from typing import Dict, Union

from sympy import Complement, Expr, Reals, Symbol, symbols, sympify
from sympy.calculus.util import continuous_domain

Number = Union[int, float]


class CoreCalc:

    @staticmethod
    def _init_symbol(input_variable: str) -> Symbol:
        # If using multiple variables, separate via comma in a string --> "x, y, z"
        return symbols(input_variable)

    def __init__(self, input_func: str) -> None:
        if not isinstance(input_func, str):
            raise TypeError("Must input string to initialize function")

        self.expression = sympify(input_func)

    def differentiate(self) -> Expr:
        return self.expression.diff()

    def antidifferentiate(self) -> Expr:
        return self.expression.integrate()

    def evaluate(self, val_dictionary: Dict[str, Number]) -> Expr:
        return self.expression.subs(val_dictionary)

    def domain(self, *variables: str) -> set:
        # With no params, will automatically assume you are using "x"
        if not variables:
            variables = ("x",)

        # Domain is where the function is continuous in every variable
        domain = Reals
        for variable in variables:
            symbol = self._init_symbol(variable)
            domain = domain.intersection(continuous_domain(self.expression, symbol, Reals))

        return domain

    def find_undefined(self, *variables: str) -> set:
        return Complement(Reals, self.domain(*variables))

    def newton_method(self, x0: Number, iterations: int, wrt: str) -> Number:
        # Algorithm for Newton's method of approximating roots: x_{n+1} = x_n - f(x_n) / f'(x_n)
        if not isinstance(wrt, str):
            raise TypeError("Wrt expression must be a string")

        if x0 not in self.domain(wrt):
            raise ValueError("x0 is not in the domain of the function; try another value")

        function_prime = self.expression.diff(wrt)

        for _ in range(iterations):
            evaluated_prime = function_prime.evalf(subs={wrt: x0})
            evaluated_function = self.expression.evalf(subs={wrt: x0})

            if evaluated_prime == 0:
                raise ValueError("Evaluated prime was zero; try another value")

            x0 = x0 - (evaluated_function / evaluated_prime)

        return x0

    def linearize(self, a: Number, wrt: str) -> Expr:
        # First expansion of Taylor series; linear approximation technique: L(x) = f(a) + f'(a)(x - a)
        if not isinstance(wrt, str):
            raise TypeError("Wrt expression must be a string")

        if a not in self.domain(wrt):
            raise ValueError("Input value was not in domain; try another value")

        wrt = self._init_symbol(wrt)

        foa = self.expression.evalf(subs={wrt: a})
        fpoa = self.expression.diff(wrt).evalf(subs={wrt: a})

        return foa + fpoa * (wrt - a)

    @staticmethod
    def factorial_run(num: int) -> int:
        # Calculates the factorial of a number (from an older project I wrote)
        if num < 0:
            raise ValueError("Factorial operand not defined for numbers below zero")

        factorial_num = 1
        for next_num in range(2, num + 1):
            factorial_num *= next_num

        return factorial_num

    def to_string(self) -> str:
        return str(self.expression)
