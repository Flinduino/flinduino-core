
#include "ZumoBuzzer.h"

static void nextNote();

ZumoBuzzer::ZumoBuzzer()
{
#pragma message ("Buzzer functions are not implemented on PIC32 (Flinduino)")
}

inline void ZumoBuzzer::init()
{
}

void ZumoBuzzer::init2()
{
}

// Set up timer 1 to play the desired frequency (in Hz or .1 Hz) for the
//   the desired duration (in ms). Allowed frequencies are 40 Hz to 10 kHz.
//   volume controls buzzer volume, with 15 being loudest and 0 being quietest.
// Note: frequency*duration/1000 must be less than 0xFFFF (65535).  This
//   means that you can't use a max duration of 65535 ms for frequencies
//   greater than 1 kHz.  For example, the max duration you can use for a
//   frequency of 10 kHz is 6553 ms.  If you use a duration longer than this,
//   you will cause an integer overflow that produces unexpected behavior.
void ZumoBuzzer::playFrequency(unsigned int freq, unsigned int dur, 
                     unsigned char volume)
{
}

// Determine the frequency for the specified note, then play that note
//  for the desired duration (in ms).  This is done without using floats
//  and without having to loop.  volume controls buzzer volume, with 15 being
//  loudest and 0 being quietest.
// Note: frequency*duration/1000 must be less than 0xFFFF (65535).  This
//  means that you can't use a max duration of 65535 ms for frequencies
//  greater than 1 kHz.  For example, the max duration you can use for a
//  frequency of 10 kHz is 6553 ms.  If you use a duration longer than this,
//  you will cause an integer overflow that produces unexpected behavior.
void ZumoBuzzer::playNote(unsigned char note, unsigned int dur,
                 unsigned char volume)
{
  // note = key + octave * 12, where 0 <= key < 12
  // example: A4 = A + 4 * 12, where A = 9 (so A4 = 57)
  // A note is converted to a frequency by the formula:
  //   Freq(n) = Freq(0) * a^n
  // where
  //   Freq(0) is chosen as A4, which is 440 Hz
  // and
  //   a = 2 ^ (1/12)
  // n is the number of notes you are away from A4.
  // One can see that the frequency will double every 12 notes.
  // This function exploits this property by defining the frequencies of the
  // 12 lowest notes allowed and then doubling the appropriate frequency
  // the appropriate number of times to get the frequency for the specified
  // note.

  // if note = 16, freq = 41.2 Hz (E1 - lower limit as freq must be >40 Hz)
  // if note = 57, freq = 440 Hz (A4 - central value of ET Scale)
  // if note = 111, freq = 9.96 kHz (D#9 - upper limit, freq must be <10 kHz)
  // if note = 255, freq = 1 kHz and buzzer is silent (silent note)

  // The most significant bit of freq is the "divide by 10" bit.  If set,
  // the units for frequency are .1 Hz, not Hz, and freq must be divided
  // by 10 to get the true frequency in Hz.  This allows for an extra digit
  // of resolution for low frequencies without the need for using floats.

}

// Returns 1 if the buzzer is currently playing, otherwise it returns 0
unsigned char ZumoBuzzer::isPlaying()
{
  return 0;
}

// Plays the specified sequence of notes.  If the play mode is 
// PLAY_AUTOMATIC, the sequence of notes will play with no further
// action required by the user.  If the play mode is PLAY_CHECK,
// the user will need to call playCheck() in the main loop to initiate
// the playing of each new note in the sequence.  The play mode can
// be changed while the sequence is playing.  
// This is modeled after the PLAY commands in GW-BASIC, with just a
// few differences.
//
// The notes are specified by the characters C, D, E, F, G, A, and
// B, and they are played by default as "quarter notes" with a
// length of 500 ms.  This corresponds to a tempo of 120
// beats/min.  Other durations can be specified by putting a number
// immediately after the note.  For example, C8 specifies C played as an
// eighth note, with half the duration of a quarter note. The special
// note R plays a rest (no sound).
//
// Various control characters alter the sound:
//   '>' plays the next note one octave higher
//
//   '<' plays the next note one octave lower
//
//   '+' or '#' after a note raises any note one half-step
//
//   '-' after a note lowers any note one half-step
//
//   '.' after a note "dots" it, increasing the length by
//       50%.  Each additional dot adds half as much as the
//       previous dot, so that "A.." is 1.75 times the length of
//       "A".
//
//   'O' followed by a number sets the octave (default: O4).
//
//   'T' followed by a number sets the tempo (default: T120).
//
//   'L' followed by a number sets the default note duration to
//       the type specified by the number: 4 for quarter notes, 8
//       for eighth notes, 16 for sixteenth notes, etc.
//       (default: L4)
//
//   'V' followed by a number from 0-15 sets the music volume.
//       (default: V15)
//
//   'MS' sets all subsequent notes to play staccato - each note is played
//       for 1/2 of its allotted time, followed by an equal period
//       of silence.
//
//   'ML' sets all subsequent notes to play legato - each note is played
//       for its full length.  This is the default setting.
//
//   '!' resets all persistent settings to their defaults.
//
// The following plays a c major scale up and back down:
//   play("L16 V8 cdefgab>cbagfedc");
//
// Here is an example from Bach:
//   play("T240 L8 a gafaeada c+adaeafa <aa<bac#ada c#adaeaf4");
void ZumoBuzzer::play(const char *notes)
{
}

void ZumoBuzzer::playFromProgramSpace(const char *notes_p)
{
}

// stop all sound playback immediately
void ZumoBuzzer::stopPlaying()
{
}

// Gets the current character, converting to lower-case and skipping
// spaces.  For any spaces, this automatically increments sequence!
static char currentCharacter()
{
}

// Returns the numerical argument specified at buzzerSequence[0] and
// increments sequence to point to the character immediately after the
// argument.
static unsigned int getNumber()
{
}

static void nextNote()
{
}

// This puts play() into a mode where instead of advancing to the
// next note in the sequence automatically, it waits until the
// function playCheck() is called. The idea is that you can
// put playCheck() in your main loop and avoid potential
// delays due to the note sequence being checked in the middle of
// a time sensitive calculation.  It is recommended that you use
// this function if you are doing anything that can't tolerate
// being interrupted for more than a few microseconds.
// Note that the play mode can be changed while a sequence is being
// played.
//
// Usage: playMode(PLAY_AUTOMATIC) makes it automatic (the
// default), playMode(PLAY_CHECK) sets it to a mode where you have
// to call playCheck().
void ZumoBuzzer::playMode(unsigned char mode)
{
}

// Checks whether it is time to start another note, and starts
// it if so.  If it is not yet time to start the next note, this method
// returns without doing anything.  Call this as often as possible 
// in your main loop to avoid delays between notes in the sequence.
//
// Returns true if it is still playing.
unsigned char ZumoBuzzer::playCheck()
{
}
