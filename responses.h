#ifndef RESPONSES_H_INCLUDED
#define RESPONSES_H_INCLUDED
#include<iostream>

using  namespace std;
struct BusesForStopResponse {
    string info;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string info;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    string info;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

#endif // RESPONSES_H_INCLUDED
