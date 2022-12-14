/*
 * Temporal One Time Passwords:
 *
 * An implementation of TOTP using the RTC to keep time
 */
#include "repeater.h"

uint8_t* _hmacKey;
uint8_t _keyLength;
uint8_t _timeZoneOffset;
uint32_t _timeStep;

// Init the library with the private key, its length and the timeStep duration
void TOTP(uint8_t* hmacKey, uint8_t keyLength, uint32_t timeStep) {
    _hmacKey = hmacKey;
    _keyLength = keyLength;
    _timeStep = timeStep;
}

void setTimezone(uint8_t timezone){
    _timeZoneOffset = timezone;
}

uint32_t TimeStruct2Timestamp(struct tm time){
    //time.tm_mon -= 1;
    //time.tm_year -= 1900;
    return mktime(&(time)) - (_timeZoneOffset * 3600) - 2208988800;
}

// Generate a code, using the timestamp provided
uint32_t getCodeFromTimestamp(uint32_t timeStamp) {
    uint32_t steps = timeStamp / _timeStep;
    return getCodeFromSteps(steps);
}

// Generate a code, using the timestamp provided
uint32_t getCodeFromTimeStruct(struct tm time) {
    return getCodeFromTimestamp(TimeStruct2Timestamp(time));
}

// Generate a code, using the number of steps provided
uint32_t getCodeFromSteps(uint32_t steps) {
    // STEP 0, map the number of steps in a 8-bytes array (counter value)
    uint8_t _byteArray[8];
    _byteArray[0] = 0x00;
    _byteArray[1] = 0x00;
    _byteArray[2] = 0x00;
    _byteArray[3] = 0x00;
    _byteArray[4] = (uint8_t)((steps >> 24) & 0xFF);
    _byteArray[5] = (uint8_t)((steps >> 16) & 0xFF);
    _byteArray[6] = (uint8_t)((steps >> 8) & 0XFF);
    _byteArray[7] = (uint8_t)((steps & 0XFF));

    // STEP 1, get the HMAC-SHA1 hash from counter and key
    initHmac(_hmacKey, _keyLength);
    writeArray(_byteArray, 8);
    uint8_t* _hash = sha1_resultHmac();

    // STEP 2, apply dynamic truncation to obtain a 4-bytes string
    uint32_t _truncatedHash = 0;
    uint8_t _offset = _hash[20 - 1] & 0xF;
    uint8_t j;
    for (j = 0; j < 4; ++j) {
        _truncatedHash <<= 8;
        _truncatedHash  |= _hash[_offset + j];
    }

    // STEP 3, compute the OTP value
    _truncatedHash &= 0x7FFFFFFF;    //Disabled
    _truncatedHash %= 1000000;

    return _truncatedHash;
}


#if	0
void totp_test(void) {
    uint8_t hmacKey[] = {0x4d, 0x79, 0x4c, 0x65, 0x67, 0x6f, 0x44, 0x6f, 0x6f, 0x72};               // Secret key
    TOTP(hmacKey, 10, 7200);                                                                        // Secret key, Key length, Timestep (7200s - 2hours)

    setTimezone(9);                                                                                 // Set timezone
    uint32_t newCode = getCodeFromTimestamp(1557414000);                                            // Timestamp Now
	///////////////// For struct tm //////////////////
    //	struct tm datetime;
    //	datetime.tm_hour = 9;
    //	datetime.tm_min = 0;
    //	datetime.tm_sec = 0;
    //	datetime.tm_mday = 13;
    //	datetime.tm_mon = 5;
    //	datetime.tm_year = 2019;
	//  uint32_t newCode = getCodeFromTimeStruct(datetime);
	///////////////////////////////////////////////////

	volatile unsigned int i;		// volatile to prevent optimization

	while(1) {
	   if (newCode == 0){          // 0 = INPUT HERE
	      P1OUT ^= 0x01;          // toggle P1.0
	   }
	   delay(500);
	}
}
#endif
