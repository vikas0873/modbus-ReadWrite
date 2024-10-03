#ifndef ModbusTW_h
#define ModbusTW_h

#include <ModbusMaster.h>

class ModbusTW {
  public:
    ModbusTW();
    void begin(uint8_t slaveId, HardwareSerial &serialPort);
    uint16_t readRegister(uint16_t address,bool &read_status);
    bool writeRegister(uint16_t address, uint16_t value);
  
  private:
    ModbusMaster _node PROGMEM;
};

#endif
