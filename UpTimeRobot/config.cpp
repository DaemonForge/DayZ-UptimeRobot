class CfgPatches
{
	class UpTimeRobot {
		requiredVersion=0.1;
		requiredAddons[]= {
		};
	};
};

class CfgMods
{
	class UpTimeRobot {
		dir = "UpTimeRobot";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "UpTimeRobot";
		credits = "0";
        author = "";
		authorID = "0"; 
		version = "1.0"; 
		extra = 0;
		type = "mod";
	    dependencies[]={ "Game",  "Mission" };
	    class defs
	    {
			class gameScriptModule
            {
                files[]={
					"UpTimeRobot/Scripts/3_Game"
					};
            };
			
			
	        class missionScriptModule
            {
                files[]={ 
					"UpTimeRobot/Scripts/5_Mission" 
					};
            };
			
        };
	};
};