CHANGELOG
=========
Build numbers are based off of the date and start date. (MMDD)

0125a
-----
- Changes to TitleState/Menu State
- Added HelpState.h (needs .cc filled in)
- Added test for keypresses
- Added static State* getState(StateType type) to State.h
- Added void setNextState(State* next) to Message.h
- Cleaned up / refactored a lot of code in TitleState.cc / MenuState.cc that was based off of the old nextState stuff (generally 1 line of code now ^.^ )

0123a
-----
- Converted from Makefile to cmake

