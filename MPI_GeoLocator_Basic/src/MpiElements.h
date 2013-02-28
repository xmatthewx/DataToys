//
//  MpiElements.h
//
//  Created by Patricio Gonzalez Vivo on 2/19/13.
//
//

#ifndef MPI_DataVisualizer_MpiElements_h
#define MPI_DataVisualizer_MpiElements_h

#include "ofMain.h"

enum mpiCityCategory{
    //  As you can see this dataBase don't cover all the cities on the US. MPI choose 25 cities following the last 3 criterias:
    //
    MPI_CITY_LARGEST_CONCENTRATION,  //  1   Ten cities with largest concentration of foreing-born popultion
    MPI_CITY_FASTEST_GROWING,        //  2   Ten cities with fastest growing foreing-born population
    MPI_CITY_ACTIVE_RECRUITING       //  3   Five cities most actively cruiting the foreing born
    //
    //  More info: https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/project_overview.pdf?raw=true
};

//  Each one of the cities censed represent a mpiCity
//
struct mpiCity {
    int     nId;        // The position on the dataBase, it is consisten on the four .csv files. Ex: 01
    
    string  name;       //  Name of the City. Ex: "New York"
    string  state;      //  To capital letters that describe the State. i.e. "NY"
    
    float   lat;        //  Latitud geo position of the city: i.e. 43.0000
    float   lon;        //  Longitud geo position of the city: i.e. -75.0000
    
    mpiCityCategory category;   // This follows the criteria for selecting this city as is described above. Ex: 1
    //
    //  Using the Index described here https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/project_overview.pdf?raw=true
};

enum mpiNumValue{
    //  On the dataBase there are 5 columns that contain INTEGER information.
    //
    MPI_NUM_POPULATION,
    MPI_NUM_IMMIGRANTS,
    MPI_NUM_EMPLOYED,               //  (pop. 16+)
    MPI_NUM_EMPLOYED_IMMIGRANTS,    //  (pop. 16+)
    MPI_NUM_EMPLOYED_NATIVE         //  (pop. 16+)
    //
    // More info: https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
};

enum mpiPctValue{
    //  The other columns on the dataBase contain porcentage numbers.
    //
    MPI_PCT_POPULATION_SHARE,
    MPI_PCT_RECENT_ARRIVALS,
    //
    //  EDUCATION
    //
    MPI_PCT_DEGREE_IMMIGRANTS_NO,           //  (pop. 25+)
    MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL,   //  (pop. 25+)
    MPI_PCT_DEGREE_IMMIGRANTS_BA,           //  (pop. 25+)
    MPI_PCT_DEGREE_NATIVE_NO,               //  (pop. 25+)
    MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL,       //  (pop. 25+)
    MPI_PCT_DEGREE_NATIVE_BA,               //  (pop. 25+)
    //
    //  ECONOMIC
    //
    MPI_PCT_EMPLOYED_SHARE,
    MPI_PCT_UNEMPLOYMENT,
    MPI_PCT_POVERTY,
    MPI_PCT_HOMEOWNERS,
    //
    //  ETHNIC
    //
    MPI_PCT_ETHNIC_BLACK,
    MPI_PCT_ETHNIC_ASIAN,
    MPI_PCT_ETHNIC_LATINO,
    MPI_PCT_ETHNIC_NONWHITE,
    MPI_PCT_ETHNIC_NONENGLISH_SPK,
    //
    //  CULTURAL
    //
    MPI_PCT_CREATIVE_CLASS
    //
    // More info: https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
};

//  There is a city sample for each year that city was censed
//
struct mpiCitySample {
    
    int     getNumValue( mpiNumValue _numValue ){
        //  Deliver the TOTAL NUMBERS of people
        //
        switch (_numValue) {
            case MPI_NUM_POPULATION:
                return pop;
            case MPI_NUM_IMMIGRANTS:
                return popImm;
            case MPI_NUM_EMPLOYED:
                return employedTotal;
            case MPI_NUM_EMPLOYED_IMMIGRANTS:
                return employedImm;
            case MPI_NUM_EMPLOYED_NATIVE:
                return employedNat;
            default:
                return -1;          //  Every time you recive a -1 means you are doing something wrong
        }
    }
    
    float   getPctValue( mpiPctValue _pctValue ){
        //  Delivers PERCENTAGE NUMBERS according to:
        //  https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
        //
        switch (_pctValue) {
            case MPI_PCT_POPULATION_SHARE:
                return popImmShare;
            case MPI_PCT_RECENT_ARRIVALS:
                return recArr;
            case MPI_PCT_DEGREE_IMMIGRANTS_NO:
                return noDegreeImm;
            case MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL:
                return hsDegreeImm;
            case MPI_PCT_DEGREE_IMMIGRANTS_BA:
                return baDegreeImm;
            case MPI_PCT_DEGREE_NATIVE_NO:
                return noDegreeNat;
            case MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL:
                return hsDegreeNat;
            case MPI_PCT_DEGREE_NATIVE_BA:
                return baDegreeNat;
            case MPI_PCT_EMPLOYED_SHARE:
                return employedImmShare;
            case MPI_PCT_UNEMPLOYMENT:
                return unEmployment;
            case MPI_PCT_POVERTY:
                return poverty;
            case MPI_PCT_HOMEOWNERS:
                return homeOwners;
            case MPI_PCT_ETHNIC_BLACK:
                return black;
            case MPI_PCT_ETHNIC_ASIAN:
                return asian;
            case MPI_PCT_ETHNIC_LATINO:
                return latino;
            case MPI_PCT_ETHNIC_NONWHITE:
                return nonWhite;
            case MPI_PCT_ETHNIC_NONENGLISH_SPK:
                return nonEnglSpk;
            case MPI_PCT_CREATIVE_CLASS:
                return creativeClass;
            default:
                return -1;      //  Every time you recive a -1 means you are doing something wrong
        }
    }
    
