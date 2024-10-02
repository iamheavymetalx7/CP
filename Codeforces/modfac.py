mod = int(1e9)+7;


def modfac(n,mod):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= mod
        factorials.append(f)
    inv = pow(f,mod-2,mod)
    inverse = [1 for i in range(n+1)]
    inverse[n] = inv
    for i in range(n,1,-1):
        print(i)
        inv*=i
        inv%=mod
        inverse[i-1] = inv
    return factorials,inverse

fac,inv = modfac(10,mod)
print(fac)
print(inv)