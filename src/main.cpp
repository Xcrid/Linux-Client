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
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
using namespace protoson;
using namespace std;
using namespace nlohmann;
#define USER_ID            "amlen"
#define DEVICE_ID           "test00"
#define DEVICE_CREDENTIAL   "111111"
 json j;
thinger_device thing(USER_ID, DEVICE_ID, DEVICE_CREDENTIAL);

int main(int argc, char *argv[])
  {time_t storage = time(NULL);

    while(true){

		thing.handle();
		time_t current = time(NULL);
		ifstream my_file("/",ifstream::in);
		j << my_file;
		if (current-storage>3600) {
			thing.stream(thing["donnees"]);
			storage = time(NULL);}
    
     thing["donnees"] = [](pson& in, pson& out) {
              out["nbrClients"]=  (int) j["nbrClients"];
              out["avPrice"]=  (double) j["avPrice"];
                }; 

return 0;

   
}
