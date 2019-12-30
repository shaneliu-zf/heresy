#include<iostream>
#include<fstream>
#define size 10000000000
using namespace std;

char str[size];
string x;
string y;

void readfile(char path[]){
    fstream file;
    file.open(path, ios::in);
    if(!file){
            cerr<<"no such file or directory:'"<<path<<"'"<<endl;;
            exit(1);
    }
    file.read(str,size);
    x=str;
    file.close();
}
void trans(){
    for(int i=0;i<x.length();i++){
        y+=x[i];
        if(x[i]=='{'){
            if(x[i-1]=='\n' || ((x[i-1]==' ')&&(x[i-2]==' ')) ){
                for(int j=y.length()-2;(y[j]!=')'&&(y[j]<'a'||y[j]>'z')&&(y[j]<'A'||y[j]>'Z')&&y[j]!='_')&&(y[j]<'0'||y[j]>'9');j--){
                    y.erase(y.begin()+j);
                }
            }
        }
    }
}
void writefile(char path[]){
    fstream file;
    file.open(path, ios::out|ios::trunc);
    file.write(y.c_str(),y.length());
    file.close();
}
int main(int argc,char *argv[]){
    if(argc==1){
        cerr<<"error: no input files"<<endl;
        exit(1);
    }
    else if(argc!=2){
        cerr<<"error: argc wrong"<<endl;
        exit(1);
    }
    else{
        readfile(argv[1]);
        trans();
        writefile(argv[1]);
    }
    return 0;
}
