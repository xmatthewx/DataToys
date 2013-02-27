# Making it in America: *The Immigrant Success Index*

* **[Public Radio International (PRI)](http://www.pri.org/)** is the second leading distributor of public radio shows after NPR. We produce and/or distribute shows like This American Life, The World, Afropop, Studio360 and Tavis Smiley. Our mission is to give people the information, insights and cultural experiences they need to live in a diverse, interconnected world. And we have a major initiative to reach and engage immigrants in the US to bring their voices into public debate, provide unbiased stories of their role and experiences in our society, and get all Americans involved in Siguring out our approach to immigrants and immigration. PRI is creating the Index as a way to help local journalists and citizens tell true stories about immigrant life in America as well as city policy makers who are interested in attracting and engaging their immigrant populations.


* Charlotte, SC ++ 
* Columbus, OH++ 
* Dayton, OH+++ 
* Washington DC + 
* Indianapolis, IN++ 
* Los Angeles, CA + 
* Miami, FL+
* New York, NY + 
* Richmond, VA ++
* San Francisco, CA +
* Boston, MA +
* Chicago, IL + 
* Dallas, TX + 
* Detroit, MI +++ 
* Houston, TX + 
* Lakeland, FL ++ 
* Louisville, KY ++ 
* Nashville, TN ++ 
* Raleigh, NC ++ 
* Riverside, CA +

Reference:

	+   Ten cities with largest concentration of foreign-born population 
	++  Ten cities with fastest growing foreign-born population 
	+++ Five cities most actively recruiting the foreign born
	
Over this cities in each of the three years (2000, 2005, and 2010) you will see: 

* Number: Total population
entertainment; medicine and education – and the prosperity of cities. [More information](http:// www.washingtonmonthly.com/features/2001/0205.florida.html) 



## Preparation of the dataBased
[The data base received](https://docs.google.com/file/d/0B9yD5YLwxGTIck8zUS1adGRuVEk/edit?usp=sharing) was a MS Excel document with a big table with the three years census one next to the other. In order to work and process the data it was necessary to:

*	Transform the dataBase from an MS Excel file into a [Google Spreadsheet one](https://docs.google.com/spreadsheet/ccc?key=0AsKqVj4h_cOwdDlTMGRfMGtxOFFrY0gxc1lZdGZFbFE&usp=sharing)
*	Match the name of the Cities and States according to the [project_overview.pdf](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/project_overview.pdf?raw=true)
*	Separate the cities in a different table ( [```cities.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/cities.csv) ) and replace it by IDs. This separation makes the information of the city independent of the three samples
*	Research the geographical location of the cities (Lat & Long)
*	Add the selection criteria of each city
*	Split the samples according to the three years and export them as CSV (comma separated values) files: [```2000.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/2000.csv), [```2005.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/2005.csv) and [```2010.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/2010.csv) 
	
## The DataBase and the openSource C++ API for openFrameworks

### Elements
The elements that are going to be use for the API are defined at ```MpiElements.h``` and it's composed by: 

* ```mpiCity```: this object contain the information of the chosen cities and is populated with the [```cities.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/cities.csv). The object contain the following variables

		int     nId;   		//	This is used to cross the information between tables		
    	string  name;       //  Name of the City. Ex: "New York"
    	string  state;      //  To capital letters that describe the State. i.e. "NY"
    
    	float   lat;    	//  Lat geo position of the city: i.e. 43.00
    	float   lon;   		//  Long geo position of the city: i.e. -75.00
    
    	mpiCityCategory category;	//	Selected City criteria

	
* ```mpiCityCategory```: this variable contain the three different criterial category already described. This variable could be one of the following values 

		MPI_CITY_LARGEST_CONCENTRATION  //  10 cities with largest concentration of foreing-born pop
		MPI_CITY_FASTEST_GROWING        //  10 cities with fastest growing foreing-born pop
		MPI_CITY_ACTIVE_RECRUITING       //  10 cities most actively cruiting the foreing born

* ```mpiNumValue```: the tables [```2000.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/2000.csv), [```2005.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/2005.csv) and [```2010.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/2010.csv) contain integer information of population together with percentages. ```mpiNumValue``` is a variable type that referee to those integers one that hold total amount of persons. As you can see the last three values are based on people over 16+ years old. This variable could be one of the following values 

		MPI_NUM_POPULATION
		MPI_NUM_IMMIGRANTS
		MPI_NUM_EMPLOYED               //  (pop. 16+)
		MPI_NUM_EMPLOYED_IMMIGRANTS    //  (pop. 16+)
		MPI_NUM_EMPLOYED_NATIVE        //  (pop. 16+)


* ```mpiPctValue```: referee to those values that are percentages of different populations.   This one could be:

	    MPI_PCT_POPULATION_SHARE
	    MPI_PCT_RECENT_ARRIVALS
	    
    	MPI_PCT_DEGREE_IMMIGRANTS_NO,           //  (pop. 25+)
    	MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL,   //  (pop. 25+)
    	MPI_PCT_DEGREE_IMMIGRANTS_BA,           //  (pop. 25+)
    	MPI_PCT_DEGREE_NATIVE_NO,               //  (pop. 25+)
    	MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL,       //  (pop. 25+)
    	MPI_PCT_DEGREE_NATIVE_BA,               //  (pop. 25+)

    	MPI_PCT_EMPLOYED_SHARE,
    	MPI_PCT_UNEMPLOYMENT,
    	MPI_PCT_POVERTY,
    	MPI_PCT_HOMEOWNERS,

    	MPI_PCT_ETHNIC_BLACK,
    	MPI_PCT_ETHNIC_ASIAN,
    	MPI_PCT_ETHNIC_LATINO,
    	MPI_PCT_ETHNIC_NONWHITE,
    	MPI_PCT_ETHNIC_NONENGLISH_SPK,

    	MPI_PCT_CREATIVE_CLASS

For a more information about this values please read this [overview of the data](https://github.com/patriciogonzalezvivo/DataToys/blob/master/MPI_DataBase/data_overview.pdf?raw=true)


* ```mpiCitySample```: this is the object that holds all the data from each city in a particular year. Beside the variables that holds this information is important to know that there are three functions that let you request and transform values:

		int     nId;
    
		int     getNumValue( mpiNumValue _numValue ) // return TOTAL NUMBERS 
    
		float   getPctValue( mpiPctValue _pctValue ) // return PERCENTAGES (PCT)
		
    	int 	getNumValue( mpiPctValue _pctValue ) // transform from PCT to TOTAL NUMBER 
        
It's important to know that if you are getting a ```-1``` it's because the information can't be provided. For example if you want to get the TOTAL NUMBER of immigrant with no deegree it can't be done. Looking above you will see that's because that percentage it of the population over 25+ witch we don't have. Those 6 options with the same characteristic are the only one that can be satisfy correctly. 
