def soe(n , prime):
    for i in range(0, n + 1):
        prime[i] = True;
    
    p = 2
    while(p*p <= n):
        if(prime[p] == True):
            for i in range(p*2 , n + 1 , p):
                prime[i] = False
    
        p = p + 1


def mersene(n):
    prime = [0]*(n + 1)
    soe(n , prime)

    k = 2
    while(((1 << k) - 1) <= n):
        num = (1 << k) - 1
        if(prime[num]):
            print("2^" , k , " - 1" , " is mersenne prime\n")
        k = k + 1