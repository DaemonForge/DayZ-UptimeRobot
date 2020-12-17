modded class MissionServer extends MissionBase
{
	
	override void OnInit()
	{
		super.OnInit();
		Print("[UPTIMEROBOT] Init URL: " + GetUpTimeRobotConfig().Url);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.SendUpTimePing, GetUpTimeRobotConfig().GetInterval(), true);
	}
	
	
	void SendUpTimePing(){
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		if (players && players.Count() >= GetUpTimeRobotConfig().MinPlayers){
			UApi().Rest().Get(GetUpTimeRobotConfig().Url);
		} else {
		}
	}
}
