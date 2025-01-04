import math

# 计算两点之间的整数点
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# 获取边上所有的整数点
def get_boundary_points(x1, y1, x2, y2):
    points = []
    dx, dy = x2 - x1, y2 - y1
    g = gcd(abs(dx), abs(dy))  # 最大公约数
    for i in range(g + 1):
        x = x1 + i * dx // g
        y = y1 + i * dy // g
        points.append((x, y))
    return points

# 判断一个点是否在多边形内
def is_point_inside_polygon(x, y, polygon):
    n = len(polygon)
    inside = False
    p1x, p1y = polygon[0]
    for i in range(n + 1):
        p2x, p2y = polygon[i % n]
        if y > min(p1y, p2y):
            if y <= max(p1y, p2y):
                if x <= max(p1x, p2x):
                    if p1y != p2y:
                        xinters = (y - p1y) * (p2x - p1x) / (p2y - p1y) + p1x
                    if p1x == p2x or x <= xinters:
                        inside = not inside
        p1x, p1y = p2x, p2y
    return inside

# 获取多边形内的所有整数点
def get_all_integer_points(polygon):
    # 找到多边形的边界范围
    min_x = min(polygon, key=lambda p: p[0])[0]
    max_x = max(polygon, key=lambda p: p[0])[0]
    min_y = min(polygon, key=lambda p: p[1])[1]
    max_y = max(polygon, key=lambda p: p[1])[1]
    
    # 获取所有边上的整数点
    boundary_points = []
    for i in range(len(polygon)):
        boundary_points.extend(get_boundary_points(polygon[i][0], polygon[i][1], polygon[(i + 1) % len(polygon)][0], polygon[(i + 1) % len(polygon)][1]))

    # 获取内部的整数点
    interior_points = []
    for x in range(min_x, max_x + 1):
        for y in range(min_y, max_y + 1):
            if is_point_inside_polygon(x, y, polygon):
                interior_points.append((x, y))
    
    return set(boundary_points + interior_points)

# 示例：一个三角形的顶点
polygon = [(0, 0), (4, 0), (2, 4), (2, 2)]

# 获取所有整数点
integer_points = get_all_integer_points(polygon)
integer_points = sorted(integer_points)
print(integer_points)
