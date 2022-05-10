from sympy import Symbol, solve, pprint, Eq
x = Symbol('x')
k = Symbol('k')

equation = 2 * x -6
equation2 = k-2

pprint(solve(Eq(equation2, 4)))