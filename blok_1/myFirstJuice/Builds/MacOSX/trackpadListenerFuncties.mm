#ifndef TRACKPAD_LISTENER
#define TRACKPAD_LISTENER

#include <iostream>
#include <CoreFoundation/CoreFoundation.h>

//--Global Variables-----------------------------------------------
bool isTheFingerThere[10];
int globalFingerID[10];
float globalExPosition[10];
float globalWhyPosition[10];
float lastXposition;

typedef struct { float x,y; } mtPoint;
typedef struct { mtPoint pos,vel; } mtReadout;

typedef struct {
	int frame;
	double timestamp;
	int identifier, state, foo3, foo4;
	mtReadout normalized;
	float size;
	int zero1;
	float angle, majorAxis, minorAxis;
	mtReadout mm;
	int zero2[2];
	float unk2;
} Finger;

typedef void *MTDeviceRef;
typedef int (*MTContactCallbackFunction)(int,Finger*,int,double,int);

extern "C" {
    MTDeviceRef MTDeviceCreateDefault();
    void MTRegisterContactFrameCallback(MTDeviceRef, MTContactCallbackFunction);
    void MTDeviceStart(MTDeviceRef, int); // thanks comex
}

int callback(int device, Finger *data, int nFingers, double timestamp, int frame) {
	for (int i=0; i<nFingers; i++) {
		Finger *f = &data[i];
		
		float x = f->normalized.pos.x;
		float y = f->normalized.pos.y;
        
        isTheFingerThere[i] = true;
        globalExPosition[i] = x;
        globalWhyPosition[i] = y;
        
        lastXposition = x;
        
//        std::cout << nFingers << std::endl;
//        std::cout << identifier << " " << x << " " << y << " " << std::endl;
        
    }
    return 0;
}

void threadThang() {
    MTDeviceRef dev = MTDeviceCreateDefault();
    MTRegisterContactFrameCallback(dev, callback);
    MTDeviceStart(dev, 0);
    sleep(-1);
}

void *trackpadListener(void *threadid)
{
    threadThang();
    pthread_exit(NULL);
}

#endif

