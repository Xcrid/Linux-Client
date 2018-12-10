// The MIT License (MIT)
//
// Copyright (c) 2015 THINGER LTD
// Author: alvarolb@gmail.com (Alvaro Luis Bustamante)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "thinger/thinger.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace protoson;
using namespace std;
#define USER_ID             "YOUR_USER_ID"
#define DEVICE_ID           "YOUR_DEVICE_ID"
#define DEVICE_CREDENTIAL   "YOUR_DEVICE_CREDENTIAL"
#define Wifi_ssid
#define Wifi_password


     nlohman::json json;
thinger_device thing(USER_ID, DEVICE_ID, DEVICE_CREDENTIAL)


int main(int argc, char *argv[])
{
    while(true){
    
    thing.handle();
    usleep(30000);
    vector<string> tableau;
    stringstream ss;
    string path = "/path/to/directory";
    for (auto & p : filesystem::directory_iterator(path))
    { tableau.push_back(p);}
    for (int i=0;i<tableau.size();i++){
        ss << path << tableau[i] ;
    ifstream my_file(ss.c_str());
    json << my_file;
    remove(ss.c_str());
  //nlohmann::to_pson(j, value);
    //psonArray.push_back(value);
    //jsonArray.push_back(j);}
    thing.stream(thing["donnees"]);}
     thing["donnees"] >> [] (pson &out) { 
              out["nom"]=  (const char*) json[i]["string"];
              out[""]=  hhhhhh;
                }();
    
    jsonArray.clear();}

return 0;

   
}
