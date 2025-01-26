#include <stdio.h>
#include <stdbool.h>

int my_strlen(char *str)
{
    int i=0; 
    for(i=0;str[i]!='\0';i++)
    {
    }
    return i;
}
void swap(char *s, char *s1)
{
    char temp=*s;
    *s=*s1;
    *s1=temp;
    
}
void str_permutation(char s[], int low, int high)
{   
    int i;
    if(low==high)//if low comes to the equality of "high", print that permutation
    {
        printf("%s\n",s);
    }
    for(i=low;i<=high;i++)//loop the string from were low starts
    {
        swap(&s[low],&s[i]);// switch character at low and high
        str_permutation(s,low+1,high);
        swap(&s[low],&s[i]);//switch back the characters after returning
    }
}
void str_permutations(char s[],int k)
{
    static int included[30]={0};//this is mantained through each function call/flag array
    static char result[30];//this is mantained through each function call

    if(s[k]=='\0'){
        result[k]='\0';
        printf("%s\n",result);

    }else{
        for(int i=0;s[i]!='\0';i++)//loop through the entire string
        {
            if(included[i]==0)//if a character is '0', it means you include it in the result
            {
                result[k]=s[i];
                included[i]=1;//after including it mark that position by'1' in the flag array
                str_permutations(s,k+1);
                included[i]=0;//when the control comes back, mark '0' in the flag array, continue sanning.
            }
       }
    }

}
void if_anagram(char s[],char s1[])//handles lower or Upper case letter
{//we can use bits also, but there must be no duplicates
    int H[26]={0},i,j;
    if(my_strlen(s)==my_strlen(s1))
    {
        for(i=0;s[i]!='\0';i++)
        {
            H[s[i]-97]+=1;
        }
        for(j=0;s1[j]!='\0';j++)
        {
            H[s1[j]-97]-=1;
            if(H[s1[j]-97]<0){
                printf("%s and %s are not anagrams\n",s,s1);
                break;
            }
                
        }
        
        if(s1[j]=='\0')
            printf("%s and %s are anagrams\n",s,s1);
    }
    else{
        printf("%s and %s are not anagrams\n",s,s1);
    }
    
}
void find_duplicates(char s[])//using bits
{
    int H=0,X=0,i;
    for(i=0;s[i]!='\0';i++)
    { 
        X=1;
        X=X=1<<(s[i]-97);
        if((X&H)>0)
        printf("%c is a duplicate\n", s[i]);
        else
        H=X|H;

    }
}
void check_duplicates(char s[])//using a hash table
{// same case letters
    int H[26]={0},i;
    for(i=0;s[i]!='\0';i++)
    {
        H[s[i]-97]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
            printf("%c appears %d times\n", i+97, H[i]);
        
    }
}
void check_palindrome(char s[])//the case must be same for all character
{// does not utilize am extra array
//can also be archived by twi arrays, reverse array and compare
    int i, j;
    for(j=0;s[j]!='\0';j++){};
    j=j-1;
    for(i=0,j;i<j&&i!=j;i++,j--)
    {
        if(s[i]!=s[j])
        break;
    }
    if(i==j || i>j) printf("%s is a palindrome",s);
    else printf("%s is not a palindrome",s);
}
void compare_strings(char s[], char s1[])//the strings mudt be in the same case
{
    int i,j;
    for(i=0,j=0;s[i]!='\0'&&s1!='\0';i++,j++)
    {
        if(s[i]!=s1[j])
        break;
    }
    if(s[i]==s1[j]) printf("%s and %s are equal", s,s1);
    else if(s[i]<s1[j]) printf("%s, is smaller",s);
    else printf("%s is greater", s1);
}
void reverse_string1(char s[])//uses no extra array
{
  int i,j;
  char temp;
  for(j=0;s[j]!='\0';j++)
  {}
  j=j-1;//take j upon the last char
  for(i=0,j;i<j;i++,j--)
  {
    temp=s[i];
    s[i]=s[j];
    s[j]=temp;
  }
  printf("%s",s);
}
void reverse_string(char s[])
{
    int len=my_strlen(s);
    char s1[len];
    int i,j;
    for(i=0;s[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;i>=0;i--,j++)
    {
        s1[j]=s[i];
    }
    s1[j]='\0';
    printf("%s",s1);
}

bool match_char(char ch, char *pattern)
{
    while(*pattern)
    {
        if(ch==*pattern){
            return true;
        }
        pattern++;
    }
    return false;
}

bool validate_password(char *password)
{
    char *special_chars = "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";
    bool has_upper=false;
    bool has_lower=false;
    bool has_digit=false;
    bool has_special=false;

    int lenght=my_strlen(password);
    if(lenght<8)
    {
        return false;
    }

    for(int i=0; password[i]!='\0';i++)
    {
        char ch=password[i];
        
        if(ch>='A' && ch<='Z'){
            has_upper=true;
        }else if(ch>='a' && ch<='z'){
            has_lower=true;
        }else if(ch>='0' && ch<='9'){
            has_digit=true;
        }else if(match_char(ch,special_chars)){
            has_special=true;
        }else if(ch==' '){
            return false;
        }

    }
    return has_upper&&has_lower&&has_digit&&has_special;

}

void smallCase(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {

            s[i] = s[i] - 32;
        }
    }
    printf("%s\n", s);
}

 int wordCount(char s[])
 {
    int count=1,i;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i-1]!=' ' && s[i]==' ')
        {
            count++;
        }
    }
    return count;
}
int main(){
    
    //char s[]="howzre you";
   // printf("%d",wordCount(s));
   // smallCase(s);
//    char *password = "MyStrong@123";

//     if (validate_password(password)) {
//         printf("Password is valid.\n");
//     } else {
//         printf("Password is invalid.\n");
//     }
//  char A[]="pythone";
//  reverse_string1(A);
    
    // char s[]="painter";
    // char s1[]="painter";
    // compare_strings(s,s1);
   // check_palindrome("painter");
   //check_duplicates("finding");
   //find_duplicates("finding");
   //if_anagram("mississippi","imississipp");
   //str_permutations("ABC",0);
   char str[]="ABC";
   str_permutation(str,0,2);
    return 0;
}