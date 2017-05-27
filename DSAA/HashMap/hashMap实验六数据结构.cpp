#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

class hashMap{
    
    
    vector<string> nameSet{"yuruijie","lupengwei","lanshiying","zhangshuai","chenyuxiao","caoxipeng","fanxinlong","luozhanxiang","fengjianhao","yangxiaoqi","chenrunze","mahongce","mazhe","zhaxinanjie","yangyuanzhen","caizhongmou","hanruiqing","zoudi","zhangyilei","chengyihan","chenkaijie","linwenyi","xuzhenhui","liuyao","dengqi","wanghan","zhangzhanhong","yangjiayu","yangzhongjie","liuhailun"};//the dataset of the name
    static const int m=50;//the size of the hashtable
    static const int prime = 43;
    int hashtable[m]={0};//the hashtable
    int hashlen[m]={0};//the hash len
    int keySet[m]={0};//the key value array
    int addressSet[m]={0};//the addresss array
    
public:
    int convertNameToInt(string _name){//convert the string of name to an key
        int key=0;
        for(char i:_name){
            if(i!=' '){
                key+=i;
            }
        }
        return key;
    }
    
    void initialize(){//create the hash table
        for(int i=0;i<nameSet.size();++i){
            int key=convertNameToInt(nameSet[i]);//calculate the key value of the string
            keySet[i]=key;//save the key
            addressSet[i]=hash(key);//save the address
            hashlen[i]=searchHashTable(nameSet[i]);
        }
        double asl=0;
        cout.width(15);
        cout<<"name";
        cout.width(10);
        cout<<"key";
        cout.width(10);
        cout<<"address";
        cout.width(10);
        cout<<"searchlen"<<endl;
        for(int i=0;i<nameSet.size();++i){
            cout.width(15);
            cout<<nameSet[i];
            cout.width(10);
            cout<<keySet[i];
            cout.width(10);
            cout<<addressSet[i];
            cout.width(10);
            cout<<hashlen[i]<<endl;
            asl+=hashlen[i];
        }
        cout<<endl;
        asl/=nameSet.size();//the average search length
        cout<<"the asl(average search length) is "<<asl<<endl;
    }
    
    int hash(int key){//hash the key value
        int address=key%prime;
        while(hashtable[address]!=0) address++;
        hashtable[address]=key;
        return address;
    }
    
    int searchHashTable(string name){//search the name and return the address
        int key=convertNameToInt(name);
        int searchlen=0;
        int address = key%prime;
        while(hashtable[address]!=0){
            searchlen++;
            if(hashtable[address]==key) return searchlen;
            address++;
        }
        return -1;
    }
    
    void test(){//the test program to search a name in the hashTable and return the search len
        initialize();
        while(1){
            cout<<"enter the name you want to search"<<endl;
            string searchElement;
            cin>>searchElement;
            int ans=searchHashTable(searchElement);
            cout<<"the key value is "<<convertNameToInt(searchElement)<<endl;
            if(ans==-1) cout<<"not found"<<endl;
            else cout<<"it is found , the search len is "<<ans<<endl;
        }
    }
};
int main(){
    hashMap nameMap;
    nameMap.test();
    return 0;
}


