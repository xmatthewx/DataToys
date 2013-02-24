//
//  MpiElements.h
//  MPI_DataVisualizer
//
//  Created by Patricio Gonzalez Vivo on 2/19/13.
//
//

#ifndef MPI_DataVisualizer_MpiElements_h
#define MPI_DataVisualizer_MpiElements_h

enum mpiStarsIndex {
    LARGEST_CONCENTRATION,  //  1   Ten cities with largest concentration of foreing-born popultion
    FASTEST_GROWING,        //  2   Ten cities with fastest growing foreing-born population
    ACTIVE_RECRUITING       //  3   Ten cities most actively cruiting the foreing born
    
    //  Se the end of https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/project_overview.pdf?raw=true
    //
};

enum mpiValue{
    MPI_CITY_ID = 0,
    MPI_POPULATION_TOTAL = 1,
    MPI_POPULATION_IMMIGRANTS = 2,
    MPI_POPULATION_SHARE = 3,
    MPI_RECENT_ARRIVALS = 4,
    MPI_DEGREE_IMMIGRANTS_NO = 5,
    MPI_DEGREE_IMMIGRANTS_HIGHSCHOOL = 6,
    MPI_DEGREE_IMMIGRANTS_BA = 7,
    MPI_DEGREE_NATIVE_NO = 8,
    MPI_DEGREE_NATIVE_HIGHSCHOOL = 9,
    MPI_DEGREE_NATIVE_BA = 10,
    MPI_EMPLOYED_TOTAL = 11,
    MPI_EMPLOYED_IMMIGRANTS = 12,
    MPI_EMPLOYED_NATIVE = 13,
    MPI_EMPLOYED_SHARE = 14,
    MPI_UNEMPLOYMENT = 15,
    MPI_POVERTY = 16,
    MPI_HOMEOWNERS = 17,
    MPI_ETHNIC_BLACK = 18,
    MPI_ETHNIC_ASIAN = 19,
    MPI_ETHNIC_LATINO = 20,
    MPI_ETHNIC_NONWHITE = 21,
    MPI_ETHNIC_NONENGLISH_SPK = 22,
    MPI_CREATIVE_CLASS = 23
};

//  GeoLocalization information of the city
//
struct CityLoc{
    int     nId;            //  We need this to cross the information with the Sample to place it in a map
    
    string  name, state;        //  It's good to have names isn' t
    float   latitud, longitud;  //  This is the key to position them on a world map
    
    mpiStarsIndex stars;    //  Using the Index described here https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/project_overview.pdf?raw=true
};

//  Sample by City
//
struct CitySample {
    
    float   getValue( mpiValue _mpiValue ){
        switch (_mpiValue) {
            case MPI_CITY_ID:
                return nId;
            case MPI_POPULATION_TOTAL:
                return pop;
            case MPI_POPULATION_IMMIGRANTS:
                return popImm;
            case MPI_POPULATION_SHARE:
                return popImmShare;
            case MPI_RECENT_ARRIVALS:
                return recArr;
            case MPI_DEGREE_IMMIGRANTS_NO:
                return noDegreeImm;
            case MPI_DEGREE_IMMIGRANTS_HIGHSCHOOL:
                return hsDegreeImm;
            case MPI_DEGREE_IMMIGRANTS_BA:
                return baDegreeImm;
            case MPI_DEGREE_NATIVE_NO:
                return noDegreeNat;
            case MPI_DEGREE_NATIVE_HIGHSCHOOL:
                return hsDegreeNat;
            case MPI_DEGREE_NATIVE_BA:
                return baDegreeNat;
            case MPI_EMPLOYED_TOTAL:
                return employedTotal;
            case MPI_EMPLOYED_IMMIGRANTS:
                return employedImm;
            case MPI_EMPLOYED_NATIVE:
                return employedNat;
            case MPI_EMPLOYED_SHARE:
                return employedImmShare;
            case MPI_UNEMPLOYMENT:
                return unEmployment;
            case MPI_POVERTY:
                return poverty;
            case MPI_HOMEOWNERS:
                return homeOwners;
            case MPI_ETHNIC_BLACK:
                return black;
            case MPI_ETHNIC_ASIAN:
                return asian;
            case MPI_ETHNIC_LATINO:
                return latino;
            case MPI_ETHNIC_NONWHITE:
                return nonWhite;
            case MPI_ETHNIC_NONENGLISH_SPK:
                return nonEnglSpk;
            case MPI_CREATIVE_CLASS:
                return creativeClass;
            default:
                return -1;
        }
    }
    
    //  City ID
    //
    int     nId;
    
    //  Population
    //
    int     pop;            //Number: Total pop
    int     popImm;         //Number:  Immigrants
    
    float   popImmShare;    //Immigrant share (%)
    float   recArr;         //Recent arrivals (%) of all immigrants
    
    //  Education
    //
    float   noDegreeImm;    //Percent: No high school degree   Immigrants
    float   hsDegreeImm;    //Percent: High school/AA degree  Immigrants
    float   baDegreeImm;    //Percent: BA/higher  Immigrants
    float   noDegreeNat;    //Percent: No high school degree  Native born
    float   hsDegreeNat;    //Percent: High school/AA degree Native born
    float   baDegreeNat;    //Percent: BA/higher Native born
    
    //  Employment
    //
    int     employedTotal;  //Number:  Employed
    int     employedImm;    //Number:  Imm  Employed
    int     employedNat;    //Number:  Natives  Employed
    
    float   employedImmShare;   // Imm share among all empl (%)
    float   unEmployment;       //Unemployment rate (%)
    
    //  Financial
    //
    float   poverty;        //Poverty rate (%)
    float   homeOwners;     //Rate of home ownership (%)
    
    //  Ethnic/Cultural
    //
    float   black;          //Percent: Black
    float   asian;          //Percent: Asian
    float   latino;         //Percent: Latino
    float   nonWhite;       //Percent: Non-white
    float   nonEnglSpk;     //Percent: Speak other lang (than English)
    
    float   creativeClass;  //Percent: Creative class
    
    //  Confused?? Need help?? Check this:
    //  https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true
    
};

#endif
