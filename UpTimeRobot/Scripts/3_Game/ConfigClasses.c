class UpTimeRobotConfig
{ 
	private static string ConfigPATH = "$profile:\\UApi\\UpTimeRobot.json";
	//Default Values
	float Interval = 55;
	string Url = "";
	int MinPlayers = 2;
		
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (GetGame().IsServer()){
			if (FileExist(ConfigPATH)){ //If config exist load File
				JsonFileLoader<UpTimeRobotConfig>.JsonLoadFile(ConfigPATH, this);
			}else{ //File does not exist create file
				Save();
			}
		}
	}
	
	void Save(){
		JsonFileLoader<UpTimeRobotConfig>.JsonSaveFile(ConfigPATH, this);
	}

	float GetInterval(){
		return Interval * 1000;
	}
	
};

ref UpTimeRobotConfig m_UpTimeRobotConfig;


//Helper function to return Config
static ref UpTimeRobotConfig GetUpTimeRobotConfig()
{
	if (!m_UpTimeRobotConfig && GetGame().IsServer())
	{
		m_UpTimeRobotConfig = new UpTimeRobotConfig;
		m_UpTimeRobotConfig.Load();
	}
	return m_UpTimeRobotConfig;
};
