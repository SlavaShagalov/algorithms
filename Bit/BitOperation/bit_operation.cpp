#include "bit_operation.hpp"

bool getBit(uint32_t num, uint8_t index) {
    return (num >> index) & 1;
}