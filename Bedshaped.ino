#define AUDIO_OUT_PIN 8
const int freqs[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 466.16, 523.25, 587.33, 587.33, 659.25,698.46, 783.99, 880, 932.33, 1046.50};
int crotchet_milliseconds = 792;
int noise_level = 2;
int time_between_notes = 35;

void setup() {
Serial.begin(115200);
Serial.println("Start setup");
//using a bpm of 76


}

void sound(int frequency, int noise, int miliseconds)
{

  analogWriteFreq(frequency);
  int max_amplitude = 512;
  for (miliseconds; miliseconds > 0; miliseconds = miliseconds -10)
  {
  int amplitude = max_amplitude + random(16) * noise;
  analogWrite(AUDIO_OUT_PIN, amplitude);
  delay(10);
  }

}

void note(int note_code, float duration, boolean ending = true)
{
  int note_miliseconds = crotchet_milliseconds * duration;
  //first determine if it's silence or note
  if (note_code == -1){
    Serial.println("Silence");
    analogWrite(AUDIO_OUT_PIN, 0);
    delay(duration);
    return;
  }
  Serial.println("Note");
  int frequency = freqs[note_code];
  //if it's a note full note send the duration minus an extra delay of silence
  if (ending == true) {

    note_miliseconds = note_miliseconds - time_between_notes;
    sound(frequency, noise_level, note_miliseconds);
    analogWrite(AUDIO_OUT_PIN, 0);
    delay(time_between_notes);
  }
  else {
    sound(frequency, noise_level, note_miliseconds);
  }
}

void loop() {
      Serial.println("Starting loop");
      note( 4 , 0.25 , true );
      note( 10 , 0.25 , true );
      note( 10 , 0.75 , true );
      note( 10 , 0.25 , true );
      note( 10 , 0.75 , true );
      note( 5 , 0.5 , true );
      note( 6 , 0.5 , true );
      note( 7 , 2 , true );
      note( -1 , 2.5 , true );
      note( 7 , 0.25 , true );
      note( 7 , 0.75 , true );
      note( 13 , 0.25 , true );
      note( 13 , 0.75 , true );
      note( 12 , 0.25 , true );
      note( 13 , 0.75 , true );
      note( 12 , 1 , true );
      note( 8 , 1.5 , true );
      note( -1 , 3 , true );  
      note( 6 , 0.25 , false );
      note( 7 , 0.25 , true );
      note( 9 , 0.25 , true );
      note( 11 , 0.75 , true );
      note( 11 , 0.25 , true );
      note( 11 , 1.25 , true );
      note( 6 , 0.5 , true );
      note( 7 , 0.5 , true );
      note( 8 , 1.5 , true );
      note( -1 , 2.5 , true );
      note( 7 , 0.25 , true );
      note( 7 , 0.75 , true );
      note( 13 , 0.50 , true );
      note( 13 , 0.50 , true );
      note( 12 , 0.50 , true );    
      note( 13 , 0.50 , true );
      note( 12 , 0.50 , true ); 
      note( -1 , 0.5 , true );  
      note( 8 , 0.5 , true );    
      //tercer pentagrama
      note( 9 , 3 , true );  
      note( 9 , 0.5 , true );  
      note( 10 , 2.5 , true );
      note( -1 , 1 , true );  
      note( 10 , 0.5 , true );  
      note( 10 , 3.5 , true );    
      note( 10 , 0.5 , true ); 
      note( 10 , 1.5 , true );       
      note( -1 , 0.75 , true );
      note( 10 , 0.25 , true ); 
      note( 11 , 0.25 , true );
      note( 11 , 0.25 , true );
      note( 11 , 0.25 , true );
      note( 11 , 0.59 , true );
      note( 9 , 0.33 , true );
      note( 9 , 0.33 , true ); 
      //cuarto pentagrama 
      note( 9 , 0.33 , true );
      note( 8 , 0.33 , true );  
      note( 9 , 0.34 , true ); 
      note( 12 , 2.5 , true );
      note( 12 , 0.25 , true );
      note( 12 , 1.25 , false );
      note( 13 , 0.5 , true ); 
      note( 11 , 1.5 , true );
      note( -1 , 0.5 , true );       
      note( 10 , 1 , false ); 
      note( 11 , 3 , true );
      note( 9 , 0.5 , true );
      note( 11 , 0.75 , true );
      note( 11 , 0.75 , true );
      note( 9 , 1.5 , true );  
      note( -1 , 0.5 , true );
      note( 9 , 0.5 , true );
      //quinto pentagrama 
      note( 9 , 0.33 , true );
      note( 8 , 0.33 , true );  
      note( 9 , 0.34 , true ); 
      note( 12 , 2.5 , true );
      note( 12 , 0.25 , true );
      note( 12 , 1.25 , false );
      note( 13 , 0.5 , true ); 
      note( 11 , 1.5 , true );
      note( 10 , 0.5 , true );       
      note( 10 , 1 , false ); 
      note( 11 , 1.5 , true );
      note( -1 , 1.5 , true );
      note( 9 , 0.5 , true );
      note( 11 , 0.75 , false );
      note( 10 , 0.75 , false );
      note( 9 , 1.5 , true );  
      note( -1 , 0.75 , true );
      note( 9 , 0.25 , true );
      //sexto pentagrama
      note( 10 , 0.5 , true );
      note( 9, 0.25, true);
      note( 10 , 0.75 , true );
      note( 11 , 1.5 , true );
      note( -1 , 1 , true );
      note(10, 0.5, false);
      note(9, 0.25, false);
      note(10, 1.25, true);
      note(11, 0.25, false);
      note(12, 0.25, false);
      note(11, 1, false);
      note(10, 1, true);
      note(10,0.25,false);
      note(10,1.5, true);
      note(-1,0.75, true);
      note(4,0.25, true);
      note(4, 0,5, true);
      note(11, 0,25, true);
      note(11, 0.75, true);
      note(11, 0.25, true);
      note(11, 0.75, true);
      note(6, 0.5, false);
      note(7, 0.5, true);
      //septimo pentagrama
      note(8, 1.5, true); 
      note(-1, 2.5, true);
      note(8, 0.25, true);
      note(8, 0.25, true);
      note(8, 0.5, true);
      note(14, 0.25, true);
      note(14, 0.75, true);
      note(14, 0.25, true);
      note(14, 0.75, true);
      note(13, 1, true);
      note(8, 1.5, true);
      note(-1, 2.25, true);
      note(6, 0,25, true);
      note(6, 0,25, true);
      note(6, 0,5, true); 
      note(7, 0.25, false);
      note(9, 0.25, true);
      note(11, 0.75, true);
      note(11, 0.25, true);
      note(11, 0.75, true);
      note(6, 0.5, false);
      note(7, 0.5, false);
      note(8, 0.5, false); 
      //final de pentagrama 7                                                                            
        Serial.println("Ending loop");
        analogWrite(AUDIO_OUT_PIN, 0);
        delay(1000);

}
