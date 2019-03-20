//
//  initialization.h
//  graph
//
//  Created by Yao Zhou on 2019/3/20.
//  Copyright © 2019 Yao Zhou. All rights reserved.
//

#ifndef initialization_h
#define initialization_h

using namespace std;

int initialization(int argc, char **argv , parameter * para)
{
    // object: 对命令行输入的参数进行处理，并传递给 para;
    //
    
//    if (argc < 2 ) {help0(); return 0;}
    
    for(int i = 0; i < argc ; i++)
    {
        string flag = argv[i] ;
        
        flag = replace_all(flag,"--","");
        //        cout << flag << endl;
        if (flag  == "gff3" ||  flag  == "i" || flag == "inFile" || flag == "file")
        {
            if(i + 1 == argc) {LogLackArg(flag); return 0;}
            i++;
            para -> inGff = argv[i];
            
        }
        else if (flag  == "model")
        {
            if(i + 1 == argc) {LogLackArg(flag); return 0;}
            i++;
            para -> model = argv[i];
        }
        else if (flag  == "type")
        {
            if(i + 1 == argc) {LogLackArg(flag); return 0;}
            i++;
            para -> type = argv[i];
        }
        else if (flag == "help"  ||  flag == "h")
        {
            help0();
            return 0;
        }
        else
        {
            //            cerr << "UnKnow argument -"<<flag<<endl;
            //            return 0;
        }
    }
    if  ( ( (para -> model).empty() &&  (para->type).empty() )  )
    {
        cerr << "lack argument for the must" << endl ;
        return 0;
    }
    return 1 ;
}

#endif /* initialization_h */
