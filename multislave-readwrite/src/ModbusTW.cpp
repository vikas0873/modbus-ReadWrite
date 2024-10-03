#include "ModbusTW.h"

ModbusTW::ModbusTW() {}

void ModbusTW ::begin(uint8_t slaveId, HardwareSerial &serialPort)
{
  _node.begin(slaveId, serialPort);
}

uint16_t ModbusTW ::readRegister(uint16_t address,bool &read_status)
{
  uint16_t result = 0;
  uint8_t success = _node.readHoldingRegisters(address, 1);
  read_status = false;
  if (success == _node.ku8MBSuccess)
  {
    result = _node.getResponseBuffer(0);
    read_status = true;
  }
  return result;
}

bool ModbusTW ::writeRegister(uint16_t address, uint16_t value)
{
  uint8_t success = _node.writeSingleRegister(address, value);
  return (success == _node.ku8MBSuccess);
}
