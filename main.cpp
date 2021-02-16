#include <cstdio>
#include <iostream>
#include <fstream>
#include <yarp/os/Bottle.h>
#include <yarp/os/Port.h>
#include <yarp/os/Network.h>

using namespace std;
using yarp::os::Bottle;
using yarp::os::Port;
using yarp::os::Network;

int main()
{
    ofstream testingFile;
    testingFile.open("ensayos.csv", ofstream::out);
    testingFile << "Timestamp" << "," << "Roll" << "," << "Pitch" << endl; // Headers

    Bottle bot;
    string bot_str;
    Port input;
    Network yarp;
//    yarp.init();
    input.open("/in");
    cout << "Port /in opened" << endl;

    Network::connect("/softimu/out", "/in");
    cout << "Ports /in and /softimu/out connected" << endl;

    double start = yarp::os::Time::now();

    while(input.read(bot)){
        printf("Got message: %s\n", bot.toString().c_str());
        bot_str = bot.toString().c_str();
        testingFile << yarp::os::Time::now()-start << "," << bot_str << endl;
    }

    testingFile.close();
    input.close();
    return 0;
}




