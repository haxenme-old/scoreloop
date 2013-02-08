#ifndef IPHONE
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif


#include <hx/CFFI.h>
#include "Utils.h"


using namespace scoreloop;



static value scoreloop_initialize (value gameIdentifier, value gameSecret, value gameVersion, value currency, value languages) {
	
	bool result = Initialize (val_string (gameIdentifier), val_string (gameSecret), val_string (gameVersion), val_string (currency), val_string (languages));
	return alloc_bool (result);
	
}
DEFINE_PRIM (scoreloop_initialize, 5);


static void scoreloop_process_event (value event) {
	
	HandleEvent (val_int (event));
	
}
DEFINE_PRIM (scoreloop_process_event, 1);



extern "C" void scoreloop_main () {}
DEFINE_ENTRY_POINT (scoreloop_main);



extern "C" int scoreloop_register_prims () { return 0; }