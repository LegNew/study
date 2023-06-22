import numpy as np

def act(x):
    return 0 if x < 0.7 else 1

def go(factor_1, factor_2, factor_3, factor_4, factor_5):
    x = np.array([factor_1, factor_2, factor_3, factor_4, factor_5])
    w11 = [-0.3, 0.6, 1, 0.7, 0.1]
    w12 = [-0.5, -0.7, 0.3, -0.1, 0.1]
    w13 = [-0.2, 0.9, 0.4, 0.3, 0.2]
    w21 = [-0.5, 0.1, 0.1]
    w22 = [0.7, -0.5, 0.1]
    weight1 = np.array([w11, w12, w13])
    weight2 = np.array([w21, w22])
    weight3 = np.array([-1, 1])

    sum_hidden1 = np.dot(weight1, x)
    print("Znachiniya sum na neironah pervogo scritogo sloya:" + str(sum_hidden1))

    out_hidden1 = np.array([act(x) for x in sum_hidden1])
    print("Znacheniya na vihodah na neironah pervogo skritogo sloya:" + str(out_hidden1))

    sum_hidden2 = np.dot(weight2, out_hidden1)
    print("Znachiniya sum na neironah vtorogo scritogo sloya:" + str(sum_hidden2))

    out_hidden2 = np.array([act(sum_hidden1) for sum_hidden1 in sum_hidden2])
    print("Znacheniya na vihodah na neironah vtorogo skritogo sloya:" + str(out_hidden2))

    sum_end = np.dot(weight3, out_hidden2)
    y = act(sum_end)
    print("Vihodnoe znachenie HC: " + str(y))

    return y


plot = 1
gameplay = 0
graphics = 1
art = 1
expensive = 0


res = go(plot, gameplay, graphics, art, expensive)
if res == 1:
    print("Budu smotret")
else:
    print("Posmotru potom")