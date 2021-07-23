modded class MissionServer extends MissionBase
{
	
	override void OnInit()
	{
		super.OnInit();
		Print("[UPTIMEROBOT] Init URL: " + GetUpTimeRobotConfig().Url);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.SendUpTimePing, GetUpTimeRobotConfig().GetInterval(), false);
	}
	
	
	void SendUpTimePing(){
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.SendUpTimePing, GetUpTimeRobotConfig().GetInterval(), false);
		autoptr array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		if (players && players.Count() >= GetUpTimeRobotConfig().MinPlayers){
			#ifndef UNIVERSALAPI_STABLE
				UApi().Rest().Get(GetUpTimeRobotConfig().Url);
			#else
				UApi().Get(GetUpTimeRobotConfig().Url);	
			#endif
		}
	}
}
