import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# 数据
x = np.array([6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24])
y = np.array([10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600])

# 定义要拟合的函数
def func(x, a, b):
    return a * x + b

# 进行曲线拟合
popt, pcov = curve_fit(func, x, y)

# 绘制原始数据和拟合曲线
plt.scatter(x, y, label='Original data')
plt.plot(x, func(x, *popt), 'r-', label='Fitted line: y = %fx + %f' % (popt[0], popt[1]))

plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()
