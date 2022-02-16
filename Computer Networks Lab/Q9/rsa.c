#include<stdio.h>
#include<math.h>

int gcd(int a, int h){
    int temp;
    while(1){
        temp = a%h;
        if(temp==0) return h;
        a = h;
        h = temp;
    }
}

int main(int argc, char const *argv[])
{
    printf("-----RSA ALGORITHM-----\n");
    double p,q,n,c,d,phi,e,msg,m,k;

    // take 2 random prime numbers
    p=3;
    q=7;
    n=p*q;
    phi = (p-1)*(q-1);

    // e is for encryption
    e = 2;

    // get a co-prime number for phi
    while(e<phi){
        if(gcd(e, phi)==1)
            break;
        e++;
    }

    k=2;
    
    // d is for decryption
    // d*e = 1+(k*phi)
    d = (1+(k*phi))/e;

    // message to encrypt
    msg = 27;

    // c holds the encrypted message
    // c = (msg^e) mod n
    c = pow(msg, e);
    c = fmod(c, n);

    // m is to find the decrypted message
    // m = c^d mod n
    m = pow(c,d);
    m = fmod(m,n);

    // printing all the values
    printf("Message to be encrypted : %lf\n", msg);
    printf("p = %lf, q = %lf\n", p,q);
    printf("n=%lf\nphi=%lf\n", n, phi);
    printf("e=%lf, d=%lf\n",e, d);
    printf("Encrypted message : %lf\n", c);
    printf("Decrypted message : %lf\n", m);
    printf("\n----------\n");
    return 0;
}
