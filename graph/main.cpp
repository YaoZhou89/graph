//
//  main.cpp
//  graph
//
//  Created by Yao Zhou on 2019/3/20.
//  Copyright © 2019 Yao Zhou. All rights reserved.
//

// 想要调用库，使用 include;
// 调用系统文件
#include <iostream>

// 调用自己写的头文件（file.h)

// include文件的顺序是有影响的，可以尝试把 help.h放到最后一位，看看能否编译
#include "Header.h"
#include "help.h"
#include "baseFunctions.h"
#include "DataClass.h"
#include "initialization.h"
#include "FileFunctions.h"

// 这行加入后，调用标准库就写点,比如，不加入下面的这行，往屏幕输出就是 std::cout； 加了这行，就可以直接写 cout;
using namespace std;

/* 接下来的代码，主要是对gff3文件进行处理。
 主要任务如下：
 1. 统计这里面总计有多少个基因？
 2. 其中有多少个基因是存在多个转录本的？
 3. 哪个基因最长，长度是多少？
 4. 哪个基因的转录本最多，最多的有多少条？
*/
// main函数是程序的主入口，程序进入的大门
int main(int argc, char * argv[]) {
    //标准输出到屏幕，使用 cout; （这是文件注释的第一种方式）
    help0();
    cout << "Hello, World!\n";
    // 反斜杠\n表示回车键，或者使用endl; 其他常用的是tab隔开, \t；
    cout << "Welcome to C++!  Enjoy your first journey" << endl;
    
    /* 文件注释的第2种方式
     基本要求：写代码，一定要有注释。每个函数，类是用来做什么的；输入参数的含义是什么等等；
     */
    
    //*****使用clock进行计时，可方便对某段代码的运行时间进行分析*****//
    // 记录起始时间；
    clock_t start;
    double duration;
    start = clock();
    
//    parameter *para = new parameter(0); // parameter是我们自己定义的类，para是我们新创建的一个对象；
    parameter *para = new parameter();
    // 对命令行输入的参数进行处理；并检查命令行输入是否合法，不合法就调出。
    // 调用intialization的时候，就已经对参数进行处理了，如果正常则返回值为1，如果异常，则返回值为0；
    if ( (initialization(argc, argv, para) == 0) )
    {
        delete para;
        return 1 ;
    }
    
    if (!(para->inGff).empty())
    {
        if ((para -> model).empty()){
            cerr << "model should be specified! Please check" << endl; ;
        }else if((para -> model) == "gff3"){
            if((para->type) == "gene"){
                // 调用 gene 这个函数；
                gene(para);
/*###
 */
            }else if ((para->type) == "transcript"){
                // 调用 transcript这个函数；
                transcript(para);
                
            }else{
                cerr << "type not recgonized! Please check!" << endl;
            }
        }
    }
    
    // 记录程序终止时间；
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"Finished in "<< duration <<" sec " << '\n';
    
    return 0;
}
