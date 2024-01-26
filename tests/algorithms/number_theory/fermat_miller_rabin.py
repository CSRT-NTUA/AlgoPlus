import sys
import time
import random

def power(x, y, p):
    ans = 1
    
    x = x % p
    while(y > 0):
        if(y & 1):
            ans = (ans * x) % p
        
        y = y >> 1
        x = (x * x) % p
    
    return ans

def prime_check(n , k):
    if(n == 1 or n == 4):
        return False
    if(n == 2 or n == 3):
        return True
    else:
        for i in range(k):
            a = random.randint(2 , n - 2)

            if(power(a,n-1,n) != 1):
                return False
    return True

def prime_fermat(n) -> bool:
    if(n <= 3):
        return n > 1
    if(n % 2 == 0 or n % 3 == 0):
        return False
    
    limit = int(n ** 0.5)
    for i in range(5 , limit + 1, 6):
        if(n % i == 0 or n % (i + 2) == 0):
            return False
    return True


def millen_rabin(w , n) -> bool:
    a = 2 + random.randint(1 , n-4)
    x = power(a , w,  n)

    if(x == 1 or x == -1):
        return True
    
    while(w != n-1):
        x = (x*x) % n
        w *= 2
        if(x == 1): return False;
        if(x == n-1): return True;
    
    return False


def primality_check(n , k) -> bool:
    if(n <= 1 or n == 4):
        return False
    if(n <= 3):
        return True;
    
    w = n - 1
    while(~w & 1):
        w //= 2
    for i in range(k):
        if(millen_rabin(w , n) == False):
            return False
    return True
