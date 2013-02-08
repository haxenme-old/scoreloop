package;

#if cpp
import cpp.Lib;
import nme.events.SystemEvent;
#elseif neko
import neko.Lib;
#end


class Scoreloop {
	
	
	public static function initialize (gameIdentifier:String, gameSecret:String, gameVersion:String, currency:String, languages:String):Bool {
		
		var result = scoreloop_initialize (gameIdentifier, gameSecret, gameVersion, currency, languages);
		
		if (result) {
			
			nme.Lib.current.stage.addEventListener (SystemEvent.SYSTEM, stage_onSystemEvent);
			
		}
		
		return result;
		
	}
	
	
	
	
	// Event Handlers
	
	
	
	
	private static function stage_onSystemEvent (event:SystemEvent):Void {
		
		scoreloop_process_event (event.data);
		
	}
	
	
	
	
	// Native Methods
	
	
	
	
	private static var scoreloop_initialize = Lib.load ("scoreloop", "scoreloop_initialize", 5);
	private static var scoreloop_process_event = Lib.load ("scoreloop", "scoreloop_process_event", 1);
	
	
}