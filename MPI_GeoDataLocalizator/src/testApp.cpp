#include "testApp.h"
#include "OpenStreetMapProvider.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    dBase.loadCities("cities.csv");
    dBase.loadSample(2000, "2000.csv");
    dBase.loadSample(2005, "2005.csv");
    dBase.loadSample(2010, "2010.csv");
    
    map.setup(new OpenStreetMapProvider(), (double)ofGetWidth(), (double)ofGetHeight());
	map.setZoom(3);
    
    //  Loads cities positions
    //
    for (int i = 0; i < dBase.getTotalCities(); i++){
        citiesPos.push_back( map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) ) );
    }
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
    for (int i = 0; i < citiesPos.size(); i++){
        ofSetColor(255,0,0);
        ofCircle(citiesPos[i], 2);
        
        ofSetColor(0,0,200);
        ofDrawBitmapString(dBase.getCity(i), citiesPos[i] + ofPoint(10,5));
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
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// TODO: check if we're over the map
	map.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	map.mousePressed(x,y,button);
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
