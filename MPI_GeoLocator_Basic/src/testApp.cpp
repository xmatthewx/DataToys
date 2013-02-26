#include "testApp.h"
#include "OpenStreetMapProvider.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFullscreen(true);
    
    dBase.loadCities("cities.csv");
    dBase.loadSample(2000, "2000.csv");
    dBase.loadSample(2005, "2005.csv");
    dBase.loadSample(2010, "2010.csv");
    
    map.setup(new OpenStreetMapProvider(), (double)ofGetWidth(), (double)ofGetHeight());
    myLoc = Location(40.257,-98.7689);
    map.setCenter(myLoc);
	map.setZoom(5);
    
    //  Loads cities positions
    //
    for (int i = 0; i < dBase.getTotalCities(); i++){
        citiesPos.push_back( map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) ) );
    }
    
    angle = 0;
    distance = 0;
    apperture = 30;
    
    ofPoint point = map.locationPoint(myLoc);
    areaZone.clear();
    areaZone.addVertex(point);
    areaZone.arc(point, distance, distance, angle-apperture*0.5, angle+apperture*0.5, true,60);
    areaZone.addVertex(point);
}

//--------------------------------------------------------------
void testApp::update(){
	map.update();
    
    for (int i = 0; i < citiesPos.size(); i++){
        citiesPos[i] = map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) );
    }
}

//--------------------------------------------------------------
void testApp::draw(){    
    map.draw();
    
    ofPushStyle();
    
    
    ofSetColor(0,200,0);
    ofCircle( map.locationPoint(myLoc), map.getZoom() );
    
    ofSetColor(0,200,0,100);
    ofBeginShape();
    for(int i = 0; i < areaZone.size(); i++){
        ofVertex(areaZone[i]);
    }
    ofEndShape();
    
    for (int i = 0; i < citiesPos.size(); i++){
        
        if (areaZone.inside( citiesPos[i] )){
            ofSetColor(0,0,200,200);
            ofDrawBitmapString(dBase.getCity(i), citiesPos[i] + ofPoint(10,5));

            ofFill();
        } else {
            ofNoFill();
        }
        
        ofSetColor(255,0,0,200);
        ofCircle(citiesPos[i], map.getZoom() * 2);
        
    }
    
    ofPopStyle();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	map.keyPressed(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	map.keyReleased(key);
	
	if (key == 'f' || key == 'F') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	// TODO: change mouse cursor if over map?
//    Location loc = map.pointLocation(ofPoint(x,y));
//    cout << "Lat: "<< loc.lat << " , Lon: " << loc.lon << endl;
//    
//    cout << map.getZoom() << endl;
    
    ofPoint mouse = ofPoint(x,y);
    ofPoint point = map.locationPoint(myLoc);
    ofPoint diff = mouse - point;
    
    distance = diff.length();
    angle = ofRadToDeg(atan2(diff.y,diff.x));
    
    areaZone.clear();
    areaZone.addVertex(point);
    areaZone.arc(point, distance, distance, angle-apperture*0.5, angle+apperture*0.5, true,60);
    areaZone.addVertex(point);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// TODO: check if we're over the map
	map.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	map.mousePressed(x,y,button);
    
    myLoc = map.pointLocation(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	map.mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	// TODO: map.setSize(w,h)?
	map.width = w;
	map.height = h;
}

