//strings 

//(a)->concatenate two strings 
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1 = "hi ";
    string str2 = "hello";
    string str3="";
    for(int i=0;i<str1.size();i++){
        str3+=str1[i];
    }

    for(int j=0;j<str2.size();j++){
        str3+=str2[j];
    }

    cout<<str3;

}

//(b)->reverse a string
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "hello world";

    int n = str.size();
    int i = 0;
    while(i<=n/2){
        swap(str[i],str[n-i-1]);
        i++;
    }
    
    cout<<str;
}


//(c)-> delete vovels 

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter string ";

    getline(cin , str);

    int n= str.size();
    string ans ;
    int j=0;
    for(int i=0;i<n;i++){
        if(str[i] != 'a' || str[i] != 'e' || str[i] != 'i' || str[i] != 'o' || str[i] != 'u'){
                ans[j] = str[i];
                j++;
        }
    }
    cout<<ans;
}

//(d)->sort string

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter string ";

    getline(cin , str);
    int n=str.size();

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);
            }
        }
    }
    cout<<str;

}

//(e)->convert uppercase to lower case

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter string ";

    getline(cin , str);
    int n=str.size();

    for(int i=0;i<n;i++){
        if(str[i]>=65 && str[i]<=90){
            str[i]+=32;
        }
    }
    cout<<str;

}