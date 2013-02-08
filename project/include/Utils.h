#ifndef SCORELOOP_H
#define SCORELOOP_H


namespace scoreloop {
	
	
	void HandleEvent (int event);
	bool Initialize (const char* gameIdentifier, const char *gameSecret, const char *gameVersion, const char *currency, const char *languages);
	
	
}


#endif