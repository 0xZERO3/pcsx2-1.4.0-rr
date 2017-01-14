#include "PrecompiledHeader.h"

#include "App.h"	// use "CoreThread"
#include "Counters.h"	// use"g_FrameCount"

#include "MovieControle.h"


//----------------------------------
// Movie FrameAdvance/stop/start
//----------------------------------
static uint stopFrameCount = false;

static bool fStop = false;
static bool fStart = false;
static bool fFrameAdvance = false;
static bool fPauseState = false;




//-----------------------------------------------
// �Q�[����CoreThread�œ����Ă���A�����Ă���Ԃ�GSFrame(wxFrame)�̏������󂯕t���Ȃ�
// (�L�[���͂̎󂯕t����CoreThread����GSFrame����2�ӏ����ݒ肳��Ă���ۂ�)
// CoreThread����~���Ă���Ԃ�wxFrame�̓��͂������d�g�݂��ۂ�
//-----------------------------------------------

bool Movie_isStop()
{
	return (fPauseState && CoreThread.IsOpen() && CoreThread.IsPaused());
}
//-----------------------------------------------
// Counters(CoreThread)���̒�~����p
//-----------------------------------------------
void Movie_StartCheck()
{
	if (fStart && CoreThread.IsOpen() && CoreThread.IsPaused()) {
		CoreThread.Resume();
		fStart = false;
		fPauseState = false;
	}
}

void Movie_StopCheck()
{
	if (fFrameAdvance) {
		if (stopFrameCount < g_FrameCount) {
			fFrameAdvance = false;
			fStop = true;
		}
	}
	if (fStop && CoreThread.IsOpen() && CoreThread.IsRunning()) {
		CoreThread.PauseSelf();	//self����Ȃ��Ǝ~�܂�Ȃ�
		stopFrameCount = g_FrameCount;
		fPauseState = true;
	}
}



//----------------------------------
// shortcut key
//----------------------------------
void Movie_FrameAdvance()
{
	fFrameAdvance = true;
	fStop = false;
	fStart = true;
}
void Movie_TogglePause()
{
	fStop = !fStop;
	if (fStop == false) {
		fStart = true;
	}
}
void Movie_Pause()
{
	fStop = true;
}
void Movie_UnPause()
{
	fStop = false;
	fStart = true;
}







