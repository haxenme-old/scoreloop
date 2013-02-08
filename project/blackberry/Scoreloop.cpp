#include "Utils.h"
#include <scoreloop/scoreloopcore.h>
#include <scoreloop/sc_init.h>


namespace scoreloop {
	
	
	SC_Error_t errCode;
	SC_Client_h client;
	SC_InitData_t initData;
	
	
	void HandleEvent (int data) {
		
		bps_event_t *event = (bps_event_t *)data;
		
		if (bps_event_get_domain(event) == SC_GetBPSEventDomain (&initData)) {
			
			SC_HandleBPSEvent (&initData, event);
			
		}
		
	}
	
	
	bool Initialize (const char* gameIdentifier, const char *gameSecret, const char *gameVersion, const char *currency, const char *languages) {
		
		SC_InitData_Init (&initData);
		SC_Error_t errCode = SC_Client_New(&client, &initData, gameIdentifier, gameSecret, gameVersion, currency, languages);
		return (errCode == 0);
		
	}

	
	
}