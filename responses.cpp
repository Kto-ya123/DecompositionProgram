#include"responses.h"
#include<string>

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    os << r.info;
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    os << r.info;
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    os << r.info;
    return os;
}
