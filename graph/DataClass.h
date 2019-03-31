//
//  DataClass.h
//  graph
//
//  Created by Yao Zhou on 2019/3/20.
//  Copyright © 2019 Yao Zhou. All rights reserved.
//

#ifndef DataClass_h
#define DataClass_h

using namespace std;
class parameter {
//定义了一个类，叫做parameter，用来对命令行的输入进行处理。
//这个类里没有私有成员，
private:
    int testP = 0;
    
public:
    string inFile;
    string outFile;
    string inGff;
    string model;
    string type;
    string geneID;
    // 一个没有参数的构造函数，可以使用它对参数进行初始化
    parameter(){
        inFile = "";
        inGff = "/Users/yaozhou/Downloads/tomato1.gff3.gz";
        outFile = "";
        model = "gff3";
        type = "gene";
        geneID = "";
        cout << "empty" << endl;
        cout << "testP is:\t" << testP << endl;
    }
    parameter(int i){
        cout << "input number is:\t" << i << endl;
    }
};

class gff3 {
    
private:
   
    
public:
    // 了解set,map,hash_map, Multi_set等，选择合适的容器
    int geneNum;
    int transcriptNum;
    map<string, vector<int>> geneLength;
    map<string, int> transprit;
    map<string,int> exonNumber;
    set<string> genes;
    // 定义了一个空参数构造函数和一个有参数的构造函数；
    gff3(string inFile,string geneID){
        cout << "inFile is:\t" << inFile << endl;
        readGff(inFile);
        cout << "gene number is:\t" << geneNum << endl;
        cout << "transcript number is:\t" << transcriptNum << endl;
        cout << "Gene "<< geneID << "\texon number is:\t" << exonNumber[geneID] << endl;
    }
    
    gff3(){
        cout << "this just is a demo!" << endl;
    }
    
    //定义一个函数对gene进行初始化；
    // 这里没有进行优化，根据你们所学的知识，可以考虑对这里的gene变量进行优化
    
    // void 表示函数没有返回值；
    // 注意这里的geneNum等变量的作用范围（全局变量）；
    void readGff(string inFile){
//        map<string, map<string,vector<int>>> gene;
        igzstream inf (inFile.c_str(),fstream::in);
        if (inf.fail()){
            cerr << "Read gff3 failed!" << endl;
        }
        string line;
        vector<string> ll;
        vector<string> name,IDa;
       
        bool geneReaded = false;
        int exonNum = 0;
        string geneIDpre;
        while (!inf.eof()){
            // 按行读取文件，读入的数据存在line里；
            getline(inf, line);
            if (line.length() < 1) continue; // 有时候会读到空行，直接跳过去，这一步以后不管有没有空行都加上；
            if (line[0] == '#') continue; //这里取的第一位，返回值是char类型，所以==后面用了单引号，不能用双引号；
            if (line.substr(0,1) == "#") continue; //这一行和上一行是同一个含义，但是substr的返回值类型是string,所以==后面用了双引号
            ll.clear(); // 循环中每次使用前，都要清空，否则上次产生的值还在
            split(line, ll," \t"); //对读入的文件进行分割，分割符为tab
            
            // 提取基因的ID，例如，ID=gene:Solyc00g005084.1; 提取后ID为Solyc00g005084
            name.clear();
            IDa.clear();
            split(ll[8],name,".");
            split(name[0],IDa,":");
            string ID = IDa[1]; // while循环里的变量，出了这个循环，就不能用了，注意变量的作用范围
            if (ll[2] == "gene"){
                if(!geneReaded){
                    geneReaded = true;
                }else{
                    exonNumber.insert(map<string,int>::value_type(geneIDpre,exonNum));
                }
                genes.insert(ID);
                exonNum = 0;
                ++geneNum;
                int length = string2Int(ll[4]) - string2Int(ll[3]) + 1;
                if (geneLength.count(ll[2])>0){
                    vector<int> lens = geneLength[ll[2]];
                    lens.push_back(length);
                    geneLength[ll[2]] = lens;
                }else{
                    vector<int> lens;
                    lens.push_back(length);
                    geneLength[ll[2]] = lens;
                }
                geneIDpre = ID;
            }else if (ll[2] == "mRNA"){
                ++transcriptNum;
                genes.insert(ID);
            }else if (ll[2] == "exon"){
                genes.insert(ID);
                exonNum ++;
                ;
            }else if (ll[2] == "cds"){
                continue;
            }else if (ll[2] == "intron"){
                continue;
            }else if (ll[2] == "five_prime_utr"){
                continue;
            }else if (ll[2] == "three_prime_utr"){
                continue;
            }else {
                continue;
            }
            
        }
//        exonNumber.push_back(exonNum);
        exonNumber.insert(map<string,int>::value_type(geneIDpre,exonNum));
    }
    


};
#endif /* DataClass_h */
