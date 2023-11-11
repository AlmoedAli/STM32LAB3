/*
 * normalMode.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#ifndef INC_NORMALMODE_H_
#define INC_NORMALMODE_H_

#define INIT1 0
#define STATUS1_1 1
#define STATUS1_2 2
#define STATUS1_3 3
#define STATUS1_4 4

#define INIT2 0
#define STATUS2_1 1
#define STATUS2_2 2
#define STATUS2_3 3
#define STATUS2_4 4


extern int statusTraffic1;
extern int statusTraffic2;

extern int durationLedRed;
extern int durationLedGreen;
extern int durationLedYellow;


extern int tempDurationLedRed;
extern int tempDurationLedGreen;
extern int tempDurationLedYellow;

void normalModeFunction();



#endif /* INC_NORMALMODE_H_ */
