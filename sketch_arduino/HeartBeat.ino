unsigned long gLastHeartBeatTime = 0L;
int HEART_BEAT_DELAY = 10000;


void heartBeat(unsigned long curTime) {
  if((curTime - gLastHeartBeatTime )>  HEART_BEAT_DELAY){
      reply[BULE_TOOTH_MODE]("hb");
      gLastHeartBeatTime = curTime;
  }
}
