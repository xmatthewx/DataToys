//
//  MpiData.h
//  MPI_DataVisualizer
//
//  Created by Patricio Gonzalez Vivo on 2/19/13.
//
//  Check MPI DATA BASE overview to know more about the data base
//  https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
//

#ifndef MPI_DATA
#define MPI_DATA

#include "ofMain.h"

#include "MpiElements.h"

class MpiData {
public:
    
    void    loadCities( string _cvsFile );
    void    loadSample( int _year, string _cvsFile );
    
    //      YEAR
    //
    int     getTotalYears();
    int     getYearId( int _year );
    int     getYear( int _yearId);
    int     getFirstYear();
    int     getLastYear();
    
    //      CITY
    //
    int     getTotalCities();
    int     getCityId( string _city );
    string  getCity( int _cityId );
    string  getState( int _cityId );
    float   getLatitud( int _cityId );
    float   getLongitud( int _cityId );
    
    //      VALUES
    //
    float   getPctVal( mpiPctValue _mpiPctValue, int _cityId , int _yearId = -1);
    int     getNumVal( mpiPctValue _mpiNumValue, int _cityId , int _yearId = -1);
    int     getNumVal( mpiNumValue _mpiNumValue, int _cityId , int _yearId = -1);
    
    float   getMinPctVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    float   getMaxPctVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    int     getMinNumVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    int     getMaxNumVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    int     getMinNumVal( mpiNumValue _mpiNumValue, int _cityId = -1);
    int     getMaxNumVal( mpiNumValue _mpiNumValue, int _cityId = -1);
    
    //      SAMPLES
    //
    int                     getTotalSamples();
    vector<mpiCitySample>&  getSamples( int _yearId );
    mpiCitySample&          getSample( int _yearId, int _cityId );
    
private:
    vector< int >                   years;
    vector< mpiCity >               cities;     // This store the city info
    vector< vector<mpiCitySample> > samples;    // The first vector it's for the year and the second the total amount of cities.
    
};

#endif
