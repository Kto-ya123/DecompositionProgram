#include"query.h"
istream& operator >> (istream& is, Query& q) {
    string typeQuery;
    is >> typeQuery;
    q.stops.clear();
    if(typeQuery == "NEW_BUS"){
        int number;
        q.type = QueryType::NewBus;
        is >> q.bus;
        is >> number;
        string stop;
        for(int i(0); i < number; i++){
            is >> stop;
            q.stops.push_back(stop);
        }
    }else if(typeQuery == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }else if(typeQuery == "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }else if(typeQuery == "ALL_BUSES"){
        q.type = QueryType::AllBuses;
    }
    return is;
}
