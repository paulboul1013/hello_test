from mpmath import mp

mp.dps = 1_000_000  # 設置計算精度
pi_value = str(mp.pi)  # 獲取 π 值
with open("pi_1million_digits.txt", "w") as f:
    f.write(pi_value)  # 保存到文件