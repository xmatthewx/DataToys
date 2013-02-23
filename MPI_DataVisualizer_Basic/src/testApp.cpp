
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_SIMPLE );
    ofEnableSmoothing();
    
    dBase.loadCities("cities.csv");
    dBase.loadSample(2000, "2000.csv");
    dBase.loadSample(2005, "2005.csv");
    dBase.loadSample(2010, "2010.csv");
    
//    cout << dBase.getSample( dBase.getYearId(2000), dBase.getCityId("New York") ).pop << endl;
    
    frame.set(0,0,600,100);
    
    city = "New York";
    maxPop = MAX(dBase.getMaxVal( MPI_POPULATION_TOTAL), dBase.getMaxVal( MPI_POPULATION_IMMIGRANTS) );
    minPop = MIN(dBase.getMinVal( MPI_POPULATION_TOTAL), dBase.getMinVal( MPI_POPULATION_IMMIGRANTS) );
    
    pop = makeChart( dBase.getCityId(city) , MPI_POPULATION_TOTAL , frame, minPop, maxPop );
    popImm = makeChart( dBase.getCityId(city) , MPI_POPULATION_IMMIGRANTS, frame, minPop, maxPop );
}

//--------------------------------------------------------------
ofPolyline  testApp::makeChart( int _cityId, mpiValue _mpiValue, ofRectangle _rect, float _minVal,  float _maxVal ){
    ofPolyline line;
    
    line.addVertex( ofPoint(_rect.x, _rect.y+_rect.height) );
    
    //  Construct the mesh
    //
    for (int i = 0; i < dBase.getTotalYears(); i++) {
        float val = dBase.getSample(i, _cityId).getValue( _mpiValue );
        
        ofPoint vertex;
        vertex.x = ofMap( dBase.getYear(i) , dBase.getFirstYear(), dBase.getLastYear() , _rect.x, _rect.width, true);
        vertex.y = ofMap(val, _minVal, _maxVal, _rect.y+_rect.height, _rect.y);
        
        line.curveTo( vertex );
        line.addVertex( vertex );
    }
    
    line.addVertex( ofPoint(_rect.x+_rect.width,_rect.y+_rect.height) );
    
    return line;
}

//--------------------------------------------------------------
void testApp::update(){
	
    
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackgroundGradient(ofColor::gray, ofColor::black);
    
    cam.begin();
    ofPushMatrix();
    ofTranslate(-frame.width*0.5,-frame.height*0.5);
    
    //  Draw Frame
    //
    ofNoFill();
    ofSetColor(255);
    ofLine( ofPoint(0,0), ofPoint(0,frame.height));
    ofLine( ofPoint(0,frame.height), ofPoint(frame.width,frame.height));
    ofDrawBitmapString( city + " Population and Immigran Population",ofPoint(frame.width*0.5-200,-10) );
    
    ofDrawBitmapString( ofToString(maxPop), ofPoint(-100,0));
    ofDrawBitmapString( ofToString(minPop), ofPoint(-100,frame.height));
    
    ofPushMatrix();
    ofTranslate( 0 , frame.height );
    ofRotate(90, 0, 0, 1);
    ofDrawBitmapString( ofToString(dBase.getYear(0) ), ofPoint(0,0));
    ofDrawBitmapString( ofToString(dBase.getYear(1) ), ofPoint(0,-frame.width*0.5));
    ofDrawBitmapString( ofToString(dBase.getYear(2) ), ofPoint(0,-frame.width));
    ofPopMatrix();
    
    // Draw population
    //
    ofFill();
    ofSetColor(255,0,0,100);
    ofBeginShape();
    for(int i = 0; i < pop.size(); i++){
        ofVertex(pop[i]);
    }
    ofEndShape();
    
    //  Draw population of immigration
    //
    ofTranslate(0, 0, 1);
    ofSetColor(0,0,255,100);
    ofBeginShape();
    for(int i = 0; i < popImm.size(); i++){
        ofVertex(popImm[i]);
    }
    ofEndShape();
    
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}