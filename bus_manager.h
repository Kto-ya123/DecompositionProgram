#ifndef BUS_MANAGER_H_INCLUDED
#define BUS_MANAGER_H_INCLUDED
#include<vector>
#include<map>
#include"responses.h"
class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);
    BusesForStopResponse GetBusesForStop(const string& stop);
    StopsForBusResponse GetStopsForBus(const string& bus);
    AllBusesResponse GetAllBuses();
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};
#endif // BUS_MANAGER_H_INCLUDED
