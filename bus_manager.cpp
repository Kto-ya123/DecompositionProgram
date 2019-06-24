#include<string>
#include"bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus].clear();
    for (const string& stop : stops) {
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) {
    BusesForStopResponse rezult;
    if (stops_to_buses.count(stop) == 0) {
        rezult.info += "No stop";
    } else {
        for (const string& bus : stops_to_buses[stop]) {
            rezult.info += bus + " ";
        }
        rezult.info += "\n";
    }
    return rezult;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) {
    StopsForBusResponse rezult;
    if (buses_to_stops.count(bus) == 0) {
        rezult.info += "No bus";
    } else {
        for (const string& stop : buses_to_stops[bus]) {
            rezult.info += "Stop " + stop + ": ";
            if (stops_to_buses[stop].size() == 1) {
                rezult.info += "no interchange";
            } else {
                for (const string& other_bus : stops_to_buses[stop]) {
                    if (bus != other_bus) {
                        rezult.info += other_bus + " ";
                    }
                }
            }
            rezult.info += "\n";
        }
    }
    return rezult;
}

AllBusesResponse BusManager::GetAllBuses() {
    AllBusesResponse rezult;
    if (buses_to_stops.empty()) {
        rezult.info += "No buses";
    } else {
        for (const auto& bus_item : buses_to_stops) {
            rezult.info += "Bus " + bus_item.first + ": ";
            for (const string& stop : bus_item.second) {
                rezult.info += stop + " ";
            }
            rezult.info += "\n";
        }
    }
    return rezult;
}
