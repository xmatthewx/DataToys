#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

//  Thanks to Tom Carden, for ModestMaps code ( http://modestmaps.com/index.html )
//  https://github.com/RandomEtc/modestmaps-of
//
#include "Map.h"
#include "OpenStreetMapProvider.h"

//  Our happy dataBase
//
#include "MpiData.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);

	Map map;
    MpiData     dBase;
    
    vector <ofPoint> citiesPos;
    Location    myLoc;
    float       angle;
    float       apperture;
    float       distance;
    ofPolyline  areaZone;
};

#endif