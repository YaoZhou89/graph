//
//  Header.h
//  graph
//
//  Created by Yao Zhou on 2019/3/20.
//  Copyright © 2019 Yao Zhou. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// mac里的hash_map是在 ext/hash_map，所以需要如下的调用：
#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif

#include <set>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <zlib.h>
#include "./include/gzstream/gzstream.c"
#include <algorithm>
#include <functional>
#include <random>
#include <regex>

#endif /* Header_h */
