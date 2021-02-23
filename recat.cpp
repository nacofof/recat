#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char* argv[]){
    if(argc != 1){

        ifstream ifs(argv[1], ios_base::ate | ios::binary);//ファイルオープン
        //ポインタ位置を取得
        int filesize = ifs.tellg();
        //ポインタ位置を先頭に移動
        ifs.seekg(0,ifstream::beg);
        //ファイルの内容を配列に読み込み
        char *buffer = new char[filesize];
        ifs.read(buffer,filesize);
        
        //文字列を正順に表示
        cout<<buffer<<endl;
    } else {
        cout << "You need to supply a filename" << endl;
    }
    exit(0);
}