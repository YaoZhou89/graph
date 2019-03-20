//
//  baseFunctions.h
//  graph
//
//  Created by Yao Zhou on 2019/3/20.
//  Copyright © 2019 Yao Zhou. All rights reserved.
//

#ifndef baseFunctions_h
#define baseFunctions_h

#include <vector>

using namespace std;

// 除了double，int等基本的数据类型外，我们可以自己定义新的类型，比如这里我们定义了一个新的类型 叫做lint；
typedef long int  lint ;

inline void  LogLackArg( string  flag )
{
    // objectj: 检查参数是否赋值，如果需要赋值的参数没有赋值，则直接报错调出；
    cerr << "\t\tLack Argument for [ -"<<flag<<" ]"<<endl;
}

inline string &  replace_all(string &  str,const  string &  old_Avalue,const string &  new_Avalue)
{
    // object: 替代函数
    while(true)   {
        string::size_type  pos(0);
        if(   (pos=str.find(old_Avalue))!=string::npos   )
            str.replace(pos,old_Avalue.length(),new_Avalue);
        else   break;
    }
    return   str;
}

inline void split(const string& str,vector<string>& tokens,  const string& delimiters = " ")
{
    // object: 使用特定的分割符分割字符串；
    // input: 需要被分割的字符串，存放分割后结果的vector;以及分隔符；
    // 这里的代码尝试去理解，看不懂也没有关系
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

inline double string2Double(std::string const& s){
    // object: 数字的字符串形式转成double类型
    std::istringstream iss(s);
    double value;
    if (!(iss >> value)) throw std::runtime_error("invalid double: " + s);
    return value;
}

inline double string2Doubleabs(std::string const& s){
    // object: 数字的字符串形式转成double类型，并取绝对值；
    std::istringstream iss(s);
    double value;
    if (!(iss >> value)) throw std::runtime_error("invalid double: " + s);
    if(value<0) value = -value;
    return value;
}

inline double string2Doublepos(std::string const& s){
    // object: 数字的字符串形式转成double类型，小于0的全部为0；
    std::istringstream iss(s);
    double value;
    if (!(iss >> value)) throw std::runtime_error("invalid double: " + s);
    if(value<0) value = 0;
    return value;
}

inline lint string2Int(std::string const& s){
    // object: 数字的字符串形式转成int类型；
    std::istringstream iss(s);
    lint value;
    if (!(iss >> value)) throw std::runtime_error("invalid int");
    return value;
}
inline string Int2String(int const& s){
    // object: int转成string；
    std::string out_string;
    std::stringstream ss;
    if (!(ss << s)) throw std::runtime_error("invalid string");
    out_string = ss.str();
    return out_string;
}

inline double avg ( vector<double>& v )
{
    // object: 检查参数合法性，没有参数返回0；有参数返回1；
    double return_value = 0.0;
    int n = v.size();
    
    for ( int i=0; i < n; i++)
    {
        return_value += v[i];
    }
    
    return ( return_value / n);
}
#endif /* baseFunctions_h */
