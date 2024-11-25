import os

def f(n: int) -> int:
    return n * (n + 1) >> 1

# 确保 source 文件夹存在，如果不存在则创建
os.makedirs("D:\college\learn_important\VScode\suan_fa_code\code_learning\洛谷\刷题\source", exist_ok=True)

# 打开 source 文件夹中的 output.txt 文件，准备写入
output_file_path = os.path.join("D:\college\learn_important\VScode\suan_fa_code\code_learning\洛谷\刷题\source", "output.txt")
with open(output_file_path, "w") as file:
    for i in range(1, 10000):
        result = f(i)
        if result <= 1e7:
            file.write(f"{result}, ")
        else:
            break
