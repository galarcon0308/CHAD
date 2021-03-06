#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
using namespace std; 
  
static double haversine(double lat1, 
                        double lon1, 
                        double lat2,
                        double lon2) 
    { 
        // distance between latitudes 
        // and longitudes 
        double dLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double dLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
  
        // convert to radians 
        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  
        // apply formulae 
        double a = pow(sin(dLat / 2), 2) +  
                   pow(sin(dLon / 2), 2) *  
                   cos(lat1) * cos(lat2); 
        double rad = 6371; 
        double c = 2 * asin(sqrt(a)); 
        return rad * c; 
    } 


/*** R
lat1 = 51.5007; 
lon1 = 0.1246; 
lat2 = 40.6892; 
lon2 = 74.0445; 

haversine(lat1, lon1, lat2, lon2)
*/
