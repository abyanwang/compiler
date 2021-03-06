#include <iostream>
#include <fstream>
#include <vector>
#include "core/Scanner.cpp"
#include "core/Utils.cpp"
#include "core/Log.h"
#include "core/Parser.cpp"
#include "core/TokenStream.h"
#include "core/TreeNode.cpp"
using namespace std;

int main(int argc,char* argv[]) {
	if(argc == 1){
    	puts("添加文件");
    	return 0;
	}
    if(argc > 2){
    	puts("一次只能解析一个文件");
		return 0; 
	} 
    Log log(cerr);
    ifstream fin(argv[1]);
//    if(argv[1][4] != '1')freopen("test_out.txt","w",stdout);
//	else freopen("test1_out.txt","w",stdout);  
    try {
        auto list = Scanner::scan(fin, log);
        TokenStream stream(list);
        Parser parser(stream, log);

        parser.getRootTreeNode()->print(cout);
    } catch (const string& err) {
        cerr << endl << err << endl;
    }
}
