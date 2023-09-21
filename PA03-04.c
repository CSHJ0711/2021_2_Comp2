//PA03
#include <stdio.h>
void sort3(int a, int b, int c){
    int temp;
    
    if(a >= b)
    {
        temp = b; 
        b = a; 
        a = temp; 
    }
    if(b >= c)
    {
        temp = c; 
        c = b; 
        b = temp; 
    }
    if(a >= b)
    {
        temp = b; 
        b = a; 
        a = temp; 
    }
 
    printf("[Sorted Result] s: %d, m: %d, b: %d\n",a, b, c);
}
int main (void)
{
        
    int x=0, y=0, z=0;
    
    puts("Enter three integer numbers (x,y,z)");
    printf("x: "); scanf("%d", &x);
    printf("y: "); scanf("%d", &y);
    printf("z: "); scanf("%d", &z);
    sort3(x,y,z);
    
}



//PA04
#include <stdio.h>

void sort3(int a, int b, int c, int *ss, int *sm, int *sb){
    int temp;
    
    if(a >= b)
    {
        temp = b;
        b = a;
        a = temp;
    }
    if(b >= c)
    {
        temp = c;
        c = b;
        b = temp;
    }
    if(a >= b)
    {
        temp = b;
        b = a;
        a = temp; 
    }
    *ss = a;
    *sm = b;
    *sb = c;
}
int main (void)
{
        
    int x=0, y=0, z=0;
    int ss, sm, sb;
    
    puts("Enter three integer numbers (x,y,z)");
    printf("x: "); scanf("%d", &x);
    printf("y: "); scanf("%d", &y);
    printf("z: "); scanf("%d", &z);
    sort3(x,y,z, &ss, &sm, &sb);
    printf("[Sorted Result] s: %d, m: %d, b: %d\n",ss, sm, sb);
    
}


