#include <Arduino.h>
#include <MIDI.h>
#include <dmtimer.h>

MIDI_CREATE_DEFAULT_INSTANCE();

DMTimer tmrClock;

void playNote(int note, int durationMs){
	MIDI.sendNoteOn(note, 127, 1);
	delay(durationMs);
	MIDI.sendNoteOff(note, 127, 1);
}


void setup() {
  // put your setup code here, to run once:
  MIDI.begin(1);

  float bpm = 60;
  float hz = bpm/60;
  float period_ms = 1.0 / hz;
  float _24th_note = period_ms / 24.0;

  tmrClock.setInterval(_24th_note);
  
}

void loop() {

	if(tmrClock.isTimeReached())
	{
	//	MIDI.sendClock();
	}
  // put your main code here, to run repeatedly:
  for(int n = 48;n<58;n++)
  {
	  playNote(n, 200);
  }

  delay(1000);
}