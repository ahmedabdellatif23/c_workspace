#include "stdio.h"
#include "header_file.h"
#include "stdbool.h"

#define MAX_STATES 3U
#define MAX_EVENTS 3U

/* FSM */
typedef enum
{
    isIdleState = 0,
    isLockedState,
    isUnlockedState,
} eSystemState;

typedef enum
{
    LockEvent = 0,
    UnlockEvent,
    IdleEvent
} eSystemEvent;

// typedef of function pointer
typedef eSystemState (*pfEventHandler)(void);

/* typedef of 2d array  for the states*/
typedef eSystemState (*const afEventHandler[MAX_STATES][MAX_EVENTS])(void);

/* structure of state and event with event handler */
typedef struct
{
    eSystemState eStateMachine;
    eSystemEvent eStateMachineEvent;
    pfEventHandler pfStateMachineEvnentHandler;
} sStateMachine;

/* function call to lock sys and return the ideal state */


eSystemState LockHandler(void)
{
    return isLockedState;
}
eSystemState UnlockHandler(void)
{
    return isUnlockedState;
}
eSystemState IdleHandler(void)
{
    return isIdleState;
}

int main()
{
    eSystemState eNextState = isUnlockedState;
    eSystemEvent eNewEvent = IdleEvent;
    // Table to define valid states and event of finite state machine
    static afEventHandler StateMachine =
        {
            [isIdleState] = {[LockEvent] = LockHandler},
            [isLockedState] = {[UnlockEvent] = UnlockHandler},
            [isUnlockedState] = {[IdleEvent] = IdleHandler},
        };
    // Check NULL pointer and array boundary
    if ((eNextState <= MAX_STATES) && (eNewEvent <= MAX_EVENTS) && StateMachine[eNextState][eNewEvent] != NULL)
    {
        // function call as per the state and event and return the next state of the finite state machine
        eNextState = (*StateMachine[eNextState][eNewEvent])();
    }
    else
    {
        // bool x = false;
    }
    return 0;
}