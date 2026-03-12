def f(n: int) -> int:
    m = [0, 1]
    if n < 2:
        return m[n]

    for i in range(1, n):
        t = m[0] + m[1]
        m[0] = m[1]
        m[1] = t

    return m[1]


if __name__ == "__main__":
    n = int(input())
    print(f"{f(n)}\n")
