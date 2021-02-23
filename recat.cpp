#include <iostream>
#include <fstream>

using namespace std;

void reverse(char* buffer, int bufferLen){
    for (int i = 0; i< bufferLen / 2; i++){
        char temp = buffer[i];
        buffer[i]=buffer[bufferLen -i -1];
        buffer[bufferLen -i -1]=temp;
    }
}

int main(int argc, char* argv[]){
    if(argc != 1){

        ifstream ifs(argv[1], ios_base::ate | ios::binary);//ファイルオープン
        //ポインタ位置を取得
        int bufferLen = ifs.tellg();
        //ポインタ位置を先頭に移動
        ifs.seekg(0,ifstream::beg);
        //ファイルの内容を配列に読み込み
        char *buffer = new char[bufferLen];
        ifs.read(buffer,bufferLen);
        
        //文字列を正順に表示
        //cout<<buffer<<endl;

        //逆順表示
        reverse(buffer,bufferLen);
        cout<<buffer<<endl;
    } else {
        cout << "You need to supply a filename" << endl;
    }
    exit(0);
}