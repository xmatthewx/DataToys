//
//  MpiData.h
//  MPI_DataVisualizer
//
//  Created by Patricio Gonzalez Vivo on 2/19/13.
//
//

#ifndef MPI_DATA
#define MPI_DATA

#include "ofMain.h"

#include "MpiElements.h"

#include "ofxCsv.h"
using namespace wng;

//  Check MPI DATA BASE overview 
//  https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
//
class MpiData {
public:
    
    MpiData();
    
    void    loadCities( string _cvsFile );             //  The ID's of the cities have to mach the one of the Samples
    void    loadSample( int _year, string _cvsFile );
    
    int     getTotalYears();
    int     getTotalCities();
    int     getTotalSamples();
    
    int     getYear( int _yearId);
    int     getFirstYear();
    int     getLastYear();
    
    int     getYearId( int _year );
    int     getCityId( string _city );
    
    string  getCity( int _cityId );
    string  getState( int _cityId );
    float   getLatitud( int _cityId );
    float   getLongitud( int _cityId );
    
    CitySample& getSample( int _yearId, int _cityId );
    
    float   getMinVal( mpiValue _mpiValue, int _cityId );   // Min value in a specific city
    float   getMaxVal( mpiValue _mpiValue, int _cityId );   // Max value in a specific city
    
    float   getMinVal( mpiValue _mpiValue );                // Min value of all cities
    float   getMaxVal( mpiValue _mpiValue );                // Max value of all cities
    
private:
    vector< int >               years;
    vector< CityLoc >           cities; // This store the city info
    vector< vector<CitySample> > samples; // The first vector it's for the year and the second the total amount of cities.
    
};

#endif
