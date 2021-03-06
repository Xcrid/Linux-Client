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
#define USER_ID            "xcrid"
#define DEVICE_ID           "1"
#define DEVICE_CREDENTIAL   "xcrid0!"
 json j;
thinger_device thing(USER_ID, DEVICE_ID, DEVICE_CREDENTIAL);

int main(int argc, char *argv[])
  {time_t storage = time(NULL);

    while(true){

		thing.handle();
		time_t current = time(NULL);
		if (current-storage>3600) {
			ifstream my_file("/home/pi/Documents/dataToSend.json");
			j = json::parse(my_file);
			thing.stream(thing["lumiere"]);
			storage = time(NULL);
			j["nbrClients"] = 0;
			ofstream file("/home/pi/Documents/dataToSend.json");
			file << j;
			file.close();
		}
    
     thing["lumiere"] = [](pson& in, pson& out) {
              out["nbrClients"]=  (int) j["nbrClients"];
                }; 
    }
return 0;

   
}