    int getNumValue( mpiPctValue _pctValue ){
        //  This function actually do a TRANSFORMATION from PERCENTAGE to TOTAL NUMBER according to
        //  https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
        //
        switch (_pctValue) {
            case MPI_PCT_POPULATION_SHARE:
                return pop*(popImmShare*0.01);
            case MPI_PCT_RECENT_ARRIVALS:
                return pop*(recArr*0.01);
                
            //  CAUTION: We can not calculate directly here because the PCT is of people 25+
            //
//            case MPI_PCT_DEGREE_IMMIGRANTS_NO:
//                return pop*(noDegreeImm*0.01);
//            case MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL:
//                return pop*(hsDegreeImm*0.01);
//            case MPI_PCT_DEGREE_IMMIGRANTS_BA:
//                return pop*(baDegreeImm*0.01);
//            case MPI_PCT_DEGREE_NATIVE_NO:
//                return pop*(noDegreeNat*0.01);
//            case MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL:
//                return pop*(hsDegreeNat*0.01);
//            case MPI_PCT_DEGREE_NATIVE_BA:
//                return pop*(baDegreeNat*0.01);
                
            case MPI_PCT_EMPLOYED_SHARE:
                return employedTotal*(employedImmShare*0.01);   //  This is the only one that is not over the total population
                
            case MPI_PCT_UNEMPLOYMENT:
                return pop*(unEmployment*0.01);
            case MPI_PCT_POVERTY:
                return pop*(poverty*0.01);
            case MPI_PCT_HOMEOWNERS:
                return pop*(homeOwners*0.01);
            case MPI_PCT_ETHNIC_BLACK:
                return pop*(black*0.01);
            case MPI_PCT_ETHNIC_ASIAN:
                return pop*(asian*0.01);
            case MPI_PCT_ETHNIC_LATINO:
                return pop*(latino*0.01);
            case MPI_PCT_ETHNIC_NONWHITE:
                return pop*(nonWhite*0.01);
            case MPI_PCT_ETHNIC_NONENGLISH_SPK:
                return pop*(nonEnglSpk*0.01);
            case MPI_PCT_CREATIVE_CLASS:
                return pop*(creativeClass*0.01);
                
            //  Every time you recive a -1 means you are doing something wrong
            //
            default:
                return -1;
        }
    }
    
    //
    //---------------------------------------------- RAW DATA
    //
    int     nId;            //  City ID
    
    //  POPULATION
    //
    int     pop;            //  Number of total population
    int     popImm;         //  Number of total immigrants
    
    float   popImmShare;    //  % of immigrant share
    float   recArr;         //  % of immigrants who are recent arrivals (arrived within the last 10 years)
    
    //  EDUCATION/SKILLED
    //  * Among immigrant adults (pop. 25+): % low-, middle-, and high skilled
    //
    float   noDegreeImm;    //  % no high school degree  Immigrants
    float   hsDegreeImm;    //  % high school/AA degree  Immigrants
    float   baDegreeImm;    //  % BA/higher  Immigrants
    
    //  * Among native adults (pop. 25+): % low-, middle-, and high skilled
    //
    float   noDegreeNat;    //  % No high school degree  Native born
    float   hsDegreeNat;    //  % High school/AA degree Native born
    float   baDegreeNat;    //  % BA/higher Native born
    
    //  FINANCIAL
    //
    int     employedTotal;  //  Number of all employed workers (pop. 16+)
    int     employedImm;    //  Number of immigrant employed workers (pop. 16+)
    int     employedNat;    //  Number of native employed workers (pop. 16+)
    
    float   employedImmShare;// Immigrant share (% among all employed)
    float   unEmployment;   //  % Unemployed (of total pop.)

    float   poverty;        //  % in Poverty (of total pop.)
    float   homeOwners;     //  Rate of home ownership (%)
    
    //  ETHNICAL/CULTURAL (these serve as proxies for ethnic/linguistic diversity)
    //
    float   black;          //  % Black (of total pop.)
    float   asian;          //  % Asian (of total pop.)
    float   latino;         //  % Latino (of total pop.)
    float   nonWhite;       //  % Non-white (of total pop.)
    float   nonEnglSpk;     //  % Speak other lang (than English) (of total pop.)
    
    float   creativeClass;  //  % Creative class
    //  i.e., share employed in professional occupations and had at least a bachelor�s degree among all employed adults
    
    //
    //  More info: https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
    
};

#endif
