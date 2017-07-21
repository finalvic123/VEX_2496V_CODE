#include <stdlib.h>
#include <string.h>
#include "main.h"

//include guards to prevent double inclusion
#ifndef SUBSYSTEM_H //if macro isn't defined, define Subsystem class
#define SUBSYSTEM_H

/*
All subsystems on the robot share similar properties and functions,
these are defined below. While some are implemented in a generic fashion,
e.g. setAll() or setMotor(), others, like debug(), aren't because they
are implementation specific
*/
class Subsystem {
	public:
		Subsystem(const char *name, int motors[10], int revField[10],
			const int num, int sensors[10], const char id);//Construction
		void setAll(int speed); //Calls set motor for all indexes
		
		void setMotor(const int id, int speed); //Set a motor with its array position and speed.
							//Reversing is handled for you based on revField
		
		virtual void debug() = 0; //Debug information of sensors/motors
		virtual void iterateCtl() = 0;//Main operator control loop
		virtual int eStop() = 0; //Emergency stop functionality
		~Subsystem(); //Destructor for memory cleanup
	protected:
		const char *_name; //Generic string identifier 
		int _motors[10]; //Associated motor ports
		int _revField[10]; //Associated reverse values for motors, -1 or 1
		const int _num; //Number of motors/reverse values 
		int _sensors[10];//Associated sensor ports
		const char _id;//Unique unsigned byte identifier
};


#endif
