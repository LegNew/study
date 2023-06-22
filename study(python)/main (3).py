import numpy as np


def f(x):
    return 2/(1 + np.exp(-x)) - 1


def df(x):
    return 0.5*(1 + x)*(1 - x)


w11 = [0.3, 0.6, 0.1, 0.7, 0.1]
w12 = [0.5, 0.7, 0.3, 0.1, 0.1]
w13 = [0.2, 0.9, 0.4, 0.3, 0.2]
w21 = [0.5, 0.1, 0.1]
w22 = [0.7, 0.5, 0.1]
W1 = np.array([w11, w12, w13])
W2 = np.array([w21, w22])
W3 = np.array([-0.4, 0.6])


def go_for(inp):
    sum = np.dot(W1, inp)
    out1 = np.array([f(x) for x in sum])

    sum = np.dot(W2, out1)
    out2 = np.array([f(out1) for out1 in sum])

    sum = np.dot(W3, out2)
    y = f(sum)
    return(y, out1, out2)


def train(epoch):
    global W1, W2, W3
    lmd = 0.01
    N = 10000
    count = len(epoch)
    for k in range(N):
        x = epoch[np.random.randint(0, count)]
        y, out1, out2 = go_for(x[0:5])
        e = y - x[-1]
        delta = e*df(y)
        W3[0] = W3[0] - lmd*delta*out2[0]
        W3[1] = W3[1] - lmd*delta*out2[1]

        delta2 = W2.transpose()*delta*df(out2)
        delta2 = delta2.transpose()

        W2[0, :] = W2[0, :] - np.array(x[0:3]) * delta2[0] * lmd
        W2[1, :] = W2[1, :] - np.array(x[0:3]) * delta2[1] * lmd

        delta3 = W1.transpose()*delta*df(out1)
        delta3 = delta3.transpose()

        W1[0, :] = W1[0, :] - np.array(x[0:5]) * delta3[0] * lmd
        W1[1, :] = W1[1, :] - np.array(x[0:5]) * delta3[1] * lmd
        W1[2, :] = W1[2, :] - np.array(x[0:5]) * delta3[2] * lmd


sample = [(0, 0, 1, 1, 0, 1),
          (0, 0, 0, 0, 1, 0),
          (1, 1, 0, 0, 0, 1),
          (0, 0, 0, 1, 1, 1),
          (1, 0, 1, 0, 1, 0),
          (0, 1, 1, 1, 0, 1),
          (0, 0, 0, 1, 0, 0),
          (1, 1, 0, 0, 1, 1),
          (1, 1, 1, 0, 1, 1),
          (1, 1, 0, 1, 1, 1),
          (1, 0, 1, 1, 0, 1),
          (0, 1, 0, 1, 1, 1),
          (0, 1, 1, 1, 1, 0),
          (1, 0, 1, 1, 1, 0),
          (1, 1, 1, 1, 1, 1),
          (1, 0, 1, 0, 0, 0),
          (1, 0, 0, 1, 0, 1),
          (1, 1, 1, 0, 0, 1),
          (1, 0, 0, 0, 1, 1),
          (1, 1, 0, 1, 0, 1)]

train(sample)

for x in sample:
    y, out1, out2 = go_for(x[0:5])
    print(f"Выходное значение НС: {y} => {x[-1]}")