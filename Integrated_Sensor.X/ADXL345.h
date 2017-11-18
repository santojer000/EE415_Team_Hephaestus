/* 
 * File:   ADXL345.h
 * Author: Adoney
 *
 * Created on October 30, 2017, 7:59 PM
 */

#ifndef ADXL345_H
#define	ADXL345_H

#define ADXL345_MB 0x40
#define ADXL345_READ 0x80
/* ------- Register names ------- */
#define ADXL345_DEVID           0x00
#define ADXL345_RESERVED1       0x01
#define ADXL345_THRESH_TAP      0x1D
#define ADXL345_OFSX            0x1E
#define ADXL345_OFSY            0x1F
#define ADXL345_OFSZ            0x20
#define ADXL345_DUR             0x21
#define ADXL345_LATENT          0x22
#define ADXL345_WINDOW          0x23
#define ADXL345_THRESH_ACT      0x24
#define ADXL345_THRESH_INACT    0x25
#define ADXL345_TIME_INACT      0x26
#define ADXL345_ACT_INACT_CTL   0x27
#define ADXL345_THRESH_FF       0x28
#define ADXL345_TIME_FF         0x29
#define ADXL345_TAP_AXES        0x2A
#define ADXL345_ACT_TAP_STATUS  0x2B
#define ADXL345_BW_RATE         0x2C
#define ADXL345_POWER_CTL       0x2D
#define ADXL345_INT_ENABLE      0x2E
#define ADXL345_INT_MAP         0x2F
#define ADXL345_INT_SOURCE      0x30
#define ADXL345_DATA_FORMAT     0x31
#define ADXL345_DATAX0          0x32
#define ADXL345_DATAX1          0x33
#define ADXL345_DATAY0          0x34
#define ADXL345_DATAY1          0x35
#define ADXL345_DATAZ0          0x36
#define ADXL345_DATAZ1          0x37
#define ADXL345_FIFO_CTL        0x38
#define ADXL345_FIFO_STATUS     0x39

/*----------------------------------------------------------------------
  Bit field definitions and register values
  ----------------------------------------------------------------------*/
//#define XL345_
/* register values for DEVID                                            */
/* The device ID should always read this value, The customer does not
  need to use this value but it can be samity checked to check that the
  device can communicate                                                */
 
#define ADXL345_ID              0xE5

/* Reserved soft reset value                                            */
#define ADXL345_SOFT_RESET      0x52

/* Registers THRESH_TAP through TIME_INACT just take 8 bit values
   There are no specific bit fields in these registers                  */

/* Bit values in ACT_INACT_CTL                                          */
#define ADXL345_INACT_Z_ENABLE  0x01
#define ADXL345_INACT_Z_DISABLE 0x00
#define ADXL345_INACT_Y_ENABLE  0x02
#define ADXL345_INACT_Y_DISABLE 0x00
#define ADXL345_INACT_X_ENABLE  0x04
#define ADXL345_INACT_X_DISABLE 0x00
#define ADXL345_INACT_AC        0x08
#define ADXL345_INACT_DC        0x00
#define ADXL345_ACT_Z_ENABLE    0x10
#define ADXL345_ACT_Z_DISABLE   0x00
#define ADXL345_ACT_Y_ENABLE    0x20
#define ADXL345_ACT_Y_DISABLE   0x00
#define ADXL345_ACT_X_ENABLE    0x40
#define ADXL345_ACT_X_DISABLE   0x00
#define ADXL345_ACT_AC          0x80
#define ADXL345_ACT_DC          0x00

/* Registers THRESH_FF and TIME_FF just take 8 bit values
   There are no specific bit fields in these registers
   units of THRESH_FF 1/16 gee/LSB
   units of TIME_FF 5 ms.                                               */

/* Bit values in TAP_AXES                                               */
#define ADXL345_TAP_Z_ENABLE    0x01
#define ADXL345_TAP_Z_DISABLE   0x00
#define ADXL345_TAP_Y_ENABLE    0x02
#define ADXL345_TAP_Y_DISABLE   0x00
#define ADXL345_TAP_X_ENABLE    0x04
#define ADXL345_TAP_X_DISABLE   0x00
#define ADXL345_TAP_SUPPRESS    0x08

/* Bit values in ACT_TAP_STATUS                                         */
#define ADXL345_TAP_Z_SOURCE    0x01
#define ADXL345_TAP_Y_SOURCE    0x02
#define ADXL345_TAP_X_SOURCE    0x04
#define ADXL345_STAT_ASLEEP     0x08
#define ADXL345_ACT_Z_SOURCE    0x10
#define ADXL345_ACT_Y_SOURCE    0x20
#define ADXL345_ACT_X_SOURCE    0x40

