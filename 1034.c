#include<stdio.h>
//测试点真他妈的贱，居然要用long long 才能过！！！
typedef struct _rational_number
{
    long long k;
    long long a;
    long long b;
}RationalNumber; // k + a/b

long long gcd(long long a, long long b)
{
    long long m;
    while( a % b)
    {
        m = a;
        a = b;
        b = m % b;
    }
    return b;
}
void formatRN(RationalNumber *pRN)
{
    if(pRN->b == 0)
        return;
        
    int m = gcd(pRN->a, pRN->b);
    
    pRN->a /= m;
    pRN->b /= m;
    
    if(pRN->b < 0)
    {
        pRN->a = -pRN->a;
        pRN->b = -pRN->b;
    }
    
    pRN->k = pRN->a / pRN->b;
    pRN->a = pRN->a % pRN->b;
    
    if(pRN->k < 0)
    {
        pRN->a = -pRN->a;
    }
}
void outRN(RationalNumber rn)
{
    if(rn.k < 0 )
    {
        printf("(%lld",rn.k);
        if(rn.a == 0) printf(")");
        else printf(" %lld/%lld)",rn.a, rn.b);
    }
    else if( rn.k == 0 && rn.a < 0)
    {
        printf("(%lld/%lld)",rn.a, rn.b);
    }
    else if(rn.k == 0 && rn.a == 0){
        printf("0");
    }
    else if(rn.k == 0 && rn.a > 0)
    {
        printf("%lld/%lld",rn.a, rn.b);
    }
    else if (rn.k > 0 && rn.a == 0) {
        printf("%lld",rn.k);
    }
    else {
        printf("%lld %lld/%lld",rn.k, rn.a , rn.b);
    }
    
}

void operate(RationalNumber A, RationalNumber B, char op, RationalNumber *pC)
{
    switch (op) {
        case '+':
            pC->a = A.a*B.b + A.b*B.a;
            pC->b = A.b*B.b;
            break;
        case '-':
            pC->a = A.a*B.b - A.b*B.a;
            pC->b = A.b*B.b;
            break;
        case '*':
            pC->a = A.a*B.a;
            pC->b = A.b*B.b;
            break;
        case '/':
            pC->a = A.a*B.b;
            pC->b = A.b*B.a;    
        default:
            break;
    }
}

int main()
{
    RationalNumber A, B, radd,rsub,rmuli,rdivi;
    
    scanf("%lld/%lld %lld/%lld",&A.a, &A.b, &B.a, &B.b);
    operate(A,B,'+',&radd);
    operate(A,B,'-',&rsub);
    operate(A,B,'*',&rmuli);
    if(B.a != 0)
    {
        operate(A,B,'/',&rdivi);
        formatRN(&rdivi);
    } 
    
    formatRN(&A);formatRN(&B);formatRN(&radd);
    formatRN(&rsub);formatRN(&rmuli);
    
    outRN(A);printf(" + ");outRN(B);printf(" = ");outRN(radd);printf("\n");
    outRN(A);printf(" - ");outRN(B);printf(" = ");outRN(rsub);printf("\n");
    outRN(A);printf(" * ");outRN(B);printf(" = ");outRN(rmuli);printf("\n");
    outRN(A);printf(" / ");outRN(B);printf(" = ");
    if(B.k==0 && B.a == 0)
    {
        printf("Inf\n");
    }
    else {
        outRN(rdivi);
        printf("\n");
    }
    
}









