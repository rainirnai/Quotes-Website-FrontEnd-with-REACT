#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

/**Shift Cipher**/

void shift_cipher(string s){
    int n=s.length();
    srand(time(0));
    int key=rand();
    key=key%26;
    cout<<"The secret key is "<<key<<endl;
    cout<<"The cipher text is"<<endl;
    for(int i=0;i<n;i++){
        if(s[i]!=32){
            int a=s[i]-'a';
            a=((a+key)%26)+'a';
            printf("%c",a);       
        }
    }
    cout<<endl;
} 

/**End**/

/**Vigenere Cipher**/

string generatelongkey(string s,string key){
    int x=s.size();
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == s.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string generateciphertext(string s, string key){
    string ciphertext;
    int n=s.length();
    for(int i=0;i<n;i++){
        char x=(s[i]-'a')%26;
        x=x+key[i];
        ciphertext.push_back(x);
    }
    return ciphertext;
}

void vigenere_cipher(string temp){
    int n=temp.length();
    string s=""; 
    for(int i=0;i<n;i++){
        if(temp[i]!=32){
            s.push_back(temp[i]);
        }
    }
    cout<<"Enter your key"<<endl;
    string key;
    while(getline(cin,key)){
        //cout<<key<<endl;
        break;
    }
    while(key.length()>s.length()){
        cout<<"Enter a key equal or smaller in length than the ciphertext"<<endl;
        while(getline(cin,key)){
            cout<<key<<endl;
            break;
        }
    }
    string longkey=generatelongkey(s,key);
    string ciphertext=generateciphertext(s,longkey);
    cout<<"Vigenere cipher key is: "<<longkey<<endl;
    cout<<"Cipher text is: "<<ciphertext<<endl;
}

/** End **/

/**Playfair Cipher**/
int removespaces(string plain,int ps){
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

void toLowerCase(string plain,int ps){
    for(int i=0;i<ps;i++){
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int prepare(string str,int ptrs){
    if (ptrs % 2 != 0) {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
    }
    return ptrs;
}

void generateKeyTable(string key, int ks, char keyT[5][5])
{
    int i, j, k, flag = 0;
    int dicty[26]={0};

    for (i = 0; i < ks; i++) {
        if (key[i] != 'j')
            dicty[key[i] - 97] = 2;
    }
 
    dicty['j' - 97] = 1;
 
    i = 0;
    j = 0;
 
    for (k = 0; k < ks; k++) {
        if (dicty[key[k] - 97] == 2) {
            dicty[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
 
    for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}

void search(char keyT[5][5], char a, char b, int arr[])
{
    int i, j;
 
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';
 
    for (i = 0; i < 5; i++) {
 
        for (j = 0; j < 5; j++) {
 
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a){
    return (a % 5);
}

string encrypt(string str, char keyT[5][5], int ps)
{
    int i, a[4];
 
    for (i = 0; i < ps; i += 2) {
 
        search(keyT, str[i], str[i + 1], a);
 
        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
    return str;
}
 
string encryptbyPlayfairCipher(string s, string key){
    char ps,ks,keyT[5][5];
    
    ks=key.length();
    ks=removespaces(key,ks);
    toLowerCase(key,ks);
    
    ps = s.length();
    toLowerCase(s, ps);
    ps = removespaces(s, ps);
    
    ps=prepare(s,ps);
    
    generateKeyTable(key, ks, keyT);
    
    return encrypt(s, keyT, ps);
    
}

void playfair_cipher(string s){
    string key;
    cout<<"Enter your key for Playfair cipher "<<endl;
    while(getline(cin,key)){
        cout<<key<<endl;
        break;
    }
    while(key.length()>s.length()){
        cout<<"Enter a key equal or smaller in length than the ciphertext"<<endl;
        while(getline(cin,key)){
            cout<<key<<endl;
            break;
        }
    }
    string ecip=encryptbyPlayfairCipher(s,key);
    cout<<"Playfair Cipher text is: "<<ecip<<endl;
}

/**End**/

/*One Time Pad*/
void onetimepad(string s)
{
    int n=s.length();
    srand(time(NULL));
    int arr[n];
    cout<<"Your secret key is: ";
    for(int i=0;i<n;i++){
        arr[i]=rand()%10;
        cout<<arr[i];
    }
    cout<<endl;
    char ciphertext[n];
    cout<<"Your One Time Pad ciphertext is"<<endl;
    for(int i=0;i<n;i++){
        ciphertext[i]=((s[i]^arr[i])%26)+'a';
        printf("%c",ciphertext[i]);
    }
    cout<<endl;
}

/*End*/

int main()
{
    int choice=1;
    string s;
    cout<<"Enter your message in plain text "<<endl;
    while(getline(cin,s)){
        //cout<<s<<endl;
        break;
    }
    /*cout<<"We can encrypt by the following ciphers: "<<endl;
    cout<<"1.Shift Cipher"<<endl;
    cout<<"2.Vigenere Cipher"<<endl;
    cout<<"3.Playfair Cipher"<<endl;
    cout<<"4.One Time Pad"<<endl;
    cout<<"Enter your choice number"<<endl;
    cin>>choice;
    cout<<"You have entered "<<choice<<endl;
    switch(choice){
        case 1:
            shift_cipher(s);
            break;
        case 2:
            vigenere_cipher(s);
            break;
        case 3:
            playfair_cipher(s);
            break;
        default:
            cout<<"Please enter a valid choice";
    }*/
    cout<<"/***Shift cipher****/"<<endl;
    shift_cipher(s);
    cout<<"/***End***/"<<endl;
    cout<<"/***Vigenere cipher***/"<<endl;
    vigenere_cipher(s);
    cout<<"/***End***/"<<endl;
    cout<<"/***Playfair cipher***/"<<endl;
    playfair_cipher(s);
    cout<<"/***End***/"<<endl;
    cout<<"/***One Time Pad***/"<<endl;
    onetimepad(s);
    cout<<"/***End***/"<<endl;
    return 0;
}