/* Bit values in BW_RATE                                                */
/* Expresed as output data rate */
#define ADXL345_RATE_3200       0x0F
#define ADXL345_RATE_1600       0x0E
#define ADXL345_RATE_800        0x0D
#define ADXL345_RATE_400        0x0C
#define ADXL345_RATE_200        0x0B
#define ADXL345_RATE_100        0x0A
#define ADXL345_RATE_50         0x09
#define ADXL345_RATE_25         0x08
#define ADXL345_RATE_12_5       0x07
#define ADXL345_RATE_6_25       0x06
#define ADXL345_RATE_3_125      0x05
#define ADXL345_RATE_1_563      0x04
#define ADXL345_RATE__782       0x03
#define ADXL345_RATE__39        0x02
#define ADXL345_RATE__195       0x01
#define ADXL345_RATE__098       0x00

/* Expresed as output bandwidth */
/* Use either the bandwidth or rate code,
   which ever is more appropraite for your application */
#define ADXL345_BW_1600         0x0F
#define ADXL345_BW_800          0x0E
#define ADXL345_BW_400          0x0D
#define ADXL345_BW_200          0x0C
#define ADXL345_BW_100          0x0B
#define ADXL345_BW_50           0x0A
#define ADXL345_BW_25           0x09
#define ADXL345_BW_12_5         0x08
#define ADXL345_BW_6_25         0x07
#define ADXL345_BW_3_125        0x06
#define ADXL345_BW_1_563        0x05
#define ADXL345_BW__782         0x04
#define ADXL345_BW__39          0x03
#define ADXL345_BW__195         0x02
#define ADXL345_BW__098         0x01
#define ADXL345_BW__048         0x00

#define ADXL345_LOW_POWER       0x08
#define ADXL345_LOW_NOISE       0x00
/* Bit values in POWER_CTL                                              */
#define ADXL345_WAKEUP_8HZ           0x00
#define ADXL345_WAKEUP_4HZ           0x01
#define ADXL345_WAKEUP_2HZ           0x02
#define ADXL345_WAKEUP_1HZ           0x03
#define ADXL345_SLEEP                0x04
#define ADXL345_MEASURE              0x08
#define ADXL345_STANDBY              0x00
#define ADXL345_AUTO_SLEEP           0x10
#define ADXL345_ACT_INACT_SERIAL     0x20
#define ADXL345_ACT_INACT_CONCURRENT 0x00

/* Bit values in INT_ENABLE, INT_MAP, and INT_SOURCE are identical
   use these bit values to read or write any of these registers.        */
#define ADXL345_OVERRUN              0x01
#define ADXL345_WATERMARK            0x02
#define ADXL345_FREEFALL             0x04
#define ADXL345_INACTIVITY           0x08
#define ADXL345_ACTIVITY             0x10
#define ADXL345_DOUBLETAP            0x20
#define ADXL345_SINGLETAP            0x40
#define ADXL345_DATAREADY            0x80

/* Bit values in DATA_FORMAT                                            */

/* Register values read in DATAX0 through DATAZ1 are dependant on the 
   value specified in data format.  Customer code will need to interpret
   the data as desired.                                                 */
#define ADXL345_RANGE_2G             0x00
#define ADXL345_RANGE_4G             0x01
#define ADXL345_RANGE_8G             0x02
#define ADXL345_RANGE_16G            0x03
#define ADXL345_DATA_JUST_RIGHT      0x00
#define ADXL345_DATA_JUST_LEFT       0x04
#define ADXL345_10BIT                0x00
#define ADXL345_FULL_RESOLUTION      0x08
#define ADXL345_INT_LOW              0x20
#define ADXL345_INT_HIGH             0x00
#define ADXL345_SPI3WIRE             0x40
#define ADXL345_SPI4WIRE             0x00
#define ADXL345_SELFTEST             0x80

/* Bit values in FIFO_CTL                                               */
/* The low bits are a value 0-31 used for the watermark or the number
   of pre-trigger samples when in triggered mode                        */
#define ADXL345_TRIGGER_INT1         0x00
#define ADXL345_TRIGGER_INT2         0x20
#define ADXL345_FIFO_MODE_BYPASS     0x00
#define ADXL345_FIFO_RESET           0x00
#define ADXL345_FIFO_MODE_FIFO       0x40
#define ADXL345_FIFO_MODE_STREAM     0x80
#define ADXL345_FIFO_MODE_TRIGGER    0xC0

/* Bit values in FIFO_STATUS                                            */
/* The low bits are a value 0-32 showing the number of entries
   currently available in the fifo buffer                               */

#define ADXL345_FIFO_TRIGGERED       0x80

#endif	/* ADXL345_H */

