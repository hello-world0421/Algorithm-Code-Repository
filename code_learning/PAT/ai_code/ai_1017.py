def high_precision_division(dividend, divisor):
    """
    高精度除法
    :param dividend: 被除数，字符串形式
    :param divisor: 除数，整数形式
    :return: 商，字符串形式
    """
    if divisor == 0:
        raise ValueError("除数不能为零")

    # 将除数转换为字符串形式，方便处理
    divisor_str = str(divisor)
    divisor_len = len(divisor_str)

    # 初始化结果和余数
    result = ""
    remainder = 0

    # 逐位进行除法运算
    for i in range(len(dividend)):
        # 当前位的数值
        current_digit = int(dividend[i])
        # 当前的被除数（余数 + 当前位）
        current_dividend = remainder * 10 + current_digit
        # 计算商
        quotient = current_dividend // divisor
        # 计算余数
        remainder = current_dividend % divisor
        # 将商添加到结果中
        result += str(quotient)

    # 去除结果前面的零
    result = result.lstrip('0')
    if result == "":
        result = "0"

    return result, remainder

# 示例
dividend = "123456789050987654321"
divisor = 7
print(high_precision_division(dividend, divisor))
