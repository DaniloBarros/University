import numpy as np
from matplotlib import pyplot as plt

# Segundo passo: Definir funo
def f(x):
    return -x * np.e ** -x + 0.2

def p(A, B):
    plt.xlabel('x')
    plt.ylabel('y = f(x)')
    plt.title('Zero de funcoes')
    plt.grid()
    plt.plot(x, y)

    [xmin, xmax, ymin, ymax] = plt.axis()
    plt.plot([A, A], [ymin, ymax], 'k-')
    plt.plot([B, B], [ymin, ymax], 'k-')

# Terceiro passo: Visualizar fun
x = np.linspace(0, 10, 100)
y = f(x)

p(1, 10)
plt.show()

A = 1
B = 10

for i in range(5):
    # Termo de recursao
    xi = (A + B) / 2
    p(A, B)
    [xmin, xmax, ymin, ymax] = plt.axis()
    plt.plot([xi, xi], [ymin, ymax], '--')
    plt.show()

    if (f(A) * f(xi)) < 0:
        B = xi
    elif (f(A) * f(xi)) == 0:
        print('Raiz encontrada em %6.f' % xi)
    else:
        A = xi
plt.show(block=True)
