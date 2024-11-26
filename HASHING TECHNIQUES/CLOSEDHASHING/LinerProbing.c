
//CLOSED HASHING:1. LINER PROBING
//h(x)=x%size ---> h1(x)=(h(x)+f(i))%size i.e where f(i)=i and i takes values from i=0,1,2.....
int hash(int key)
{
    return key%SIZE;
}

int probe(int H[],int key)
{
    int index=hash(key);
    int i=0;

    while(H[(index+i)%SIZE]!=0)//were there are elements
         i++;
    return (index+i)%SIZE;//return free space
}
void Insert(int H[], int key)
{
    int index=hash(key);

    if(H[index]!=0)//if it's occupied
    {
        index=probe(H,key);
    }
    H[index]=key;
}

int search(int H[], int key)
{
    int index=hash(key);
    int i=0;

    while(H[(index+i)%SIZE]!=key && H[(index+i)%SIZE]!=0)//while key is not found loop
        i++;
    if(H[(index+i)%SIZE]==0)
     return -1;
    return (index+i)%SIZE;

    

}
int main(){
    int HT[10]={0};

    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);
    printf("\nkey found at %d\n", search(HT,27));
    return 0;
}